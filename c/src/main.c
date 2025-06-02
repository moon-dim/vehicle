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

int main()
{
	pthread_t tid1;
	pthread_t tid2;

	//初始化系统
	__init__();


/*****************************************已废弃_2025.06.03 00:25*************************************************************/
	//人脸检测线程
	// pthread_create(&tid1, NULL, py_start, NULL);
    // printf("Thread worker1 tid[%lu] created ok\n", tid1);
/*****************************************已废弃_2025.06.03 00:25*************************************************************/

	//等待指针初始化
	while(!attribute_ptr){
		printf("wait attribute_ptr init...\n\n");
		sleep(1);
	}
	printf("attributte_ptr init finish![address: %d]\n\n",&attribute_ptr);

	//采集数据线程
    pthread_create(&tid1, NULL, thread_get_data, NULL);
    printf("Thread worker3 tid[%lu] created ok\n", tid1);

	//执行指令线程
    // pthread_create(&tid2, NULL, thread_cmd_ctl, NULL);
    // printf("Thread worker2 tid[%lu] created ok\n", tid2);

	pthread_join(tid1,NULL);
	// pthread_join(tid2,NULL);
}
