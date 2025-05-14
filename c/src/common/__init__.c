#include "public_data.h"
#include "cmd_fac.h"
#include "device_fac.h"
#include "mqtt_conf.h"
#include "face_detection.h"

void __init__()
{

    //��ʼ��python������
    py_init();
    
    //��ʼ��wiringPi��
	wiringPiSetup();

    //��ʼ��ȫ���豸
    device_init();

    //��ʼ��ȫ��ָ��
    cmd_init();

    //��ʼ��MQTTQ
    mqtt_init();

}

//��ʼ��ȫ���豸
void device_init(){
	PutLEDInLink();
	PutDhtInLink();
	PutBeeperInLink();
	PutPressureInLink();
	PutSGInLink();
    device *p = device_phead->next;
	while(p != NULL){
		p->init();
		printf("main:find '%s' in link!\n",p->device_name);
		p = p->next;
	}
}

//��ʼ��ȫ��ָ��
void cmd_init(){
    PutFireInLink();
}