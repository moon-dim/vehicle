#include "device_fac.h"
 
int HC_init()
{
	pinMode (HC_GPIO, OUTPUT); 
	digitalWrite (HC_GPIO, HIGH);
}
 
int HC_open()
{
	digitalWrite (HC_GPIO, LOW) ;
}
 
int HC_close()
{
	digitalWrite (HC_GPIO, HIGH) ;
}
 
 
device HC = {
	.device_name = HC_NAME,
	.init 		 = HC_init,
	.open 		 = HC_open,
	.close 		 = HC_close,
};

device* PutHCInLink(device *head)
{	
	HC.next = head->next;
	head->next = &HC;
	return head;
}


// void* infCTL(void *obj)
// {
// 	data 		*tmp = (data*)obj;	
// 	data_mqtt 	*mqtt = tmp->mqtt;
// 	device 		*device_phead = tmp->device_phead;
// 	device 		*device_pfind = NULL;
// 	cmd			*cmd_pfind = NULL;
// 	device_pfind = findDEVICEinLink(HC_NAME,device_phead);
// 	int status = *(int*)device_pfind->read_status();
// 	if(status){
// 		device_pfind = findDEVICEinLink(LED_YELLOW_NAME,device_phead);
// 		device_pfind->open();
// 		mqtt->attributes.in_car = true;
// 	}
// 	// else if(!in_car){
// 	// 	device_pfind = findDEVICEinLink(LED_YELLOW_NAME,device_phead);
// 	// 	device_pfind->close();
// 	// }
// }