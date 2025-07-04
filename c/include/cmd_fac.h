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

#define AT_DANGER 40			//����¶�Σ����ֵ
#define GAS_DANGER 50			//�к�����Ũ��Σ����ֵ
#define PRESSURE_NOHUMAN	50 	//����ѹ����ֵ
#define PRESSURE_HAVEHUMAN	600 //����ѹ����ֵ

#define HOT_CTL_NAME "hot_ctl"  //���¿���ָ������
#define GAS_CTL_NAME "gas_ctl"  //�к��������ָ������
#define HUMAN_CTL_NAME "human_ctl"	//������Ա���ָ��
 
typedef struct cmd
{
	char cmd_name[64]; 			//ָ������
	void*(*cmd_handler)();		//ָ�����
	struct cmd *next;
}cmd;
 
extern cmd	*cmd_phead;

void PutHotCTLInLink();
void PutGasCTLInLink();
void PutHumanCTLInLink();

void cmd_init();

#endif