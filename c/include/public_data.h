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
    int     face_detection;     //�������
    
    float   temperature;        //�¶�
    float   humidity;           //ʪ��
    float   pressure;           //ѹ��
    float   gas;                //�к�����
    bool    beeper;             //������
    
    bool    led_green;          //������
    bool    led_yellow;         //������
    bool    led_red;            //�����
    
    bool    in_car;             //����������Ա
    bool    hot_ctl;            //���±���
    bool    gas_ctl;            //�к����屨��
    bool    window;             //��������
    bool    hand_ctl;           //�ֶ�����

    float   temperature_threshold;  //�¶���ֵ
    float   humidity_threshold;     //ʪ����ֵ
    float   gas_threshold;          //�к�����Ũ����ֵ 
    
}attribute;

#define SHM_NAME "/attr_shm"
#define SEM_NAME "/attr_sem"
#define SHM_SIZE sizeof(attribute)

extern attribute *attribute_ptr;
extern sem_t     *sem;

void __init__();
void shm_init();

#endif