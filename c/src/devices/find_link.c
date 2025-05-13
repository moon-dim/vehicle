#include "find_link.h"
 
device* findDEVICEinLink(char *name, device *phead)
{	
	device *p = phead->next;
	while(p != NULL){
		if(strcmp(p->device_name,name)==0){			
			return p;		
		}		
		p = p->next;
	}	
	return NULL;
}
 
cmd* findCMDinLink(char *name, cmd *phead)
{	
	cmd *p = phead->next;
	while(p != NULL){		
		if(strcmp(p->cmd_name,name)==0){			
			return p;		
		}		
		p = p->next;	
	}
	return NULL;
}