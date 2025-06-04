/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-06-03 21:52:31
 * @LastEditTime : 2025-06-03 22:53:25
 * @FilePath     : \vehicle\c\include\device_fac.h
 * @Description  : 
 */
#ifndef __DEVICEFAC_H__
#define __DEVICEFAC_H__
 
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <softPwm.h>
#include <stdbool.h>

#define DHT_GPIO 			1
#define PRESSURE_GPIO 		4
#define PRESSURE_SCK 		5
#define BEEPER_GPIO 		22
#define SG_GPIO				29
#define LED_GREEN_GPIO 		21
#define LED_YELLOW_GPIO 	23
#define LED_RED_GPIO 		25

#define DHT_NAME 			"dht11"
#define PRESSURE_NAME		"pressure"
#define BEEPER_NAME	 		"beeper"
#define	SG_NAME				"window"
#define MQ_NAME				"gas"
#define LED_GREEN_NAME 	 	"led_green"
#define LED_YELLOW_NAME	 	"led_yellow"
#define LED_RED_NAME 	 	"led_red"

#define	IN_CAR_NAME			"in_car"
#define TEMPERATRUE_NAME	"temperature"
#define HUMIDITY_NAME		"humidity"
#define FACE_DETECTION_NAME "face_detection"

#define PCF8591_ADDRESS 0x48
#define PCF8591_AIN0 0
#define VOLTAGE_REF 5


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

extern device	*device_phead;

void PutLEDInLink();
void PutDhtInLink();
void PutBeeperInLink();
void PutPressureInLink();
void putCameraInLink();
void PutSGInLink();
void PutMQInLink();

void device_init();

#endif