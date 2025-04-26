#include <reg52.h>
#include "SMG_CHOOSE.h"			//�����λѡ��0-7

sbit key_add = P3^1;//��������K1���Ƽ�1
sbit key_sub = P3^0;//����������K2�Ƽ�1

unsigned char code DuanMa[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//����ܶ�ѡ��ʾ
	
void delay(unsigned int t);//��ʱ����
void display(unsigned char disum);//��ʾ����

void main()
{
	unsigned int num = 0;
	while(1)
	{
		if(key_add == 0)//�жϰ����Ƿ���
		{
			delay(1250);//����
			if(key_add == 0)//�ٴ��жϰ����Ƿ���
			{
				while(key_add == 0)//�ȴ������ͷ�
				{
					display(num);
				}
				delay(1250);
				num++;
				if(num==100)//����ֻ������λ������ʾ��������99ʱ����һλ����
				{
					num = 0;
				}
			}
		}
		
		display(num);//����ֻ�а���ʱ����ʾ�����
		
		if(key_sub == 0)
		{
			delay(1250);//����
			if(key_sub == 0)//�ٴ��жϰ����Ƿ���
			{
				while(key_sub == 0)//�ȴ������ͷ�
				{
					display(num);
				}
				delay(1250);
				if(num > 0)
				{
					num--;
				}
				else
				{
					num = 99;
				}
			}
		}
		display(num);
		
	}
}


void delay(unsigned int t)
{
	while(--t);
}

void display(unsigned char disum)
{
	unsigned char shi,ge;
	shi = disum/10;//����10����ʮλ
	ge = disum%10;//ģ��10���ø�λ
	
	SMG_CHOOSE(0);//λ��
	P0 = DuanMa[shi];//����10����ʮλ
	delay(100);
	P0 = 0x00;//��Ӱ
	
	SMG_CHOOSE(1);//λ��
	P0 = DuanMa[ge];//ģ��10���ø�λ
	delay(100);
	P0 = 0x00;//��Ӱ
}


