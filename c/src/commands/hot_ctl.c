/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-19 22:22:10
 * @LastEditTime : 2025-06-04 10:45:10
 * @FilePath     : \vehicle\c\src\commands\hot_ctl.c
 * @Description  : 
 */

#include "cmd_fac.h"
#include "find_link.h"
#include <math.h>

void* hotCTL()
{
	sem_wait(sem);
	float 		tem = attribute_ptr->temperature;
	float 		hum = attribute_ptr->humidity;

	float		e = hum / 100 * 6.105 * exp(17.27 * tem / (237.7 + tem)); 	//计算饱和水汽压
	float		AT = 1.07 * tem + 0.2 * e - 2.7;							  //体感温度
	printf("tem: %.2f, hum: %.2f, AT: %.2f\n", tem, hum, AT);

	
	if(attribute_ptr->in_car && !attribute_ptr->hot_ctl){
		if((AT >= attribute_ptr->temperature_threshold && !attribute_ptr->hand_ctl) || AT >= AT_DANGER){
			//打开蜂鸣器
			findDEVICEinLink(BEEPER_NAME)->open();
			attribute_ptr->beeper = true;
			// printf("Beeper ON\n");

			//打开LED黄灯
			findDEVICEinLink(LED_YELLOW_NAME)->open(); 
			attribute_ptr->led_yellow = true;
			// printf("LED Yellow ON\n");

			//打开窗户
			findDEVICEinLink(SG_NAME)->open(); 
			attribute_ptr->window = true;

			attribute_ptr->hot_ctl = true;  //设置高温报警状态
			sem_post(sem);
			printf("4\n");
			mqtt_publish_urgent();  //发布紧急消息
		}
		else{
			sem_post(sem);
		}
	}
	else{
		sem_post(sem);
	}

}

cmd hot = {
	.cmd_name = HOT_CTL_NAME,
	.cmd_handler = hotCTL,
};
 
void PutHotCTLInLink()
{		
	hot.next = cmd_phead->next;
	cmd_phead->next = &hot;
}
