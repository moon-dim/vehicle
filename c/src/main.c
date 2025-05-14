#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <libgen.h>
#include <getopt.h>
#include <mosquitto.h>
#include <zlog.h>

#include "public_data.h"
#include "find_link.h"
#include "thread.h"
#include "face_detection.h"

// #define sql_path 	"../database/data.db" 	 	//数据库存取的的路径
// #define zlog_path 	"../etc/zlog.conf"  	 	//日志系统的保存路径

int main()
{
	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;

	//初始化系统
	__init__();

	//执行指令线程
    pthread_create(&tid1, NULL, thread_cmd_ctl, NULL);
    printf("Thread worker1 tid[%lu] created ok\n", tid1);

	//采集数据线程
    pthread_create(&tid2, NULL, thread_get_data, NULL);
    printf("Thread worker2 tid[%lu] created ok\n", tid2);

	//人脸检测线程
	pthread_create(&tid3, NULL, py_start, NULL);
    printf("Thread worker3 tid[%lu] created ok\n", tid3);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	py_final();
 
	return 0;
}
