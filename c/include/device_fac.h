#ifndef __DEVICEFAC_H__
#define __DEVICEFAC_H__
 
#include <wiringPi.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <softPwm.h>
#include <stdbool.h>

#define DHT_GPIO 			1
#define PRESSURE_GPIO 		2
#define PRESSURE_SCK 		3
#define BEEPER_GPIO 		4
#define HC_GPIO				6
#define SG_GPIO				7
#define MQ_AO_GPIO			21
#define MQ_DO_GPIO			22
#define LED_GREEN_GPIO 		27
#define LED_YELLOW_GPIO 	28
#define LED_RED_GPIO 		29

#define DHT_NAME 			"dht11"
#define PRESSURE_NAME		"pressure"
#define BEEPER_NAME	 		"beeper"
#define HC_NAME		 		"infrared"
#define	SG_NAME				"steering_engine"
#define MQ_NAME				"mq135"
#define LED_GREEN_NAME 	 	"led_green"
#define LED_YELLOW_NAME	 	"led_yellow"
#define LED_RED_NAME 	 	"led_red"

#define FIRE_CONTROL_NAME 	"fire_ctl"
#define GAS_CONTROL_NAME	"gas"
#define INF_CONTROL_NAME	"inf_ctl"
#define	IN_CAR_NAME			"in_car"

#define TEMPERATRUE_NAME	"temperature"
#define HUMIDITY_NAME		"humidity"


typedef struct device
{
	char device_name[64]; 	//设备名称
	int status;
	int (*init)(); 			//初始化函数
	int (*open)(); 			//打开设备的函数
	int (*close)(); 		//关闭设备的函数
	void*(*read_status)(); 	//查看设备状态的函数
	
	struct device *next;
}device;
 
 
device* PutLEDInLink(device *head);
device* PutDhtInLink(device *head);
device* PutBeeperInLink(device *head);
device* PutPressureInLink(device *head);
device* PutHCInLink(device *head);
device* putCameraInLink(device *head);
device* PutSGInLink(device *head);

#endif