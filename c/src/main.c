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

#define FIRE_TMP 30 						//火灾报警温度

#define sql_path "../database/data.db" 	 	//数据库存取的的路径
#define zlog_path "../etc/zlog.conf"  	 	//日志系统的保存路径

void *thread_cmd_ctl(void *thread_argv);	//线程1：指令执行
void *thread_get_data(void *thread_argv);	//线程2：数据采集
data *data_init();							//总数据结构体初始化
void cleanup(void *thread_argv);

int rv = -1; 	//创建rv（主函数）,该变量用于配置文件解析
int rc = -1; 	//创建rc（主函数）,该变量用于日志系统
//pthread_mutex_t mutex;
device			*device_phead = NULL;
cmd 			*cmd_phead    = NULL;

/*
void *thread4(void *arg) //火灾报警线程
{
	struct cmd *cmd_pfind_th4 = NULL;
	struct device *device_pfind_th4 = NULL;
 
	while(1){
		//delay(1000);//不用delay因为线程间本来就是竞争关系，加上一共有多个线程，哪怕不delay也不会很快速的运行
		cmd_pfind_th4 = findCMDinLink("fire",cmd_phead);
		if(cmd_pfind_th4!=NULL){
			tmp = cmd_pfind_th4->cmd_handler(device_phead);//检测温度
			humi = cmd_pfind_th4->cmd_handler(device_phead);//检测湿度
			printf("current temperature:%d\n",tmp); //不断打印当前的温度，同时充当心跳包
			fflush(stdout); 
			pthread_mutex_lock(&mutex); //上锁
			//oled_show_init(); //清屏
			int tmp1 = tmp; //保留tmp的值，至于为什么要保留存疑，如果不保留之后报警就会失效
			//oled_tmphumi(tmp1,humi); //显示在OLED上
			pthread_mutex_unlock(&mutex); //解锁
			if(tmp > FIRE_TMP && voice_return_flag!=3){//如果温度大于XX度且用户希望警报打开
				device_pfind_th4 = findDEVICEinLink("beeper",device_phead);//此处不需要再判断device_pfind是否为空，因为main函数在初始化的时候判断过了
				device_pfind_th4->open();				
			}else{ //否则就关闭警报
				device_pfind_th4 = findDEVICEinLink("beeper",device_phead);//此处不需要再判断device_pfind是否为空，因为main函数在初始化的时候判断过了
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

	//初始化wiringPi库
	wiringPiSetup();
	
	//指令工厂初始化
	cmd_phead = PutFireInLink(cmd_phead);
 
	//设备工厂初始化
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
	
	//MQTT初始化
	mqtt_init(datas);
	

	// //互斥锁初始化
	// if(pthread_mutex_init(&mutex, NULL) != 0){
	// 	printf("mutex create error\n");
	// 	pthread_mutex_destroy(&mutex);
	// }

	//atexit(cleanup);

	//执行指令线程
    pthread_create(&tid1, NULL, thread_cmd_ctl, datas);
    printf("Thread worker1 tid[%lu] created ok\n", tid1);

	//采集数据线程
    pthread_create(&tid2, NULL, thread_get_data, datas);
    printf("Thread worker2 tid[%lu] created ok\n", tid2);

	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
 
	//释放python解释器
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
		// //读取LED红灯状态
		device_pfind = findDEVICEinLink(LED_RED_NAME,device_phead);
		attributes->led_red = *(int*)device_pfind->read_status();

		//读取LED绿灯状态
		device_pfind = findDEVICEinLink(LED_GREEN_NAME,device_phead);
		attributes->led_green = *(int*)device_pfind->read_status();

		//读取LED黄灯状态
		device_pfind = findDEVICEinLink(LED_YELLOW_NAME,device_phead);
		attributes->led_yellow = *(int*)device_pfind->read_status();

		//读取蜂鸣器状态
		device_pfind = findDEVICEinLink(BEEPER_NAME,device_phead);
		attributes->beeper = *(int*)device_pfind->read_status();

		//读取压力传感器数据
		device_pfind = findDEVICEinLink(PRESSURE_NAME,device_phead);
		attributes->pressure = *(float*)device_pfind->read_status();
		printf("%.2f\n",attributes->pressure);

		//读取温湿度数据
		device_pfind = findDEVICEinLink(DHT_NAME,device_phead);
		dht_data = (float*)device_pfind->read_status();
		attributes->temperature = dht_data[0];
		attributes->humidity = (int)dht_data[1];

		//读取舵机状态
		device_pfind = findDEVICEinLink(SG_NAME,device_phead);
		attributes->window = *(int*)device_pfind->read_status();

		//MQTT发布
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
	//开始工作
	device_pfind = findDEVICEinLink(LED_GREEN_NAME,device_phead);
	device_pfind->open();
	while(true){
		//火灾
		cmd_pfind = findCMDinLink(FIRE_CONTROL_NAME,cmd_phead);
		cmd_pfind->cmd_handler(datas);
		//气体
		// cmd_pfind = findCMDinLink(GAS_CONTROL_NAME,cmd_phead);
		// cmd_pfind->cmd_handler(datas);

		//有无人员
		// cmd_pfind = findCMDinLink(INF_CONTROL_NAME,cmd_phead);
		// cmd_pfind->cmd_handler(datas);
		sleep(1);
	}
	//结束工作
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