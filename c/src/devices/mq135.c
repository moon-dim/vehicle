#include "device_fac.h"
#include <math.h>

device mq;
int fd;
float ppm;

int mq_init()
{
	fd = wiringPiI2CSetup(PCF8591_ADDRESS);
    if (fd == -1) {
        printf("�޷���I2C�豸��\n");
        return fd;
    }
}
 
int mq_open()
{
	;

}
 
int mq_close()
{
	fd = 0;
}

void* mq_read_status()
{
	// ѡ��AIN0ͨ��������ת��
    wiringPiI2CWrite(fd, PCF8591_AIN0);
    // �ȴ�ת����ɣ�10ms��
    delayMicroseconds(10000);

     // ��ȡAIN0ͨ����ֵ
    float value = wiringPiI2CRead(fd);

     // �����ѹֵ������Ũ��
    float Vout = value * VOLTAGE_REF / 255.0;
    ppm = pow((3.4880*10*Vout)/(VOLTAGE_REF-Vout), 1.0/0.3203);
    // printf("value: %f\nVout: %f\nppm: %f\n",value, Vout, ppm);
    return (void*)&ppm;
}
 
 
device mq = {
	.device_name = MQ_NAME,
	.init 		 = mq_init,
	.open 		 = mq_open,
	.close 		 = mq_close,
	.read_status = mq_read_status
};

void PutMQInLink()
{	
	mq.next = device_phead->next;
	device_phead->next = &mq;
}