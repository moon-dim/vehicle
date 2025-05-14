#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <mosquitto.h>
#include <cJSON.h>
#include <iniparser.h>
#include <dictionary.h>
#include "mqtt_conf.h"
#include "public_data.h"

// extern struct mosquitto     *mosquit_ptr;
// extern mosquitto_inf        *mosquit_inf_ptr;
// extern attribute            *attribute_ptr;


void mqtt_init(){

    int rv = 0;
    int mid = 0;
	//读取MQTT配置文件
	rv = mqtt_conf_parse();
    if (rv < 0)
    {
        printf("mqtt conf parse success!\n");
        return;
    }

	//初始化MQTT
    rv = mosquitto_lib_init();
    if (rv)
    {
        printf("mosquitto lib init failure:%s,rv=%d\n", strerror(errno), rv);
        zlog_error(mosquit_inf_ptr->w_zc, "mosquitto lib init failure:%s", strerror(errno));
        goto cleanup;
    }
    printf("mosquitto lib init success!\n");

	mosquit_ptr = mosquitto_new(mosquit_inf_ptr->clientid, true, NULL); //创建客户端ID
    if (!mosquit_ptr)
    {
        printf("mosquitto new create failure:%s\n", strerror(errno));
        //zlog_error(mosquit_inf_ptr->w_zc, "mosquitto new create failure:%s", strerror(errno));
        goto cleanup;
    }
    else
        printf("moasquitto new create success!\n");
    //       zlog_info(mosquit_inf_ptr->w_zc,"create database table success!");

    mosquitto_connect_callback_set(mosquit_ptr, mqtt_connect_callback);       //当连接服务器成功，执行回调函数，数据发布，采用短连接方式
    mosquitto_disconnect_callback_set(mosquit_ptr, mqtt_disconnect_callback); //当与服务器断连，执行回调函数，查看故障
    mosquitto_subscribe_callback_set(mosquit_ptr, mqtt_subscribe_callback);    //打印订阅提示信息，用于调试
    mosquitto_message_callback_set(mosquit_ptr, mqtt_recv_message_callback);   //用于处理接收的消息
    
	rv = mosquitto_username_pw_set(mosquit_ptr, mosquit_inf_ptr->username, mosquit_inf_ptr->passwd);
    if (rv != MOSQ_ERR_SUCCESS)
    {
        printf("mosquitto username and passwd failure:%s\n", strerror(errno));
        //zlog_error(mosquit_inf_ptr->w_zc, "mosquitto username and passwd failure:%s", strerror(errno));
        goto cleanup;
		
    }
    printf("mosquitto username and passwd set success!\n");
    //    zlog_info(mosquit_inf_ptr->w_zc,"mosquitto username and passwd success!");

    //MQTT连接
	rv = mosquitto_connect(mosquit_ptr, mosquit_inf_ptr->host, mosquit_inf_ptr->port, mosquit_inf_ptr->keepalive);
	if (rv != MOSQ_ERR_SUCCESS)
	{
		printf("mosquitto connect failure:%s", strerror(errno));
		//zlog_error(mosquit_inf_ptr->w_zc, "mosquitto connect failure:%s", strerror(errno));
	}

	rv = mosquitto_loop_start(mosquit_ptr);
	if(rv != MOSQ_ERR_SUCCESS)
    {
        //zlog_error("mosquitto loop error!");
		goto cleanup;
    }
    printf("mosquitto loop start success!\n");
    return;
cleanup:
	mosquitto_destroy(mosquit_ptr);
	mosquitto_lib_cleanup();
}

void mqtt_publish()
{
    int             mid;
    int             rv;
    char            *json_string;
    
    if(!mosquit_inf_ptr->connection)return;
    /*******************创建json对象*********************/
    cJSON *value = cJSON_CreateObject();
    cJSON *items = cJSON_CreateObject();

    /*****************************向json对象中添加一对元素,object为json对象*******************************************/
    cJSON_AddItemToObject(value, "version", cJSON_CreateString(mosquit_inf_ptr->version));
    cJSON_AddItemToObject(value, "method", cJSON_CreateString(mosquit_inf_ptr->method));
    cJSON_AddItemToObject(value, "id", cJSON_CreateString(mosquit_inf_ptr->id));
    cJSON_AddItemToObject(value, "params", items);
    cJSON_AddItemToObject(items, TEMPERATRUE_NAME, cJSON_CreateNumber(attribute_ptr->temperature));
    cJSON_AddItemToObject(items, HUMIDITY_NAME, cJSON_CreateNumber(attribute_ptr->humidity));
    cJSON_AddItemToObject(items, GAS_CONTROL_NAME, cJSON_CreateNumber(attribute_ptr->gas));
    cJSON_AddItemToObject(items, FACE_DETECTION_NAME, cJSON_CreateNumber(attribute_ptr->face_detection));
    cJSON_AddItemToObject(items, BEEPER_NAME, cJSON_CreateNumber(attribute_ptr->beeper));
    cJSON_AddItemToObject(items, LED_GREEN_NAME, cJSON_CreateNumber(attribute_ptr->led_green));
    cJSON_AddItemToObject(items, LED_RED_NAME, cJSON_CreateNumber(attribute_ptr->led_red));
    cJSON_AddItemToObject(items, LED_YELLOW_NAME, cJSON_CreateNumber(attribute_ptr->led_yellow));
    cJSON_AddItemToObject(items, FIRE_CONTROL_NAME, cJSON_CreateNumber(attribute_ptr->fire_ctl));
    cJSON_AddItemToObject(items, IN_CAR_NAME, cJSON_CreateNumber(attribute_ptr->in_car));


    /****将一个cJSON结构体代表的json对象转换为一个json格式的字符串****/
    json_string = cJSON_Print(value);
    //printf("%s\n", json_string);

    /**************************发布数据*****************************/
    rv = mosquitto_publish(mosquit_ptr, &mid, mosquit_inf_ptr->pub_topic, strlen(json_string) + 1, json_string, mosquit_inf_ptr->qos, 0);
    if (rv != MOSQ_ERR_SUCCESS)
    {
        printf("publish error:%s\n", strerror(errno));
        //zlog_error(mosquit_inf_ptr->w_zc, "publish error:%s\n", strerror(errno));
        return;
    }
    printf("punlish success topic:%s\n", mosquit_inf_ptr->pub_topic);
    //    //zlog_info(mosquit_inf_ptr->w_zc,"punlish success topic:%s\n",mosquit_inf_ptr->pub_topic);

    // mosquitto_disconnect(mosquit);
}

void mqtt_subscribe_callback(struct mosquitto *mosqut, void *obj, int mid, int qos_count, const int *granted_qos)
{
    printf("subscribe topic success:%s\n", mosquit_inf_ptr->sub_topic);
}

void mqtt_recv_message_callback(struct mosquitto *mosquit_ptr, void *obj, const struct mosquitto_message *msg)
{
    cJSON           *value;
    cJSON           *ident_value;
    char            *cjson_data;
    char            *total_data;

    strncpy(mosquit_inf_ptr->recv_message, (char *)msg->payload, sizeof(mosquit_inf_ptr->recv_message));
    printf("recv_message: %s\n", mosquit_inf_ptr->recv_message);

    if (strcmp(msg->payload, "quit") == 0)mosquitto_disconnect(mosquit_ptr);

    //把该字符串数据转换成JSON对象
    cJSON *root = cJSON_Parse(mosquit_inf_ptr->recv_message);
    if (root == NULL)
    {
        printf("parse error\n");
    }
    /*****************************params获取*********************************/
    //根据key值去获取对应的value
    value = cJSON_GetObjectItem(root, "params");
    if (value == NULL)
    {
        //printf("GetObjec error\n");
        return;
    }
    //把数据转成 字符串输出
    //printf("params:%s\n", cJSON_Print(value));

    ident_value = cJSON_GetObjectItem(value, GAS_CONTROL_NAME);
    total_data = cJSON_Print(ident_value);
    attribute_ptr->gas = atoi(total_data);

    ident_value = cJSON_GetObjectItem(value, FIRE_CONTROL_NAME);
    total_data = cJSON_Print(ident_value);
    attribute_ptr->fire_ctl = atoi(total_data);

}

void mqtt_connect_callback(struct mosquitto *mosquit_ptr, void *obj, int rc)
{
    printf("mosquitto connect success!\n");

    int mid;
    int rv;
    mosquit_inf_ptr->connection = true;

    //MQTT订阅
    rv = mosquitto_subscribe(mosquit_ptr, &mid, mosquit_inf_ptr->sub_topic, mosquit_inf_ptr->qos);
    if (rv != MOSQ_ERR_SUCCESS)
    {
        printf("Set the topic error:%s\n", strerror(errno));
        //zlog_error(mosquit_inf_ptr->w_zc, "Set the topic error:%s\n", strerror(errno));
        return;
    }
    //zlog_info(mosquit_inf_ptr->w_zc, "mosquitto subscribe topic success:%s", mosquit_inf_ptr->sub_topic);
}

void mqtt_disconnect_callback(struct mosquitto *mosq, void *obj, int rc)
{
    printf("mosquitto disconnect!\n");
    mosquit_inf_ptr->connection = false;
}

/********************************本函数将用于把配置文件的参数传递到结构体里面**************************************/
int mqtt_conf_parse()
{
    dictionary *ini = NULL;
    const char *host;
    int         port;
    const char *clientid;
    const char *username;
    const char *passwd;

    const char *pub_topic;
    const char *sub_topic;
    int         qos;
    int         keepalive;

    const char *method;
    const char *id;
    const char *version;

    if (!mosquit_inf_ptr)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    ini = iniparser_load(MQTT_INI_PATH);
    if (ini == NULL)
    {
        printf("inipar failure\n");
        return -2;
    }
    host = iniparser_getstring(ini, "mqtt_connection:host", NULL);
    port = iniparser_getint(ini, "mqtt_connection:port", -1);

    username = iniparser_getstring(ini, "mqtt_connection:username", NULL);
    passwd = iniparser_getstring(ini, "mqtt_connection:passwd", NULL);

    clientid = iniparser_getstring(ini, "mqtt_connection:clientid", NULL);

    pub_topic = iniparser_getstring(ini, "topic:pub_topic", NULL);
    sub_topic = iniparser_getstring(ini, "topic:sub_topic", NULL);

    qos = iniparser_getint(ini, "mqtt_common:qos", -1);
    keepalive = iniparser_getint(ini, "mqtt_common:heartbeat", -1);

    method = iniparser_getstring(ini, "mqtt_json:method", NULL);
    id = iniparser_getstring(ini, "mqtt_json:id", NULL);
    version = iniparser_getstring(ini, "mqtt_json:version", NULL);

    strncpy(mosquit_inf_ptr->host, host, sizeof(mosquit_inf_ptr->host));

    mosquit_inf_ptr->port = port;
    strncpy(mosquit_inf_ptr->username, username, sizeof(mosquit_inf_ptr->username));
    strncpy(mosquit_inf_ptr->passwd, passwd, sizeof(mosquit_inf_ptr->passwd));

    strncpy(mosquit_inf_ptr->clientid, clientid, sizeof(mosquit_inf_ptr->clientid));

    strncpy(mosquit_inf_ptr->pub_topic, pub_topic, sizeof(mosquit_inf_ptr->pub_topic));
    strncpy(mosquit_inf_ptr->sub_topic, sub_topic, sizeof(mosquit_inf_ptr->sub_topic));

    mosquit_inf_ptr->qos = qos;
    mosquit_inf_ptr->keepalive = keepalive;

    strncpy(mosquit_inf_ptr->method, method, sizeof(mosquit_inf_ptr->method));
    strncpy(mosquit_inf_ptr->id, id, sizeof(mosquit_inf_ptr->id));
    strncpy(mosquit_inf_ptr->version, version, sizeof(mosquit_inf_ptr->version));

    printf("host:%s,port:%d\n", mosquit_inf_ptr->host, mosquit_inf_ptr->port);
    printf("username:%s,passwd:%s\n", mosquit_inf_ptr->username, mosquit_inf_ptr->passwd);
    printf("\n");
    printf("clientid:%s\n", mosquit_inf_ptr->clientid);
    printf("\n");
    printf("pub_topic:%s,sub_topic:%s\n", mosquit_inf_ptr->pub_topic, mosquit_inf_ptr->sub_topic);
    printf("\n");
    printf("qos:%d,keepalive:%d\n", mosquit_inf_ptr->qos, mosquit_inf_ptr->keepalive);
    printf("\n");
    printf("method:%s,id:%s\n", mosquit_inf_ptr->method, mosquit_inf_ptr->id);
    printf("\n");
    iniparser_freedict(ini);

    return 0;
}
