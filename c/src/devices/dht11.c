#include "device_fac.h"

int dht_init(){
	pinMode(DHT_GPIO, OUTPUT);
	digitalWrite(DHT_GPIO, HIGH); 
}

int dht_start()
{
	pinMode(DHT_GPIO, OUTPUT); //起始拉高电平
	digitalWrite(DHT_GPIO, HIGH); 
	delay(1000);

	digitalWrite(DHT_GPIO, LOW);
	delay(25);
		
	digitalWrite(DHT_GPIO, HIGH); //拉高电平，等响应
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
	if(!digitalRead(DHT_GPIO))				//主机接收到从机发送的响应信号（低电平）
	{
		while(!digitalRead(DHT_GPIO));		//主机接收到从机发送的响应信号（高电平）
		for (int i = 0; i < 32; i++){
			while(digitalRead(DHT_GPIO));	//数据位开始的54us低电平
			while(!digitalRead(DHT_GPIO));	//数据位开始的高电平就开始
			delayMicroseconds(40);			//等50us，此时电平高为1，低为0
			data <<= 1;   					//进位
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

	res[0] = ((data >> 8) & 0xff) + (data & 0xff)/100.0; //温度
	res[1] = ((data >> 24) & 0xff);						 //湿度
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