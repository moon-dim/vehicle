/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-19 22:22:10
 * @LastEditTime : 2025-06-04 10:29:45
 * @FilePath     : \vehicle\c\src\devices\sg90.c
 * @Description  : 
 */
#include "device_fac.h"

device sg;
 
int sg_init()
{
	pinMode (SG_GPIO, OUTPUT);
	softPwmCreate(SG_GPIO, 0, 200);
}

// 正转开窗
int sg_open()
{
	if(sg.status)return 0;
    softPwmWrite(SG_GPIO,10);
    sleep(3);
    softPwmWrite (SG_GPIO, 15);
    sg.status = true;
}

// 反转关窗
int sg_close()
{
	if(!sg.status)return 0;
    softPwmWrite(SG_GPIO,20);
    sleep(3);
    softPwmWrite (SG_GPIO, 15);
    sg.status = false;
}

void* sg_read_status()
{
    return (void*)&sg.status;
}
 
 
device sg = {
	.device_name = SG_NAME,
	.init 		 = sg_init,
	.open 		 = sg_open,
	.close 		 = sg_close,
	.read_status = sg_read_status
};

void PutSGInLink()
{	
	sg.next = device_phead->next;
	device_phead->next = &sg;
}