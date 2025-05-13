#ifndef _MQTT_CONF_H_
#define _MQTT_CONF_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <libgen.h>
#include <unistd.h>
#include <errno.h>
#include <mosquitto.h>
#include <zlog.h>
#include "device_fac.h"
#include "cmd_fac.h"

#define buffsize 1024
#define MQTT_INI_PATH "../etc/mqtt_conf.ini"   	 	//mqtt配置文件的路径

typedef struct mosquitto_ctx_t
{
    char    host[128];
    int     port;
    char    clientid[128];
    char    username[128];
    char    passwd[128];
    
    char    pub_topic[128];
    char    sub_topic[128];
    int     qos;
    int     keepalive;

    char    method[128];
    char    id[128];
    char    version[128];
    
    char    recv_message[1024];

    bool    connection;

    zlog_category_t  *w_zc;

}mosquitto_ctx_t;

typedef struct attribute{
    int     beeper;         //蜂鸣器
    int     infrared;       //人体红外
    int     humidity;       //湿度
    float   temperature;    //温度
    float   pressure;       //压力
    bool    led_green;      //工作灯
    bool    led_yellow;     //警惕灯
    bool    led_red;        //警报灯
    bool    gas;           //有害气体
    bool    in_car;        //车内有无人员
    bool    fire_ctl;      //火灾报警
    bool    window;        //车窗开关
    bool    hand_ctl;
    
}attribute;

typedef struct data{
    attribute        *attributes;
    mosquitto_ctx_t  *mqtt;
    struct mosquitto *mosquit;
    device           *device_phead;
    cmd              *cmd_phead;
}data;

void mqtt_init(data *datas);
void mqtt_publish(void *obj);
void mqtt_subscribe_callback (struct mosquitto *mosquit, void *obj, int mid, int qos_count, const int *granted_qos);
void mqtt_recv_message_callback(struct mosquitto *mosquit,void *obj, const struct mosquitto_message *msg);
void mqtt_connect_callback(struct mosquitto *mosquit, void *obj, int rc);
void mqtt_disconnect_callback( struct mosquitto *mosq, void *obj, int rc);
int mqtt_conf_parse(char *path_ini, mosquitto_ctx_t *mosquitto);

#endif
