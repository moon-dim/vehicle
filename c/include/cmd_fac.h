#ifndef __CMDFAC_H__
#define __CMDFAC_H__
 
#include <wiringPi.h>
#include <sys/types.h>     
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "device_fac.h"
#include "public_data.h"
#include "mqtt_conf.h"

#define AT_DANGER 40			//体感温度危险阈值
#define GAS_DANGER 50			//有害气体浓度危险阈值
#define PRESSURE_NOHUMAN	50 	//无人压力阈值
#define PRESSURE_HAVEHUMAN	600 //有人压力阈值

#define HOT_CTL_NAME "hot_ctl"  //高温控制指令名称
#define GAS_CTL_NAME "gas_ctl"  //有害气体控制指令名称
#define HUMAN_CTL_NAME "human_ctl"	//滞留人员监测指令
 
typedef struct cmd
{
	char cmd_name[64]; 			//指令名称
	void*(*cmd_handler)();		//指令操作
	struct cmd *next;
}cmd;
 
extern cmd	*cmd_phead;

void PutHotCTLInLink();
void PutGasCTLInLink();
void PutHumanCTLInLink();

void cmd_init();

#endif