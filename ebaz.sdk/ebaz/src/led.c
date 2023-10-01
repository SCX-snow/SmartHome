/*
 * led.c
 *
 *  Created on: 2023年5月17日
 *      Author: slcomplex
 */
#include "led.h"

static XSpiPs SpiInstance;

void Lcd_Gpio_Init(){
	XGpioPs_Config *ConfigPtr;
	ConfigPtr = XGpioPs_LookupConfig(GPIO_DEVICE_ID);
	XGpioPs_CfgInitialize(&Gpio, ConfigPtr,ConfigPtr->BaseAddr);
	for(int tmp=54;tmp<63;tmp++){
		XGpioPs_SetDirectionPin(&Gpio, tmp, 0);
	}
	XGpioPs_SetDirectionPin(&Gpio, 67, 0);
	for(int tmp=63;tmp<70;tmp++){
		if(tmp!=67){
			XGpioPs_SetDirectionPin(&Gpio, tmp, 1);
		XGpioPs_SetOutputEnablePin(&Gpio, tmp, 1);
		XGpioPs_WritePin(&Gpio, tmp, 0);
		}
	}
}

void Lcd_Spi_Init(){
	XSpiPs_Config *SpiConfig;
	SpiConfig = XSpiPs_LookupConfig(SPI_DEVICE_ID);
	XSpiPs_CfgInitialize(&SpiInstance, SpiConfig, SpiConfig->BaseAddress);
	XSpiPs_SetOptions(&SpiInstance, XSPIPS_MASTER_OPTION | XSPIPS_FORCE_SSELECT_OPTION);
	XSpiPs_SetClkPrescaler(&SpiInstance, XSPIPS_CLK_PRESCALE_64);
}

void LCD_WR_DATA8(u8 dat){
	XGpioPs_WritePin(&Gpio, EMIO_DC, 1);
	XSpiPs_PolledTransfer(&SpiInstance, &dat, NULL, 1);
}

void LCD_WR_REG(u8 dat){
	XGpioPs_WritePin(&Gpio, EMIO_DC, 0);
	XSpiPs_PolledTransfer(&SpiInstance, &dat, NULL, 1);
}

void Lcd_Init(void){
	XGpioPs_WritePin(&Gpio, EMIO_RES, 0);
	usleep(20000);
	XGpioPs_WritePin(&Gpio, EMIO_RES, 1);
	usleep(20000);
	LCD_WR_REG(0x36);
	LCD_WR_DATA8(0x00);
	LCD_WR_REG(0x3A);
	LCD_WR_DATA8(0x05);
	LCD_WR_REG(0xB2);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x33);
	LCD_WR_DATA8(0x33);
	LCD_WR_REG(0xB7);
	LCD_WR_DATA8(0x35);
	LCD_WR_REG(0xBB);
	LCD_WR_DATA8(0x19);
	LCD_WR_REG(0xC0);
	LCD_WR_DATA8(0x2C);
	LCD_WR_REG(0xC2);
	LCD_WR_DATA8(0x01);
	LCD_WR_REG(0xC3);
	LCD_WR_DATA8(0x12);
	LCD_WR_REG(0xC4);
	LCD_WR_DATA8(0x20);
	LCD_WR_REG(0xC6);
	LCD_WR_DATA8(0x0F);
	LCD_WR_REG(0xD0);
	LCD_WR_DATA8(0xA4);
	LCD_WR_DATA8(0xA1);
	LCD_WR_REG(0xE0);
	LCD_WR_DATA8(0xD0);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x11);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x2B);
	LCD_WR_DATA8(0x3F);
	LCD_WR_DATA8(0x54);
	LCD_WR_DATA8(0x4C);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x0B);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x23);
	LCD_WR_REG(0xE1);
	LCD_WR_DATA8(0xD0);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x11);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x2C);
	LCD_WR_DATA8(0x3F);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x51);
	LCD_WR_DATA8(0x2F);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x20);
	LCD_WR_DATA8(0x23);
	LCD_WR_REG(0x21);
	LCD_WR_REG(0x11);
	LCD_WR_REG(0x29);
	LCD_Fill(0,0,240,240,BLACK);
}

void LCD_WR_DATA(u16 dat)
{
	u8 spi_dat[2];
	XGpioPs_WritePin(&Gpio, EMIO_DC, 1);
    spi_dat[0]=dat>>8;
    spi_dat[1]=dat;
    XSpiPs_PolledTransfer(&SpiInstance, spi_dat, NULL, 2);
}

void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
   LCD_WR_REG(0x2a);
   LCD_WR_DATA8(x1>>8);
   LCD_WR_DATA8(x1);
   LCD_WR_DATA8(x2>>8);
   LCD_WR_DATA8(x2);
   LCD_WR_REG(0x2b);
   LCD_WR_DATA8(y1>>8);
   LCD_WR_DATA8(y1);
   LCD_WR_DATA8(y2>>8);
   LCD_WR_DATA8(y2);
   LCD_WR_REG(0x2C);
}

void LCD_DrawPoint(u16 x,u16 y,u16 color)
{
	Address_set(x,y,x,y);
	LCD_WR_DATA(color);
}

void LCD_ShowChinese32x32(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//汉字数目
	u16 TypefaceNum;//一个字符所占字节大小
	u16 x0=x;
  TypefaceNum=(32/8+((32%8)?1:0))*32;
	HZnum=sizeof(tfont32)/sizeof(typFNT_GB32);	//统计汉字数目
	for(k=0;k<HZnum;k++)
	{
		if ((tfont32[k].Index[0]==*(s))&&(tfont32[k].Index[1]==*(s+1)))
		{
			Address_set(x,y,x+32-1,y+32-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{
					if(!mode)//非叠加方式
					{
						if(tfont32[k].Msk[i]&(0x01<<j))LCD_WR_DATA(fc);
						else LCD_WR_DATA(bc);
						m++;
						if(m%32==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont32[k].Msk[i]&(0x01<<j))LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==32)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}
		continue;
	}
}

void LCD_ShowChinese(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 mode)
{
	while(*s!=0)
	{
		LCD_ShowChinese32x32(x,y,s,fc,bc,mode);
		s+=2;
		x+=32;
	}
}

void LCD_ShowChar(u16 x,u16 y,u8 num,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 temp,sizex,t,m=0;
	u16 i,TypefaceNum;//一个字符所占字节大小
	u16 x0=x;
	sizex=sizey/2;
	TypefaceNum=(sizex/8+((sizex%8)?1:0))*sizey;
	num=num-' ';    //得到偏移后的值
	Address_set(x,y,x+sizex-1,y+sizey-1);  //设置光标位置
	for(i=0;i<TypefaceNum;i++)
	{
		if(sizey==12)temp=ascii_1206[num][i];		       //调用6x12字体
		else if(sizey==16)temp=ascii_1608[num][i];		 //调用8x16字体
		else if(sizey==24)temp=ascii_2412[num][i];		 //调用12x24字体
		else if(sizey==32)temp=ascii_3216[num][i];		 //调用16x32字体
		else return;
		for(t=0;t<8;t++)
		{
			if(!mode)//非叠加模式
			{
				if(temp&(0x01<<t))LCD_WR_DATA(fc);
				else LCD_WR_DATA(bc);
				m++;
				if(m%sizex==0)
				{
					m=0;
					break;
				}
			}
			else//叠加模式
			{
				if(temp&(0x01<<t))LCD_DrawPoint(x,y,fc);//画一个点
				x++;
				if((x-x0)==sizex)
				{
					x=x0;
					y++;
					break;
				}
			}
		}
	}
}

void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	while(*p!='\0')
	{
		LCD_ShowChar(x,y,*p,fc,bc,sizey,mode);
		x+=sizey/2;
		p++;
	}
}

u32 mypow(u8 m,u8 n)
{
	u32 result=1;
	while(n--)result*=m;
	return result;
}

void LCD_ShowIntNum(u16 x,u16 y,u16 num,u8 len,u16 fc,u16 bc,u8 sizey)
{
	u8 t,temp;
	u8 enshow=0;
	u8 sizex=sizey/2;
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+t*sizex,y,' ',fc,bc,sizey,0);
				continue;
			}else enshow=1;

		}
	 	LCD_ShowChar(x+t*sizex,y,temp+48,fc,bc,sizey,0);
	}
}

void LCD_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u16 fc,u16 bc,u8 sizey)
{
	u8 t,temp,sizex;
	u16 num1;
	sizex=sizey/2;
	num1=num*100;
	for(t=0;t<len;t++)
	{
		temp=(num1/mypow(10,len-t-1))%10;
		if(t==(len-2))
		{
			LCD_ShowChar(x+(len-2)*sizex,y,'.',fc,bc,sizey,0);
			t++;
			len+=1;
		}
	 	LCD_ShowChar(x+t*sizex,y,temp+48,fc,bc,sizey,0);
	}
}

void LCD_ShowPicture(u16 x,u16 y,u16 length,u16 width,const u8 pic[])
{
	u16 i,j;
	u32 k=0;
	Address_set(x,y,x+length-1,y+width-1);
	for(i=0;i<length;i++)
	{
		for(j=0;j<width;j++)
		{
			LCD_WR_DATA8(pic[k*2]);
			LCD_WR_DATA8(pic[k*2+1]);
			k++;
		}
	}
}

void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{
	u16 i,j;
	Address_set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{
		for(j=xsta;j<xend;j++)
		{
			LCD_WR_DATA(color);
		}
	}
}
