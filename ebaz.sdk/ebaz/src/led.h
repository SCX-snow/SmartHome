/*
 * led.h
 *
 *  Created on: 2023年5月17日
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
#define BROWN	0XBC40 //棕色
#define BRRED	0XFC07 //棕红色
#define GRAY	0X8430 //灰色
#define DARKBLUE	0X01CF	//深蓝色
#define LIGHTBLUE	0X7D7C	//浅蓝色
#define GRAYBLUE	0X5458 //灰蓝色
#define LIGHTGREEN	0X841F //浅绿色
#define LGRAY	0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE	0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE	0X2B12 //浅棕蓝色(选择条目的反色)

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
