# 📱数码管动态显示📱
## 思路：

利用视觉暂留实现`一串数字`在显示的错觉
- 选择第一个数码管，一般我们称之为"`位`"
- 要显示的内容，一般我们称之为"`段`"
- 显示时间
- 消影
---
- 选择第二个数码管
- 要显示的内容
- 显示时间
- 消影

**.......照此循环**
我们就会见到显示的是完整的串数字

---
## 代码预览：

```
/******************************
使用数码管显示班级和学号 
******************************/
#include <reg52.h>
#define uint unsigned int
uint roll[]={2,1,0,2,1,3,3,4};//学号
uint class_id[]={2, 4, 0, 3};//班级

sbit fmq = P2^5;

uint delay(uint count);//定义延时函数
uint number[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};//数字0到9(段选P00-P07)
uint wei[] = {0x1c, 0x18, 0x14, 0x10, 0x0c, 0x08, 0x04, 0x00};//数码管的位选(位选P22-P24)

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
				P2 = wei[i];//位选
				temp = class_id[i];
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
				P2 = wei[i];//位选
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
```
## 分段解释：
```
for(time = 2000;time > 0;time--)        //第一个for循环控制 显示时间
{
	for(i = 0;i < 4;i++)                //第二个for循环控制 循环显示的内容
	{
		P0 = 0x00;fmq = 0;              //数码管消影和蜂鸣器消音
		P2 = wei[i];                    //位选
		temp = class_id[i];             //临时存储代码数据
		P0 = number[temp];              //段码输出
		delay(1);                       //单个数码管的显示时间
	}
}
```
> [!WARNING]
注意要有内外循环
- 内循环：是`一次循环`为输出`某一位数码管的数据`
- 外循环：是这串数据的`显示次数`/`(显示时间)`
- 消影要对段码，不要对位码，可能引起某些错误显示
