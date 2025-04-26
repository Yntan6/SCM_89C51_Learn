#include <reg52.h>
#include "SMG_CHOOSE.h"			//数码管位选：0-7

sbit key_add = P3^1;//独立按键K1控制加1
sbit key_sub = P3^0;//独立按键控K2制减1

unsigned char code DuanMa[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//数码管段选显示
	
void delay(unsigned int t);//延时函数
void display(unsigned char disum);//显示函数

void main()
{
	unsigned int num = 0;
	while(1)
	{
		if(key_add == 0)//判断按键是否按下
		{
			delay(1250);//消抖
			if(key_add == 0)//再次判断按键是否按下
			{
				while(key_add == 0)//等待按键释放
				{
					display(num);
				}
				delay(1250);
				num++;
				if(num==100)//我们只控制两位数的显示，当到达99时，下一位归零
				{
					num = 0;
				}
			}
		}
		
		display(num);//避免只有按下时才显示的情况
		
		if(key_sub == 0)
		{
			delay(1250);//消抖
			if(key_sub == 0)//再次判断按键是否按下
			{
				while(key_sub == 0)//等待按键释放
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
	shi = disum/10;//余上10，得十位
	ge = disum%10;//模上10，得个位
	
	SMG_CHOOSE(0);//位码
	P0 = DuanMa[shi];//余上10，得十位
	delay(100);
	P0 = 0x00;//消影
	
	SMG_CHOOSE(1);//位码
	P0 = DuanMa[ge];//模上10，得个位
	delay(100);
	P0 = 0x00;//消影
}


