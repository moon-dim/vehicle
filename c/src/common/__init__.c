#include "public_data.h"
#include "cmd_fac.h"
#include "device_fac.h"
#include "mqtt_conf.h"
#include "face_detection.h"

struct mosquitto     *mosquit_ptr        = NULL;
mosquitto_inf        *mosquit_inf_ptr    = NULL;
attribute            *attribute_ptr      = NULL;
cmd	                *cmd_phead          = NULL;
device	            *device_phead       = NULL;

void __init__()
{
    //��ʼ��ȫ�ֱ���
    mosquit_inf_ptr    = (mosquitto_inf*)malloc(sizeof(mosquitto_inf));
    attribute_ptr      = (attribute*)malloc(sizeof(attribute));
    cmd_phead          = (cmd*)malloc(sizeof(cmd));
    device_phead       = (device*)malloc(sizeof(device));

    //��ʼ��wiringPi��
	wiringPiSetup();

    //��ʼ��ȫ���豸
    device_init();

    //��ʼ��ȫ��ָ��
    cmd_init();

    //��ʼ��MQTTQ
    mqtt_init();

    //��ʼ��python������
    py_init();
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