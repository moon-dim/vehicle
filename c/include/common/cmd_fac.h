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
#include "find_link.h"

#define FIRE_TEM 20
#define FIRE_HUM 70

 
typedef struct cmd
{
	char cmd_name[64]; 										//指令名称
	//char cmd_log[1024]; 									//指令日志
	//int (*cmd_handler)(device *phead, int fd);
	void*(*cmd_handler)(void *obj);							//指令操作
	struct cmd *next;
}cmd;
 
extern cmd	*cmd_phead;

//struct cmd* putVoiceInLink(struct cmd *head);
cmd* PutFireInLink(cmd *head);

#endif