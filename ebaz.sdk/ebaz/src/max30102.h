/*
 * max30102.h
 *
 *  Created on: 2023��5��22��
 *      Author: slcomplex
 */

#ifndef SRC_MAX30102_H_
#define SRC_MAX30102_H_

#include <stdio.h>
#include "xparameters.h"
#include "xiicps.h"
#include "sleep.h"

XIicPs InstancePtr;

void max30102_init();
float max30102_get();

#endif /* SRC_MAX30102_H_ */
