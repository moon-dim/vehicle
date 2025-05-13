#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

void *thread_cmd_ctl();		//线程1：指令执行
void *thread_get_data();	//线程2：数据采集

#endif