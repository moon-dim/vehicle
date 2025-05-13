#include "public_data.h"
#include "mqtt_conf.h"

extern struct mosquitto     *mosquit_ptr        = NULL;
extern mosquitto_inf        *mosquit_inf_ptr    = NULL;
extern attribute            *attribute_ptr      = NULL;
extern cmd	                *cmd_phead          = NULL;
extern device	            *device_phead       = NULL;

void __init__(){
    mosquit_inf_ptr    = (mosquitto_inf*)malloc(sizeof(mosquitto_inf));
    attribute_ptr      = (attribute*)malloc(sizeof(attribute));
    cmd_phead          = (cmd*)malloc(sizeof(cmd));
    device_phead       = (device*)malloc(sizeof(device));
}