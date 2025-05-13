#include "cmd_fac.h"
#include "mqtt_conf.h"

void* fireCTL(void *obj)
{
	data 		*datas = (data*)obj;
	attribute 	*attributes = datas->attributes;
	device 		*device_phead = datas->device_phead;
	device 		*device_pfind = NULL;

	float *dht_data = (float*)malloc(sizeof(float)*2);

	device_pfind = findDEVICEinLink(DHT_NAME,device_phead);
	dht_data = (float*)device_pfind->read_status();
	float tem = dht_data[0];
	int hum = dht_data[1];
	if(tem > FIRE_TEM && hum < FIRE_HUM&& !attributes->hand_ctl){
		attributes->fire_ctl = true;
		device_pfind = findDEVICEinLink(BEEPER_NAME,device_phead);
		device_pfind->open();
		device_pfind = findDEVICEinLink(LED_RED_NAME,device_phead);
		device_pfind->open();
		device_pfind = findDEVICEinLink(SG_NAME,device_phead);
		device_pfind->open();
		attributes->hand_ctl = true;
	}else if(!attributes->fire_ctl && !attributes->gas){
		device_pfind = findDEVICEinLink(BEEPER_NAME,device_phead);
		device_pfind->close();
		device_pfind = findDEVICEinLink(LED_RED_NAME,device_phead);
		device_pfind->close();
		device_pfind = findDEVICEinLink(SG_NAME,device_phead);
		device_pfind->close();
		attributes->hand_ctl = true;
	}
}

cmd fire = {
	.cmd_name = FIRE_CONTROL_NAME,
	.cmd_handler = fireCTL,
};
 
cmd* PutFireInLink(cmd *head)
{		
	fire.next = head->next;
	head->next = &fire;
	return head; 
}
