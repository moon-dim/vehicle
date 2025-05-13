/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-13 14:14:48
 * @LastEditTime : 2025-05-13 14:23:24
 * @FilePath     : \vehicle\c\include\common\data.h
 * @Description  : 
 */
#ifndef __PUBLIC_DATA_H__
#define __PUBLIC_DATA_H__

#include <mosquitto.h>

#include "cmd_fac.h"
#include "device_fac.h"

typedef struct mosquitto_inf
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

}mosquitto_inf;

typedef struct attribute{
    int     beeper;             //������
    int     humidity;           //ʪ��
    float   temperature;        //�¶�
    float   pressure;           //ѹ��
    bool    face_detection;     //�������
    bool    led_green;          //������
    bool    led_yellow;         //������
    bool    led_red;            //�����
    bool    gas;                //�к�����
    bool    in_car;             //����������Ա
    bool    fire_ctl;           //���ֱ���
    bool    window;             //��������
    bool    hand_ctl;           //�ֶ�����
    
}attribute;

// typedef struct data{
//     attribute        *attributes;
//     mosquitto_ctx_t  *mqtt;
//     struct mosquitto *mosquit;
//     device           *device_phead;
//     cmd              *cmd_phead;
// }data;

extern struct mosquitto     *mosquit_ptr;
extern mosquitto_inf        *mosquit_inf_ptr;
extern attribute            *attribute_ptr;

#endif