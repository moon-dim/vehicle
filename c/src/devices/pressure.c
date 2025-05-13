#include "device_fac.h"

#define max(a,b) a>b?a:b

device pressure;
long long zero_offset = 0;  	// ����У׼ƫ����
float scale = 208.04;           //����У׼
long long data = 0;
float ans = 0;

void* pressure_read_status()
{
    static int cnt = 0;
    if(cnt<=20)cnt++; 

    data = 0;
    // �ȴ�������׼����
	while (digitalRead(PRESSURE_GPIO) == HIGH){
        delayMicroseconds(10);
    }

    // ��ȡ24λ����
    for (int i = 0; i < 24; i++) {
        digitalWrite(PRESSURE_SCK, HIGH);
        delayMicroseconds(1);
        data <<= 1;
        if (digitalRead(PRESSURE_GPIO)){
            data++;
        }
        digitalWrite(PRESSURE_SCK, LOW);
        delayMicroseconds(1);
    }

    // ��������Ϊ128�����Ͷ����ʱ�����壩
    digitalWrite(PRESSURE_SCK, HIGH);
    delayMicroseconds(1);
    digitalWrite(PRESSURE_SCK, LOW);
    delayMicroseconds(1);

    // �������λ��24λ�з�����ת����
    if (data & 0x800000){
        data |= 0xFF000000;
    }
    
	data = max(data-zero_offset,0);
    if(cnt > 20){
        ans = data / scale;
        return (void*)&ans;
    }
	return (void*)&data;
}

// У׼����״̬
void calibrate_tare() {
    long long sum = 0;
    for (int i = 0; i < 20; i++) {
        sum += *(long long*)pressure_read_status();
    }
    zero_offset = sum / 20;
}

int pressure_init()
{
	pinMode(PRESSURE_GPIO, INPUT);
    pinMode(PRESSURE_SCK, OUTPUT);
    digitalWrite(PRESSURE_SCK, LOW);
	calibrate_tare();
}

device pressure = {
	.device_name = PRESSURE_NAME,
	.init 		 = pressure_init,
	.read_status = pressure_read_status
};

device* PutPressureInLink(device *head)
{	
	pressure.next = head->next;
	head->next = &pressure;
	return head;
}