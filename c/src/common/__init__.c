#include "public_data.h"
#include "cmd_fac.h"
#include "device_fac.h"
#include "mqtt_conf.h"
#include "face_detection.h"
#include "find_link.h"


struct mosquitto     *mosquit_ptr       = NULL;
mosquitto_inf        *mosquit_inf_ptr   = NULL;
cmd	                 *cmd_phead         = NULL;
device	             *device_phead      = NULL;
attribute            *attribute_ptr     = NULL;
sem_t                *sem               = NULL;

void __init__()
{
    mosquit_inf_ptr    = (mosquitto_inf*)malloc(sizeof(mosquitto_inf));
    cmd_phead          = (cmd*)malloc(sizeof(cmd));
    device_phead       = (device*)malloc(sizeof(device));


/*****************************************�ѷ���_2025.06.03 00:25*************************************************************/
    //��ʼ��python������
    // py_init();
/*****************************************�ѷ���_2025.06.03 00:25*************************************************************/

    //��ʼ����������
    shm_init();
    
    //��ʼ��wiringPi��
	wiringPiSetup();

    //��ʼ��ȫ���豸
    device_init();

    //��ʼ��ȫ��ָ��
    cmd_init();

    //��ʼ��MQTTQ
    mqtt_init();

    //����������
    findDEVICEinLink(LED_GREEN_NAME)->open();

}

void shm_init(){
    // ���������ڴ����
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SHM_SIZE);
    attribute_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("shm_attribute_ptr_address: %d\n", &attribute_ptr);
    close(fd);

    // �����ź��������̼�ͬ����
    sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);

    sem_wait(sem);
    attribute_ptr->temperature_threshold = 35;
    attribute_ptr->gas_threshold         = 10;
    sem_post(sem);
}

//��ʼ��ȫ���豸
void device_init(){
	PutLEDInLink();
	PutDhtInLink();
	PutBeeperInLink();
	PutPressureInLink();
	PutSGInLink();
    PutMQInLink();
    device *p = device_phead->next;
	while(p != NULL){
		p->init();
		printf("main:find '%s' in link!\n",p->device_name);
		p = p->next;
	}
}

//��ʼ��ȫ��ָ��
void cmd_init(){
    PutHotCTLInLink();
    PutGasCTLInLink();
}