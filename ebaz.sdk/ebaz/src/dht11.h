/*
 * dht11.h
 *
 *  Created on: 2023Äê5ÔÂ22ÈÕ
 *      Author: slcomplex
 */

#ifndef SRC_DHT11_H_
#define SRC_DHT11_H_

#include "xparameters.h"
#include "xgpio.h"
#include "xil_printf.h"
#include "sleep.h"

XGpio AXIGpio;
extern int temi,weti;
extern int temf,wetf;

void dht11_init();
void DHT11_Read_Data();
#endif /* SRC_DHT11_H_ */
