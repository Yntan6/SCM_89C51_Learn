/*******************************************************************************
* 函 数 名       : SMG_CHOOSE
* 函数功能		 : 数码管位选函数，choose=1时，数码管第二位亮（从左往右）
* 输    入       : choose
* 输    出    	 : 无
*******************************************************************************/


#include<reg52.h>
sbit A1 = P2^2;
sbit B2 = P2^3;
sbit C3 = P2^4;

unsigned char SMG_CHOOSE(unsigned char choose)//数码管选择	/***/	范围：0-7
{
	switch(choose)
	{
//		case 0: A1 = 0; B2 = 0; C3 = 0;break;
//		case 1: A1 = 1; B2 = 0; C3 = 0;break;
//		case 2: A1 = 0; B2 = 1; C3 = 0;break;
//		case 3: A1 = 1; B2 = 1; C3 = 0;break;
//		case 4: A1 = 0; B2 = 0; C3 = 1;break;
//		case 5: A1 = 1; B2 = 0; C3 = 1;break;
//		case 6: A1 = 0; B2 = 1; C3 = 1;break;
//		case 7: A1 = 1; B2 = 1; C3 = 1;break;
//		
		case 0: A1 = 1; B2 = 1; C3 = 1;break;
		case 1: A1 = 0; B2 = 1; C3 = 1;break;
		case 2: A1 = 1; B2 = 0; C3 = 1;break;
		case 3: A1 = 0; B2 = 0; C3 = 1;break;
		case 4: A1 = 1; B2 = 1; C3 = 0;break;
		case 5: A1 = 0; B2 = 1; C3 = 0;break;
		case 6: A1 = 1; B2 = 0; C3 = 0;break;
		case 7: A1 = 0; B2 = 0; C3 = 0;break;
	}
	return choose;
}