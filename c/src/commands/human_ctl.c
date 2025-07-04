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

void* humanCTL()
{
	sem_wait(sem);
	float pressure = attribute_ptr->pressure;
	int face_detection = attribute_ptr->face_detection;

    if(pressure<= PRESSURE_NOHUMAN && face_detection){
		attribute_ptr->in_car = true;
	}
	else if(pressure >= PRESSURE_HAVEHUMAN){
		attribute_ptr->in_car = false;
	}
	
	sem_post(sem);
}

cmd human = {
	.cmd_name = HUMAN_CTL_NAME,
	.cmd_handler = humanCTL,
};
 
void PutHumanCTLInLink()
{		
	human.next = cmd_phead->next;
	cmd_phead->next = &human;
}
