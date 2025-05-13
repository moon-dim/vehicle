#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <libgen.h>
#include <getopt.h>
#include <mosquitto.h>
#include <zlog.h>
#include "mqtt_conf.h"
#include "find_link.h"

#define FIRE_TMP 30 						//���ֱ����¶�

#define sql_path "../database/data.db" 	 	//���ݿ��ȡ�ĵ�·��
#define zlog_path "../etc/zlog.conf"  	 	//��־ϵͳ�ı���·��

void *thread_cmd_ctl(void *thread_argv);	//�߳�1��ָ��ִ��
void *thread_get_data(void *thread_argv);	//�߳�2�����ݲɼ�
data *data_init();							//�����ݽṹ���ʼ��
void cleanup(void *thread_argv);

int rv = -1; 	//����rv����������,�ñ������������ļ�����
int rc = -1; 	//����rc����������,�ñ���������־ϵͳ
//pthread_mutex_t mutex;
device			*device_phead = NULL;
cmd 			*cmd_phead    = NULL;

/*
void *thread4(void *arg) //���ֱ����߳�
{
	struct cmd *cmd_pfind_th4 = NULL;
	struct device *device_pfind_th4 = NULL;
 
	while(1){
		//delay(1000);//����delay��Ϊ�̼߳䱾�����Ǿ�����ϵ������һ���ж���̣߳����²�delayҲ����ܿ��ٵ�����
		cmd_pfind_th4 = findCMDinLink("fire",cmd_phead);
		if(cmd_pfind_th4!=NULL){
			tmp = cmd_pfind_th4->cmd_handler(device_phead);//����¶�
			humi = cmd_pfind_th4->cmd_handler(device_phead);//���ʪ��
			printf("current temperature:%d\n",tmp); //���ϴ�ӡ��ǰ���¶ȣ�ͬʱ�䵱������
			fflush(stdout); 
			pthread_mutex_lock(&mutex); //����
			//oled_show_init(); //����
			int tmp1 = tmp; //����tmp��ֵ������ΪʲôҪ�������ɣ����������֮�󱨾��ͻ�ʧЧ
			//oled_tmphumi(tmp1,humi); //��ʾ��OLED��
			pthread_mutex_unlock(&mutex); //����
			if(tmp > FIRE_TMP && voice_return_flag!=3){//����¶ȴ���XX�����û�ϣ��������
				device_pfind_th4 = findDEVICEinLink("beeper",device_phead);//�˴�����Ҫ���ж�device_pfind�Ƿ�Ϊ�գ���Ϊmain�����ڳ�ʼ����ʱ���жϹ���
				device_pfind_th4->open();				
			}else{ //����͹رվ���
				device_pfind_th4 = findDEVICEinLink("beeper",device_phead);//�˴�����Ҫ���ж�device_pfind�Ƿ�Ϊ�գ���Ϊmain�����ڳ�ʼ����ʱ���жϹ���
				device_pfind_th4->close();
			}
		}else{
			printf("thread4:can't find 'fire' in link!\n");
			fflush(stdout);
		}
 
	}
	
	pthread_exit(NULL);
}
*/
int main()
{
	pthread_t tid1;
	pthread_t tid2;

	device	  *device_pfind = NULL;
	cmd		  *cmd_pfind 	= NULL;
    data 	  *datas 		= NULL;
	device_phead = (device*)malloc(sizeof(device));
	cmd_phead 	 = (cmd*)malloc(sizeof(cmd));

	//��ʼ��wiringPi��
	wiringPiSetup();
	
	//ָ�����ʼ��
	cmd_phead = PutFireInLink(cmd_phead);
 
	//�豸������ʼ��
	device_phead = PutLEDInLink(device_phead);
	device_phead = PutDhtInLink(device_phead);
	device_phead = PutBeeperInLink(device_phead);
	device_phead = PutPressureInLink(device_phead);
	device_phead = PutHCInLink(device_phead);
	device_phead = PutSGInLink(device_phead);

	device_pfind = findDEVICEinLink(LED_RED_NAME,device_phead);
	if(device_pfind != NULL){
		device_pfind->init();
		printf("main:find '%s' in link!\n",device_pfind->device_name);
	}else{
		printf("main:can't find '%s' in link!\n",device_pfind->device_name);
	}

	device_pfind = findDEVICEinLink(LED_GREEN_NAME,device_phead);
	if(device_pfind != NULL){
		device_pfind->init();
		printf("main:find '%s' in link!\n",device_pfind->device_name);
	}else{
		printf("main:can't find '%s' in link!\n",device_pfind->device_name);
	}

	device_pfind = findDEVICEinLink(LED_YELLOW_NAME,device_phead);
	if(device_pfind != NULL){
		device_pfind->init();
		printf("main:find '%s' in link!\n",device_pfind->device_name);
	}else{
		printf("main:can't find '%s' in link!\n",device_pfind->device_name);
	}

	device_pfind = findDEVICEinLink(DHT_NAME,device_phead);
	if(device_pfind != NULL){
		device_pfind->init();
		printf("main:find '%s' in link!\n",device_pfind->device_name);
	}else{
		printf("main:can't find '%s' in link!\n",device_pfind->device_name);
	}
	
	device_pfind = findDEVICEinLink(SG_NAME,device_phead);
	if(device_pfind != NULL){
		device_pfind->init();
		printf("main:find '%s' in link!\n",device_pfind->device_name);
	}else{
		printf("main:can't find '%s' in link!\n",device_pfind->device_name);
	}

	device_pfind = findDEVICEinLink(BEEPER_NAME,device_phead);
	if(device_pfind != NULL){
		device_pfind->init();
		printf("main:find '%s' in link!\n",device_pfind->device_name);
	}else{
		printf("main:can't find '%s' in link!\n",device_pfind->device_name);
	}

	device_pfind = findDEVICEinLink(PRESSURE_NAME,device_phead);
	if(device_pfind != NULL){
		device_pfind->init();
		printf("main:find '%s' in link!\n",device_pfind->device_name);
	}else{
		printf("main:can't find '%s' in link!\n",device_pfind->device_name);
	}

	datas = data_init();
	
	//MQTT��ʼ��
	mqtt_init(datas);
	

	// //��������ʼ��
	// if(pthread_mutex_init(&mutex, NULL) != 0){
	// 	printf("mutex create error\n");
	// 	pthread_mutex_destroy(&mutex);
	// }

	//atexit(cleanup);

	//ִ��ָ���߳�
    pthread_create(&tid1, NULL, thread_cmd_ctl, datas);
    printf("Thread worker1 tid[%lu] created ok\n", tid1);

	//�ɼ������߳�
    pthread_create(&tid2, NULL, thread_get_data, datas);
    printf("Thread worker2 tid[%lu] created ok\n", tid2);

	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
 
	//�ͷ�python������
	//face_final();
	//oled_final();
	
	return 0;
}

void *thread_get_data(void *thread_argv)
{
	data 		*datas = (data*)thread_argv;	
	attribute 	*attributes = datas->attributes;
	device 		*device_phead = datas->device_phead;
	device 		*device_pfind = NULL;
	float 		*dht_data = (float*)malloc(sizeof(float)<<1);
	while(true)
	{
		// //��ȡLED���״̬
		device_pfind = findDEVICEinLink(LED_RED_NAME,device_phead);
		attributes->led_red = *(int*)device_pfind->read_status();

		//��ȡLED�̵�״̬
		device_pfind = findDEVICEinLink(LED_GREEN_NAME,device_phead);
		attributes->led_green = *(int*)device_pfind->read_status();

		//��ȡLED�Ƶ�״̬
		device_pfind = findDEVICEinLink(LED_YELLOW_NAME,device_phead);
		attributes->led_yellow = *(int*)device_pfind->read_status();

		//��ȡ������״̬
		device_pfind = findDEVICEinLink(BEEPER_NAME,device_phead);
		attributes->beeper = *(int*)device_pfind->read_status();

		//��ȡѹ������������
		device_pfind = findDEVICEinLink(PRESSURE_NAME,device_phead);
		attributes->pressure = *(float*)device_pfind->read_status();
		printf("%.2f\n",attributes->pressure);

		//��ȡ��ʪ������
		device_pfind = findDEVICEinLink(DHT_NAME,device_phead);
		dht_data = (float*)device_pfind->read_status();
		attributes->temperature = dht_data[0];
		attributes->humidity = (int)dht_data[1];

		//��ȡ���״̬
		device_pfind = findDEVICEinLink(SG_NAME,device_phead);
		attributes->window = *(int*)device_pfind->read_status();

		//MQTT����
		mqtt_publish(thread_argv);
		sleep(2);
		
	}

	pthread_exit(NULL);
}

void *thread_cmd_ctl(void *thread_argv)
{
	data 		*datas = (data*)thread_argv;	
	device 		*device_phead = datas->device_phead;
	device 		*device_pfind = NULL;
	cmd			*cmd_pfind = NULL;
	//��ʼ����
	device_pfind = findDEVICEinLink(LED_GREEN_NAME,device_phead);
	device_pfind->open();
	while(true){
		//����
		cmd_pfind = findCMDinLink(FIRE_CONTROL_NAME,cmd_phead);
		cmd_pfind->cmd_handler(datas);
		//����
		// cmd_pfind = findCMDinLink(GAS_CONTROL_NAME,cmd_phead);
		// cmd_pfind->cmd_handler(datas);

		//������Ա
		// cmd_pfind = findCMDinLink(INF_CONTROL_NAME,cmd_phead);
		// cmd_pfind->cmd_handler(datas);
		sleep(1);
	}
	//��������
	device_pfind = findDEVICEinLink(LED_GREEN_NAME,device_phead);
	device_pfind->close();
	pthread_exit(NULL);
}




void cleanup(void *thread_argv){
	printf("111111\n");
	data 		*datas = (data*)thread_argv;
	datas->attributes->led_green = false;
	mqtt_publish(thread_argv);
}