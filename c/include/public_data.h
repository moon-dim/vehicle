/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-13 14:14:48
 * @LastEditTime : 2025-05-13 14:23:24
 * @FilePath     : \vehicle\c\include\common\data.h
 * @Description  : 
 */
#ifndef __PUBLIC_DATA_H__
#define __PUBLIC_DATA_H__

#include <stdbool.h>

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

extern attribute            *attribute_ptr;

void __init__();

#endif