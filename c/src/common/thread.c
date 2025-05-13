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
		// //��ȡLED���״̬
		device_pfind = findDEVICEinLink(LED_RED_NAME);
		attribute_ptr->led_red = *(int*)device_pfind->read_status();

		//��ȡLED�̵�״̬
		device_pfind = findDEVICEinLink(LED_GREEN_NAME);
		attribute_ptr->led_green = *(int*)device_pfind->read_status();

		//��ȡLED�Ƶ�״̬
		device_pfind = findDEVICEinLink(LED_YELLOW_NAME);
		attribute_ptr->led_yellow = *(int*)device_pfind->read_status();

		//��ȡ������״̬
		device_pfind = findDEVICEinLink(BEEPER_NAME);
		attribute_ptr->beeper = *(int*)device_pfind->read_status();

		//��ȡѹ������������
		device_pfind = findDEVICEinLink(PRESSURE_NAME);
		attribute_ptr->pressure = *(float*)device_pfind->read_status();
		printf("%.2f\n",attribute_ptr->pressure);

		//��ȡ��ʪ������
		device_pfind = findDEVICEinLink(DHT_NAME);
		dht_data = (float*)device_pfind->read_status();
		attribute_ptr->temperature = dht_data[0];
		attribute_ptr->humidity = (int)dht_data[1];

		//��ȡ���״̬
		device_pfind = findDEVICEinLink(SG_NAME);
		attribute_ptr->window = *(int*)device_pfind->read_status();

		//MQTT����
		mqtt_publish();
		sleep(2);
	}

	pthread_exit(NULL);
}

void *thread_cmd_ctl()
{
	device 		*device_pfind = NULL;
	cmd			*cmd_pfind = NULL;

	//��ʼ����
	device_pfind = findDEVICEinLink(LED_GREEN_NAME);
	device_pfind->open();
	while(true){
		//����
		cmd_pfind = findCMDinLink(FIRE_CONTROL_NAME);
		cmd_pfind->cmd_handler();
		sleep(1);
	}
	//��������
	device_pfind = findDEVICEinLink(LED_GREEN_NAME);
	device_pfind->close();
	pthread_exit(NULL);
}

