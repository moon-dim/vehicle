#include "public_data.h"
#include "cmd_fac.h"
#include "device_fac.h"
#include "find_link.h"

void* fireCTL()
{
	device 		*device_pfind = NULL;
	float *dht_data = (float*)malloc(sizeof(float)*2);

	device_pfind = findDEVICEinLink(DHT_NAME);
	dht_data = (float*)device_pfind->read_status();
	float tem = dht_data[0];
	int hum = dht_data[1];
	if(tem > FIRE_TEM && hum < FIRE_HUM&& !attribute_ptr->hand_ctl){
		attribute_ptr->fire_ctl = true;
		device_pfind = findDEVICEinLink(BEEPER_NAME);
		device_pfind->open();
		device_pfind = findDEVICEinLink(LED_RED_NAME);
		device_pfind->open();
		device_pfind = findDEVICEinLink(SG_NAME);
		device_pfind->open();
		attribute_ptr->hand_ctl = true;
	}else if(!attribute_ptr->fire_ctl && !attribute_ptr->gas){
		device_pfind = findDEVICEinLink(BEEPER_NAME);
		device_pfind->close();
		device_pfind = findDEVICEinLink(LED_RED_NAME);
		device_pfind->close();
		device_pfind = findDEVICEinLink(SG_NAME);
		device_pfind->close();
		attribute_ptr->hand_ctl = true;
	}
}

cmd fire = {
	.cmd_name = FIRE_CONTROL_NAME,
	.cmd_handler = fireCTL,
};
 
void PutFireInLink()
{		
	fire.next = cmd_phead->next;
	cmd_phead->next = &fire;
}
