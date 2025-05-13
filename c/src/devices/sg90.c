#include "device_fac.h"

device sg;
 
int sg_init()
{
	pinMode (SG_GPIO, OUTPUT);
	softPwmCreate(SG_GPIO, 15, 200);
}
 
int sg_open()
{
	if(sg.status)return 0;
    softPwmWrite(SG_GPIO,25);
    sleep(3);
    softPwmWrite (SG_GPIO, 15);
    sg.status = true;
}
 
int sg_close()
{
	if(!sg.status)return 0;
    softPwmWrite(SG_GPIO,5);
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

device* PutSGInLink(device *head)
{	
	sg.next = head->next;
	head->next = &sg;
	return head;
}