#ifndef __PUBLIC_DATA_H__
#define __PUBLIC_DATA_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>

typedef struct attribute{
    int     face_detection;     //人脸检测
    
    float   temperature;        //温度
    float   humidity;           //湿度
    float   pressure;           //压力
    float   gas;                //有害气体
    bool    beeper;             //蜂鸣器
    
    bool    led_green;          //工作灯
    bool    led_yellow;         //警报灯
    bool    led_red;            //错误灯
    
    bool    in_car;             //车内有无人员
    bool    hot_ctl;            //高温报警
    bool    gas_ctl;            //有害气体报警
    bool    window;             //车窗开关
    bool    hand_ctl;           //手动控制

    float   temperature_threshold;  //温度阈值
    float   humidity_threshold;     //湿度阈值
    float   gas_threshold;          //有害气体浓度阈值 
    
}attribute;

#define SHM_NAME "/attr_shm"
#define SEM_NAME "/attr_sem"
#define SHM_SIZE sizeof(attribute)

extern attribute *attribute_ptr;
extern sem_t     *sem;

void __init__();
void shm_init();

#endif