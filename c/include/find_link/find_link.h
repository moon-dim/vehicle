#ifndef __FINDLINK_H__
#define __FINDLINK_H__
 
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "cmd_fac.h"
#include "device_fac.h"

device* findDEVICEinLink(char *name, device *phead);
struct cmd* findCMDinLink(char *name, struct cmd *phead);
 
#endif