#include "find_link.h"
 
device* findDEVICEinLink(char *name)
{	
	device *p = device_phead->next;
	while(p != NULL){
		if(strcmp(p->device_name,name)==0){			
			return p;		
		}		
		p = p->next;
	}	
	return NULL;
}
 
cmd* findCMDinLink(char *name)
{	
	cmd *p = cmd_phead->next;
	while(p != NULL){		
		if(strcmp(p->cmd_name,name)==0){			
			return p;		
		}
		p = p->next;	
	}
	return NULL;
}