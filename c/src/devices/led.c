#include "device_fac.h"

device led[3];

//ºìµÆ
int led_red_init()
{
	pinMode (LED_RED_GPIO, OUTPUT); 
	digitalWrite (LED_RED_GPIO, LOW) ;
}
 
int led_red_open()
{
	digitalWrite (LED_RED_GPIO, HIGH) ;  //µÆÁÁ
    led[0].status = true;
}
 
int led_red_close()
{
	digitalWrite (LED_RED_GPIO, LOW) ;  //µÆÃð
    led[0].status = false;
}

void* led_red_read_status()
{
	return &led[0].status;
}

//ÂÌµÆ
int led_green_init()
{
	pinMode (LED_GREEN_GPIO, OUTPUT); 
	digitalWrite (LED_GREEN_GPIO, LOW) ;
}
 
int led_green_open()
{
	digitalWrite (LED_GREEN_GPIO, HIGH) ;  //µÆÁÁ
    led[1].status = true;
}
 
int led_green_close()
{
	digitalWrite (LED_GREEN_GPIO, LOW) ;  //µÆÃð
    led[1].status = false;
}

void* led_green_read_status()
{
	return &led[1].status;
}

//»ÆµÆ
int led_yellow_init()
{
	pinMode (LED_YELLOW_GPIO, OUTPUT); 
	digitalWrite (LED_YELLOW_GPIO, LOW) ;
}
 
int led_yellow_open()
{
	digitalWrite (LED_YELLOW_GPIO, HIGH) ;  //µÆÁÁ
    led[2].status = true;	
}
 
int led_yellow_close()
{
	digitalWrite (LED_YELLOW_GPIO, LOW) ;  //µÆÃð
    led[2].status = false;
}

void* led_yellow_read_status()
{
	return &led[2].status;
}
 
device led[3] = {
    {
        .device_name = LED_RED_NAME,
        .init        = led_red_init,
        .open        = led_red_open,
        .close       = led_red_close,
        .read_status = led_red_read_status
    },{
        .device_name = LED_GREEN_NAME,
        .init        = led_green_init,
        .open        = led_green_open,
        .close       = led_green_close,
        .read_status = led_green_read_status
    },{
        .device_name = LED_YELLOW_NAME,
        .init        = led_yellow_init,
        .open        = led_yellow_open,
        .close       = led_yellow_close,
        .read_status = led_yellow_read_status
    },
};
 
void PutLEDInLink()
{
	for(int i = 0; i < 3; ++i){	
        led[i].next = device_phead->next;		
        device_phead->next = &led[i];	
    }
}