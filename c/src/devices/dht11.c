#include "device_fac.h"
#include <sys/time.h>

float res[2];

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
	delay(18);
		
	digitalWrite(DHT_GPIO, HIGH); //拉高电平，等响应
	pinMode(DHT_GPIO, INPUT);
	pullUpDnControl(DHT_GPIO, PUD_UP);
    delayMicroseconds(40);
}


int waitLevel(int target, int timeout_us) {
    struct timeval start, now;
    gettimeofday(&start, NULL);
    
    while (digitalRead(DHT_GPIO) == target) {
        gettimeofday(&now, NULL);
        if ((now.tv_sec - start.tv_sec) * 1000000 + 
            (now.tv_usec - start.tv_usec) > timeout_us) {
            return -1;
        }
    }
    return 0;
}
 
void* dht_read_status()
{
	unsigned long data = 0, crc = 0;
	dht_start();
	if(!digitalRead(DHT_GPIO))				//主机接收到从机发送的响应信号（低电平）
	{
		
		// while(!digitalRead(DHT_GPIO));
		if (waitLevel(LOW, 1000) == -1){	//主机接收到从机发送的响应信号（高电平）
			printf("DHT11 timeout!\n");
			goto final;
		}

		for (int i = 0; i < 32; i++){
			// while(digitalRead(DHT_GPIO));	//数据位开始的54us低电平
			if (waitLevel(HIGH, 1000) == -1){	//数据位开始的54us低电平
				printf("DHT11 timeout!\n");
				goto final;
			}
			// while(!digitalRead(DHT_GPIO));		//数据位开始的高电平就开始
			if (waitLevel(LOW, 1000) == -1){	//数据位开始的高电平就开始
				printf("DHT11 timeout!\n");
				goto final;
			}

			
			delayMicroseconds(40);			//等50us，此时电平高为1，低为0
			data <<= 1;   					//进位
			if (digitalRead(DHT_GPIO)) data++;
		}

		for (int i = 0; i < 8; i++){
			// while(digitalRead(DHT_GPIO));	//数据位开始的54us低电平
			if (waitLevel(HIGH, 1000) == -1){	//数据位开始的54us低电平
				printf("DHT11 timeout!\n");
				goto final;
			}
			// while(!digitalRead(DHT_GPIO));		//数据位开始的高电平就开始
			if (waitLevel(LOW, 1000) == -1){	//数据位开始的高电平就开始
				printf("DHT11 timeout!\n");
				goto final;
			}

			delayMicroseconds(40);			
			crc <<= 1;  
			if (digitalRead(DHT_GPIO)) crc++;
		}
	}
	res[0] = ((data >> 8) & 0xff) + (data & 0xff)/100.0; //温度
	res[1] = ((data >> 24) & 0xff);						 //湿度

final:
	return (void*)&res;
}


device dht11 = {
		.device_name = DHT_NAME,
		.init = dht_init,
		.open = dht_start,
		.read_status = dht_read_status,
};
 
void PutDhtInLink()
{	   		
	dht11.next = device_phead->next;
	device_phead->next = &dht11;
}