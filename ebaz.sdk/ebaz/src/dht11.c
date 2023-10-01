/*
 * dht11.c
 *
 *  Created on: 2023年5月22日
 *      Author: slcomplex
 */


#include "dht11.h"

int temi=0;
int temf=0;
int weti=0;
int wetf=0;

void dht11_init(){
	XGpio_Initialize(&AXIGpio, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_SetDataDirection(&AXIGpio, 1, 0);
	XGpio_DiscreteWrite(&AXIGpio, 1, 0x1);
}
u8 DHT11_Check(void)
{
	u8 retry=0;
	XGpio_SetDataDirection(&AXIGpio, 1, 1);//SET INPUT
    while (XGpio_DiscreteRead(&AXIGpio, 1)&&retry<100)//DHT11会拉低40~80us
	{
		retry++;
		usleep(1);
	};
	if(retry>=100)return 1;
	else retry=0;
    while (!XGpio_DiscreteRead(&AXIGpio, 1)&&retry<100)//DHT11拉低后会再次拉高40~80us
	{
		retry++;
		usleep(1);
	};
	if(retry>=100)return 1;
	return 0;
}
u8 DHT11_Read_Bit(){
	u8 retry=0;
	while(XGpio_DiscreteRead(&AXIGpio, 1)&&retry<100)//等待变为低电平
		{
			retry++;
			usleep(1);
		}
		retry=0;
		while(!XGpio_DiscreteRead(&AXIGpio, 1)&&retry<100)//等待变高电平
		{
			retry++;
			usleep(1);
		}
		usleep(40);//等待40us
		if(XGpio_DiscreteRead(&AXIGpio, 1))return 1;
		else return 0;
}
u8 DHT11_Read_Byte(void)
{
    u8 i,dat;
    dat=0;
	for (i=0;i<8;i++)
	{
   		dat<<=1;
	    dat|=DHT11_Read_Bit();
    }
    return dat;
}
void DHT11_Read_Data()
{
 	u8 buf[5];
	u8 i;
	XGpio_SetDataDirection(&AXIGpio, 1, 0);
	XGpio_DiscreteWrite(&AXIGpio, 1, 0x0);
	usleep(20000);
	XGpio_DiscreteWrite(&AXIGpio, 1, 0x1);
	usleep(30);
	if(DHT11_Check()==0)
	{
		for(i=0;i<5;i++)//读取40位数据
		{
			buf[i]=DHT11_Read_Byte();
		}
		if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
		{
			weti=buf[0];
			wetf=buf[1];
			temi=buf[2];
			temf=buf[3];
		}
	}
}
