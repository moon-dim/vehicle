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
    int     beeper;             //������
    int     humidity;           //ʪ��
    float   temperature;        //�¶�
    float   pressure;           //ѹ��
    int     face_detection;     //�������
    bool    led_green;          //������
    bool    led_yellow;         //������
    bool    led_red;            //�����
    bool    gas;                //�к�����
    bool    in_car;             //����������Ա
    bool    fire_ctl;           //���ֱ���
    bool    window;             //��������
    bool    hand_ctl;           //�ֶ�����
    
}attribute;

extern attribute            *attribute_ptr;

void public_data_init();
void __init__();

#endif