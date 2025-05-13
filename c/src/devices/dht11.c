#include "device_fac.h"

int dht_init(){
	pinMode(DHT_GPIO, OUTPUT);
	digitalWrite(DHT_GPIO, HIGH); 
}

int dht_start()
{
	pinMode(DHT_GPIO, OUTPUT); //��ʼ���ߵ�ƽ
	digitalWrite(DHT_GPIO, HIGH); 
	delay(1000);

	digitalWrite(DHT_GPIO, LOW);
	delay(25);
		
	digitalWrite(DHT_GPIO, HIGH); //���ߵ�ƽ������Ӧ
	pinMode(DHT_GPIO, INPUT);
	pullUpDnControl(DHT_GPIO, PUD_UP);
    delayMicroseconds(27);
}
 
void* dht_read_status()
{
	unsigned long data = 0, crc = 0;
	static float* res;
	res = (float*)malloc(sizeof(float)<<1);
	dht_start();
	if(!digitalRead(DHT_GPIO))				//�������յ��ӻ����͵���Ӧ�źţ��͵�ƽ��
	{
		while(!digitalRead(DHT_GPIO));		//�������յ��ӻ����͵���Ӧ�źţ��ߵ�ƽ��
		for (int i = 0; i < 32; i++){
			while(digitalRead(DHT_GPIO));	//����λ��ʼ��54us�͵�ƽ
			while(!digitalRead(DHT_GPIO));	//����λ��ʼ�ĸߵ�ƽ�Ϳ�ʼ
			delayMicroseconds(40);			//��50us����ʱ��ƽ��Ϊ1����Ϊ0
			data <<= 1;   					//��λ
			if (digitalRead(DHT_GPIO)) data++;
		}

		for (int i = 0; i < 8; i++){
			while(digitalRead(DHT_GPIO));	
			while(!digitalRead(DHT_GPIO));			
			delayMicroseconds(40);			
			crc <<= 1;  
			if (digitalRead(DHT_GPIO)) crc++;
		}
	}

	res[0] = ((data >> 8) & 0xff) + (data & 0xff)/100.0; //�¶�
	res[1] = ((data >> 24) & 0xff);						 //ʪ��
	return (void*)res;
}
 
 
device dht11 = {
		.device_name = DHT_NAME,
		.init = dht_init,
		.open = dht_start,
		.read_status = dht_read_status,
};
 
device* PutDhtInLink(device *head)
{	   		
	dht11.next = head->next;
	head->next = &dht11;	
	return head;
}