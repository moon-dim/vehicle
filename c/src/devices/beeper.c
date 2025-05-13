#include "device_fac.h"

device beeper;

int beep_init()
{
	pinMode (BEEPER_GPIO, OUTPUT); 
	digitalWrite (BEEPER_GPIO, HIGH);
}
 
int beep_open()
{
	digitalWrite (BEEPER_GPIO, LOW) ;  //·äÃùÆ÷Ïì
	beeper.status = true;
}
 
int beep_close()
{
	digitalWrite (BEEPER_GPIO, HIGH) ;  //·äÃùÆ÷²»Ïì
	beeper.status = false;
}

void* beeper_read_status()
{
	return &beeper.status;
}
 
 
device beeper = {
	.device_name = BEEPER_NAME,
	.init 		 = beep_init,
	.open 		 = beep_open,
	.close 		 = beep_close,
	.read_status = beeper_read_status
};

device* PutBeeperInLink(device *head)
{	
	beeper.next = head->next;
	head->next = &beeper;
	return head;
}