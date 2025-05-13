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
    int     beeper;             //蜂鸣器
    int     humidity;           //湿度
    float   temperature;        //温度
    float   pressure;           //压力
    bool    face_detection;     //人脸检测
    bool    led_green;          //工作灯
    bool    led_yellow;         //警报灯
    bool    led_red;            //错误灯
    bool    gas;                //有害气体
    bool    in_car;             //车内有无人员
    bool    fire_ctl;           //火灾报警
    bool    window;             //车窗开关
    bool    hand_ctl;           //手动控制
    
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