/*
 * main.c
 *
 *  Created on: 2023年5月17日
 *      Author: slcomplex
 */


#include "led.h"
#include "dht11.h"
#include "max30102.h"


#define EMIO_FIRE 54
#define EMIO_HUMAN 55
#define EMIO_KEY1 56
#define EMIO_KEY2 57
#define EMIO_KEY3 58
#define EMIO_KEY4 59
#define EMIO_KEY5 60
#define EMIO_MQ2 61
#define EMIO_MQ9 62
#define EMIO_ENABLE 63
#define EMIO_LED1 64
#define EMIO_LED2 65
#define EMIO_LED3 66
#define EMIO_MAXINT 67

int main()
{
	float tem=0,wet=0,ox=0;
	int buzzerenable=1,buzzer=0,fire=0,smoke=0,gas=0,human=0,humancheck=0,oxsum=0;
	Lcd_Gpio_Init();
	Lcd_Spi_Init();
	dht11_init();
	Lcd_Init();
	LCD_ShowPicture(0,0,64,64,pic);
	LCD_ShowChinese(64,0,(unsigned char*)"孙利诚",WHITE,BLACK,0);
	LCD_ShowString(64,32,(unsigned char*)"20009101212",BLUE,BLACK,32,0);
	LCD_ShowChinese(0,64,(unsigned char*)"温度",BLUE,BLACK,0);
	LCD_ShowFloatNum1(70,64,tem,4,GREEN,BLACK,32);
	LCD_ShowChinese(160,64,(unsigned char*)"℃",BLUE,BLACK,0);
	LCD_ShowChinese(0,96,(unsigned char*)"湿度",BLUE,BLACK,0);
	LCD_ShowFloatNum1(70,96,wet,4,GREEN,BLACK,32);
	LCD_ShowChinese(0,128,(unsigned char*)"血氧",BLUE,BLACK,0);
	LCD_ShowString(70,128,(unsigned char*)"=",BLUE,BLACK,32,0);
	LCD_ShowChinese(0,160,(unsigned char*)"蜂鸣器",BLUE,BLACK,0);
	LCD_ShowChinese(100,160,(unsigned char*)"允许",WHITE,BLACK,0);
	LCD_ShowChinese(176,176,(unsigned char*)"人员",GRAY,BLACK,0);
	max30102_init();
	LCD_ShowFloatNum1(70,128,ox,4,GRAY,BLACK,32);
    while(1)
    {
    	if(!XGpioPs_ReadPin(&Gpio,EMIO_KEY2)){
    		buzzerenable=0;
    		buzzer=0;
    	}
    	if(!XGpioPs_ReadPin(&Gpio,EMIO_KEY5))
    	    buzzerenable=1;
    	if(!XGpioPs_ReadPin(&Gpio,EMIO_KEY4)){
    	    humancheck=0;
    	    human=0;
    	}
    	if(!XGpioPs_ReadPin(&Gpio,EMIO_KEY1))
    	    humancheck=1;
    	if(!XGpioPs_ReadPin(&Gpio,EMIO_FIRE))
    		fire=1;
    	else
    		fire=0;
    	if(!XGpioPs_ReadPin(&Gpio,EMIO_MQ2))
    		smoke=1;
    	else
    		smoke=0;
    	if(!XGpioPs_ReadPin(&Gpio,EMIO_MQ9))
    		gas=1;
    	else
    		gas=0;
    	if(humancheck)
    		if(!XGpioPs_ReadPin(&Gpio,EMIO_HUMAN))
    			human=1;
    	if(XGpioPs_ReadPin(&Gpio,EMIO_HUMAN))
    	    	human=0;
    	if(fire||smoke||gas||human)
    		if(buzzerenable)
    			buzzer=1;
    	if(!fire&&!smoke&&!gas&&!human)
    		buzzer=0;
    	if(!XGpioPs_ReadPin(&Gpio,EMIO_KEY3)){
    		int tmp = max30102_get();
    		if(tmp>50){
    			ox=(ox*oxsum+tmp)/(oxsum+1);
    			if(ox<80)
    			    LCD_ShowFloatNum1(70,128,ox,4,RED,BLACK,32);
    			else if(ox<90)
    			    LCD_ShowFloatNum1(70,128,ox,4,YELLOW,BLACK,32);
    			else
    			    LCD_ShowFloatNum1(70,128,ox,4,GREEN,BLACK,32);
    			oxsum++;
    			if(oxsum>254)
    				oxsum=1;
    		}
    	}
    	else{
    		oxsum=0;
    		LCD_ShowFloatNum1(70,128,ox,4,WHITE,BLACK,32);
    	}
    	DHT11_Read_Data();
    	tem=((temi<<8)+temf)/10.0;
    	wet=((weti<<8)+wetf)/10.0;
    	LCD_ShowFloatNum1(70,64,tem,4,GREEN,BLACK,32);
    	LCD_ShowFloatNum1(70,96,wet,4,GREEN,BLACK,32);
    	if(humancheck)
    		if(human)
    			LCD_ShowChinese(176,176,(unsigned char*)"人员",RED,BLACK,0);
    		else
    			LCD_ShowChinese(176,176,(unsigned char*)"人员",GREEN,BLACK,0);
    	else
    		LCD_ShowChinese(176,176,(unsigned char*)"人员",GRAY,BLACK,0);
    	if(smoke)
    		LCD_ShowChinese(0,208,(unsigned char*)"烟雾",RED,BLACK,0);
    	else
    		LCD_ShowChinese(0,208,(unsigned char*)"烟雾",BLACK,BLACK,0);
    	if(fire)
    		LCD_ShowChinese(88,208,(unsigned char*)"火焰",RED,BLACK,0);
    	else
    		LCD_ShowChinese(88,208,(unsigned char*)"火焰",BLACK,BLACK,0);
    	if(gas)
    		LCD_ShowChinese(176,208,(unsigned char*)"燃气",RED,BLACK,0);
    	else
    		LCD_ShowChinese(176,208,(unsigned char*)"燃气",BLACK,BLACK,0);
    	if(buzzer)
    		XGpioPs_WritePin(&Gpio,EMIO_ENABLE,1);
    	else
    		XGpioPs_WritePin(&Gpio,EMIO_ENABLE,0);
    	if(buzzerenable)
    		LCD_ShowChinese(100,160,(unsigned char*)"允许",WHITE,BLACK,0);
    	else
    		LCD_ShowChinese(100,160,(unsigned char*)"禁止",BROWN,BLACK,0);
    }

    return 0;
}
