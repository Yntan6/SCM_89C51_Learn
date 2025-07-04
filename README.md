# 个人关于51单片机学习记录          
当我决定写这篇学习笔记时（2025.04.23）我已经断断续续写过不下十次的学习路线笔记，但那些笔记都随风而去了
- **要定下每周更新的决心**
- **实时添加扩展知识**
---
## 模块化编程
**模块化编程**就是将各个功能的代码进行打包，使用时直接拿过来使用，方便调试和维护

**要求**：**<name.h>**和**<name.c>**   

例如：delay作为一个延时函数，使用频率非常高，我们就可以使用模块对其进行打包，不用每次都写一遍

    <name.h>：可被外部调用的函数、变量的声明
    <name.c>：执行的变量、函数
---
**<name.h>code**： 

    #ifndef __DELAY_H__               //规定需要定义的内容，与#endif匹配        
    #define __DELAY_H__               //定义delay    
    
    void delay(unsigned int xms);     //声明函数类型、函数名、函数参数
    
    #endif                            //规定需要定义的内容，与#ifndef匹配    
---
**<name.c>code**：  

    void delay(unsigned int xms)      //可指定毫秒数的延时函数      
    {
     unsigned int k;
     for(k = 0; k < xms; k++)      
     {         
          unsigned char i, j;          //参数根据12MHz晶振由AI生成               
          i = 2;          
          j = 239;        
          do {    
              while (--j);      
          } while (--i);           
      }              
    }
---

## 独立按键
- [独立按键控制数码管进行+1或-1](https://github.com/Yntan6/SCM_89C51_Learn/blob/main/%E7%8B%AC%E7%AB%8B%E6%8C%89%E9%94%AE%E6%8E%A7%E5%88%B6%E4%B8%A4%E4%BD%8D%E6%95%B0%E7%9A%84%C2%B11/README.md)
---
## 动态数码管
- [数码管显示 班级和学号](https://github.com/Yntan6/SCM_89C51_Learn/blob/main/%E6%95%B0%E7%A0%81%E7%AE%A1/Digital_Tube.md)
---
## 定时器/计数器
- [定时器的构成](https://github.com/Yntan6/SCM_89C51_Learn/blob/main/%E5%AE%9A%E6%97%B6%E5%99%A8/timer.md)
- [使用定时精确控制LED的亮灭时间](https://github.com/Yntan6/SCM_89C51_Learn/blob/main/%E5%AE%9A%E6%97%B6%E5%99%A8/timer_code.c)
