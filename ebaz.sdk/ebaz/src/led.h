/*
 * led.h
 *
 *  Created on: 2023��5��17��
 *      Author: slcomplex
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_


#include "xparameters.h"
#include "xgpiops.h"
#include "xspips.h"
#include "xstatus.h"
#include "xplatform_info.h"
#include <xil_printf.h>
#include "ledfont.h"
#include "sleep.h"

#define EMIO_DC 68
#define EMIO_RES 69
#define SPI_DEVICE_ID XPAR_XSPIPS_0_DEVICE_ID
#define GPIO_DEVICE_ID XPAR_XGPIOPS_0_DEVICE_ID
#define WHITE	0xFFFF
#define BLACK	0x0000
#define BLUE	0x001F
#define BRED	0XF81F
#define GRED	0XFFE0
#define GBLUE	0X07FF
#define RED	0xF800
#define MAGENTA	0xF81F
#define GREEN	0x07E0
#define CYAN	0x7FFF
#define YELLOW	0xFFE0
#define BROWN	0XBC40 //��ɫ
#define BRRED	0XFC07 //�غ�ɫ
#define GRAY	0X8430 //��ɫ
#define DARKBLUE	0X01CF	//����ɫ
#define LIGHTBLUE	0X7D7C	//ǳ��ɫ
#define GRAYBLUE	0X5458 //����ɫ
#define LIGHTGREEN	0X841F //ǳ��ɫ
#define LGRAY	0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ
#define LGRAYBLUE	0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE	0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

XGpioPs Gpio;

void Lcd_Gpio_Init();
void Lcd_Spi_Init();
void Lcd_Init();
void LCD_ShowChinese(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 mode);
void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);
void LCD_ShowIntNum(u16 x,u16 y,u16 num,u8 len,u16 fc,u16 bc,u8 sizey);
void LCD_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u16 fc,u16 bc,u8 sizey);
void LCD_ShowPicture(u16 x,u16 y,u16 length,u16 width,const u8 pic[]);

#endif /* SRC_LED_H_ */
