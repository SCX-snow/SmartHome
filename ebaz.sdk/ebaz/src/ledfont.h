/*
 * ledfont.h
 *
 *  Created on: 2023Äê5ÔÂ17ÈÕ
 *      Author: slcomplex
 */

#ifndef SRC_LEDFONT_H_
#define SRC_LEDFONT_H_

extern const unsigned char ascii_1206[][12];
extern const unsigned char ascii_1608[][16];
extern const unsigned char ascii_2412[][48];
extern const unsigned char ascii_3216[][64];

typedef struct
{
	unsigned char Index[2];
	unsigned char Msk[128];
}typFNT_GB32;

extern const unsigned char pic[8192];
extern const typFNT_GB32 tfont32[25];

#endif /* SRC_LEDFONT_H_ */
