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
    int     beeper;             //蜂鸣器
    int     humidity;           //湿度
    float   temperature;        //温度
    float   pressure;           //压力
    float   gas;                //有害气体
    int     face_detection;     //人脸检测
    
    bool    led_green;          //工作灯
    bool    led_yellow;         //警报灯
    bool    led_red;            //错误灯
    
    bool    in_car;             //车内有无人员
    bool    fire_ctl;           //火灾报警
    bool    window;             //车窗开关
    bool    hand_ctl;           //手动控制
    
}attribute;

#define SHM_NAME "/attr_shm"
#define SEM_NAME "/attr_sem"
#define SHM_SIZE sizeof(attribute)

extern attribute *attribute_ptr;
extern sem_t     *sem;

void __init__();
void shm_init();

#endif