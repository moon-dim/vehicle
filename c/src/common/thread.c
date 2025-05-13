#include "thread.h"
#include "public_data.h"
#include "cmd_fac.h"
#include "device_fac.h"
#include "find_link.h"
#include "mqtt_conf.h"

void *thread_get_data()
{
	device 		*device_pfind = NULL;
	float 		*dht_data = (float*)malloc(sizeof(float)<<1);

	while(true)
	{
		// //读取LED红灯状态
		device_pfind = findDEVICEinLink(LED_RED_NAME);
		attribute_ptr->led_red = *(int*)device_pfind->read_status();

		//读取LED绿灯状态
		device_pfind = findDEVICEinLink(LED_GREEN_NAME);
		attribute_ptr->led_green = *(int*)device_pfind->read_status();

		//读取LED黄灯状态
		device_pfind = findDEVICEinLink(LED_YELLOW_NAME);
		attribute_ptr->led_yellow = *(int*)device_pfind->read_status();

		//读取蜂鸣器状态
		device_pfind = findDEVICEinLink(BEEPER_NAME);
		attribute_ptr->beeper = *(int*)device_pfind->read_status();

		//读取压力传感器数据
		device_pfind = findDEVICEinLink(PRESSURE_NAME);
		attribute_ptr->pressure = *(float*)device_pfind->read_status();
		printf("%.2f\n",attribute_ptr->pressure);

		//读取温湿度数据
		device_pfind = findDEVICEinLink(DHT_NAME);
		dht_data = (float*)device_pfind->read_status();
		attribute_ptr->temperature = dht_data[0];
		attribute_ptr->humidity = (int)dht_data[1];

		//读取舵机状态
		device_pfind = findDEVICEinLink(SG_NAME);
		attribute_ptr->window = *(int*)device_pfind->read_status();

		//MQTT发布
		mqtt_publish();
		sleep(2);
	}

	pthread_exit(NULL);
}

void *thread_cmd_ctl()
{
	device 		*device_pfind = NULL;
	cmd			*cmd_pfind = NULL;

	//开始工作
	device_pfind = findDEVICEinLink(LED_GREEN_NAME);
	device_pfind->open();
	while(true){
		//火灾
		cmd_pfind = findCMDinLink(FIRE_CONTROL_NAME);
		cmd_pfind->cmd_handler();
		sleep(1);
	}
	//结束工作
	device_pfind = findDEVICEinLink(LED_GREEN_NAME);
	device_pfind->close();
	pthread_exit(NULL);
}

