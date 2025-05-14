#include "public_data.h"
#include "cmd_fac.h"
#include "device_fac.h"
#include "mqtt_conf.h"
#include "face_detection.h"

void __init__()
{

    //初始化python解释器
    py_init();
    
    //初始化wiringPi库
	wiringPiSetup();

    //初始化全部设备
    device_init();

    //初始化全部指令
    cmd_init();

    //初始化MQTTQ
    mqtt_init();

}

//初始化全部设备
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

//初始化全部指令
void cmd_init(){
    PutFireInLink();
}