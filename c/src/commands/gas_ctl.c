/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-19 22:22:10
 * @LastEditTime : 2025-06-04 11:32:12
 * @FilePath     : \vehicle\c\src\commands\gas_ctl.c
 * @Description  : 
 */

#include "cmd_fac.h"
#include "find_link.h"
#include <math.h>

void* gasCTL()
{
	sem_wait(sem);
	float 		ppm = attribute_ptr->gas;  //获取有害气体浓度
    printf("Gas Concentration: %.2f ppm\n", ppm);
	
	if(attribute_ptr->in_car && !attribute_ptr->gas_ctl){
		if((ppm >= attribute_ptr->gas_threshold && !attribute_ptr->hand_ctl) || ppm >= GAS_DANGER){

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

			attribute_ptr->gas_ctl = true;  //设置有害气体报警状态
			sem_post(sem);

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

cmd gas = {
	.cmd_name = GAS_CTL_NAME,
	.cmd_handler = gasCTL
};
 
void PutGasCTLInLink()
{		
	gas.next = cmd_phead->next;
	cmd_phead->next = &gas;
}
