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


void mqtt_init(data *datas);
void mqtt_publish(void *obj);
void mqtt_subscribe_callback (struct mosquitto *mosquit, void *obj, int mid, int qos_count, const int *granted_qos);
void mqtt_recv_message_callback(struct mosquitto *mosquit,void *obj, const struct mosquitto_message *msg);
void mqtt_connect_callback(struct mosquitto *mosquit, void *obj, int rc);
void mqtt_disconnect_callback( struct mosquitto *mosq, void *obj, int rc);
int mqtt_conf_parse(char *path_ini, mosquitto_ctx_t *mosquitto);

#endif
