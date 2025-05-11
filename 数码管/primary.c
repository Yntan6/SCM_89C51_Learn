/******************************
使用数码管显示班级和学号 
******************************/
#include <reg52.h>
#define uint unsigned int
#define class_id 2403
uint roll[]={2,1,0,2,1,3,3,4};	

sbit A1 = P2^2;
sbit B2 = P2^3;
sbit C3 = P2^4;
sbit fmq = P2^5;

uint delay(uint count);//定义延时函数
uint number[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//数字0到9
uint wei(uint i);//数码管的位选

uint decode_class(uint i)//解码函数 
{
	unsigned int temp;
	switch(i)
	{
		case 1: temp = class_id / 1000;break;			//将2403 除1000，得到的商是2 
		case 2: temp = class_id % 1000 / 100;break;	    // %:将2403除1000 余数是403，再除100得到的商就是4 
		case 3: temp = class_id % 100 / 10;break;		//2403%100=03， 
		case 4: temp = class_id % 10;break;
/*******************************
		 "/"号的结果是商
		 "%"号的结果是余数 
********************************/
		
	}
	return temp;
	
}


void main()
{
	
	while(1)
	{
		uint temp,i,time;
		for(time = 2000;time > 0;time--)
		{
			for(i = 0;i < 4;i++)
			{
				P0 = 0x00;fmq = 0;//数码管消影和蜂鸣器消音
				wei(i);//位选
				temp = decode_class(i+1);
				P0 = number[temp];//段码输出
				delay(1);
			}
		}
		
		P0 = 0x00;P2 = 0xff;fmq = 0;//关闭段码、位码、蜂鸣器
		delay(500);
		
		for(time = 2000;time > 0;time--)
		{
			for(i = 0;i < 8;i++)
			{
				P0 = 0x00;fmq = 0;//数码管消影和蜂鸣器消音
				wei(i);//位选
				temp = roll[i];
				P0 = number[temp];//段码输出
				delay(1);
			}
		}
		P0 = 0x00;P2 = 0xff;fmq = 0;//关闭段码、位码、蜂鸣器
		delay(500);
	}
	
}
uint delay(uint count)
{
	uint i,j;
	for(i = 0;i < count;i++)
	{
		for(j = 0;j < 10;j++);
	}

}

uint wei(uint i)//数码管的位选
{
	switch(i)
	{
		case 0: A1 = 1; B2 = 1; C3 = 1;break;//P0 = 0011 1000 = 0x38
		case 1: A1 = 0; B2 = 1; C3 = 1;break;//P0 = 0001 1000 = 0x18
		case 2: A1 = 1; B2 = 0; C3 = 1;break;//P0 = 0010 1000 = 0x28
		case 3: A1 = 0; B2 = 0; C3 = 1;break;//P0 = 0000 1000 = 0x08
		case 4: A1 = 1; B2 = 1; C3 = 0;break;//P0 = 0011 0000 = 0x30
		case 5: A1 = 0; B2 = 1; C3 = 0;break;//P0 = 0001 0000 = 0x10
		case 6: A1 = 1; B2 = 0; C3 = 0;break;//P0 = 0010 0000 = 0x20
		case 7: A1 = 0; B2 = 0; C3 = 0;break;//P0 = 0000 0000 = 0x00
	}
}
