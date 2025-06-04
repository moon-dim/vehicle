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
	float 		ppm = attribute_ptr->gas;  //��ȡ�к�����Ũ��
    printf("Gas Concentration: %.2f ppm\n", ppm);
	
	if(attribute_ptr->in_car && !attribute_ptr->gas_ctl){
		if((ppm >= attribute_ptr->gas_threshold && !attribute_ptr->hand_ctl) || ppm >= GAS_DANGER){

			//�򿪷�����
			findDEVICEinLink(BEEPER_NAME)->open();
			attribute_ptr->beeper = true;
			// printf("Beeper ON\n");

			//��LED�Ƶ�
			findDEVICEinLink(LED_YELLOW_NAME)->open(); 
			attribute_ptr->led_yellow = true;
			// printf("LED Yellow ON\n");

			//�򿪴���
			findDEVICEinLink(SG_NAME)->open(); 
			attribute_ptr->window = true;

			attribute_ptr->gas_ctl = true;  //�����к����屨��״̬
			sem_post(sem);

			mqtt_publish_urgent();  //����������Ϣ
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
