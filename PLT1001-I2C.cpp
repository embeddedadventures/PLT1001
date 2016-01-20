/*

Copyright (c) 2015, Embedded Adventures
All rights reserved.

Contact us at source [at] embeddedadventures.com
www.embeddedadventures.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.

*/

/*	
	PLT1001 LED Matrix display driver Arduino library, using I2C protocol
	Written originally by Embedded Adventures
	v1.1 - displays() function added  
*/

#include "Arduino.h"
#include "Wire.h"
#include "PLT1001-I2C.h"

void PLT1001v2Class::title() {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x00);
	Wire.endTransmission();
	delay(TEXT_DELAY*5);
}

double PLT1001v2Class::version() {
	uns8 x, y;
	double result;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x01);
	Wire.endTransmission();
	delay(TEXT_DELAY);
	Wire.requestFrom(PLT1001_ADDR, 2);
	if (Wire.available()) {
		x = Wire.read();
		y = Wire.read();
	}
	result = (double)((x * 100) + y) / 100;
	return result;
}

char* PLT1001v2Class::board() {
	uns8 result;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x02);
	Wire.endTransmission();
	delay(TEXT_DELAY);
	Wire.requestFrom(PLT1001_ADDR, 1);
	if (Wire.available()) {
		result = Wire.read();
	}
	
	switch (result) {
		case 1:
			return "LDP8008";
			break;
		case 2:
			return "LDP6416";
			break;
		case 3:
			return "LDP6432";
			break;
		case 4:
			return "LDP6408";
			break;
		case 5:
			return "LDP6432-RED";
			break;
		case 6:
			return "LDP3208-S";
			break;
		case 7:
			return "LDP3216-S";
			break;
		case 8:
			return "LDP080507-R";
			break;
	}
}

int PLT1001v2Class::numDisplays() {
	int num;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x03);
	Wire.endTransmission();
	delay(TEXT_DELAY);
	Wire.requestFrom(PLT1001_ADDR, 1);
	if (Wire.available())
		num = Wire.read();
	return num;
}

void PLT1001v2Class::paint() {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x04);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::clear() {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x05);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::enableActive(uns8 en) {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x06);
	Wire.write(en);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::setDisplays(uns8 n) {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x07);
	Wire.write(n);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::test(uns8 test) {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x08);
	Wire.write(test);
	Wire.endTransmission();
	
}

void PLT1001v2Class::invert(uns8 i) {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x09);
	Wire.write(i);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::setBrightness(uns8 level) {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0A);
	Wire.write(level);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::setFont(uns8 font) {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0B);
	Wire.write(font);
	Wire.endTransmission();
	delay(delayTime);
	fontType = font;
}

void PLT1001v2Class::setScrollspeed(uns8 speed) {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0C);
	Wire.write(speed);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::pixel(uns8 color, uns16 x, uns16 y) {
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0D);
	Wire.write(color);
	Wire.write(x >> 8);		//Send x high byte
	Wire.write(x);			//Send x low byte
	Wire.write( y >> 8);	//Send y high byte
	Wire.write(y);			//Send y low byte
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::circle(uns8 color, uns16 x, uns16 y, uns8 radius) {
	color |= 0x10;			//Normal circle condition
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0E);
	Wire.write(color);
	Wire.write(x >> 8);		//Send x high byte
	Wire.write(x);			//Send x low byte
	Wire.write( y >> 8);	//Send y high byte
	Wire.write(y);			//Send y low byte
	Wire.write(radius);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::filledCircle(uns8 color, uns16 x, uns16 y, uns8 radius) {
	color |= 0x20;			//Filled circle condition
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0E);
	Wire.write(color);
	Wire.write(x >> 8);		//Send x high byte
	Wire.write(x);			//Send x low byte
	Wire.write(y >> 8);	//Send y high byte
	Wire.write(y);			//Send y low byte
	Wire.write(radius);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::circle2(uns8 color, uns16 x, uns16 y, uns8 radius) {
	color |= 0x30;			//Squared circle condition
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0E);
	Wire.write(color);
	Wire.write(x >> 8);		//Send x high byte
	Wire.write(x);			//Send x low byte
	Wire.write(y >> 8);	//Send y high byte
	Wire.write(y);			//Send y low byte
	Wire.write(radius);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::filledCircle2(uns8 color, uns16 x, uns16 y, uns8 radius) {
	color |= 0x40;			//Filled squared circle condition
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0E);
	Wire.write(color);
	Wire.write(x >> 8);		//Send x high byte
	Wire.write(x);			//Send x low byte
	Wire.write(y >> 8);	//Send y high byte
	Wire.write(y);			//Send y low byte
	Wire.write(radius);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::line(uns8 color, uns16 x1, uns16 y1, uns16 x2, uns16 y2) {
	color &= 0x0F;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0F);
	Wire.write(color);
	Wire.write((x1 >> 8));
	Wire.write(x1);
	Wire.write((y1 >> 8));
	Wire.write(y1);
	Wire.write((x2 >> 8));
	Wire.write(x2);
	Wire.write((y2 >> 8));
	Wire.write(y2);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::rectangle(uns8 color, uns16 x1, uns16 y1, uns16 x2, uns16 y2) {
	color &= 0x0F;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x0F);
	Wire.write((color | 0x10));
	Wire.write(x1 >> 8);
	Wire.write(x1);
	Wire.write(y1 >> 8);
	Wire.write(y1);
	Wire.write(x2 >> 8);
	Wire.write(x2);
	Wire.write(y2 >> 8);
	Wire.write(y2);
	Wire.endTransmission();
	delay(delayTime);
}

void PLT1001v2Class::text(uns8 color, uns16 x, uns16 y, char* text) {
	color |= 0x10;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(TEXT_DELAY + 2);
	else	
		delay(TEXT_DELAY);
}

void PLT1001v2Class::text(uns8 color, uns16 x, uns16 y, const char* text) {
	color |= 0x10;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(TEXT_DELAY + 2);
	else	
		delay(TEXT_DELAY);
}

/*
*	x, y are the coordinates of the bottom left corner where text starts
*/
void PLT1001v2Class::text(uns8 color, uns16 x, uns16 y, String text) {
	color |= 0x10;
	const char* cText = text.c_str();
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(cText);
	Wire.endTransmission();
	if (fontType == 7)
		delay(TEXT_DELAY + 2);
	else	
		delay(TEXT_DELAY);
}

/*
*	x, y are the coordinates of the bottom left corner where text starts
*/
void PLT1001v2Class::text(uns8 color, uns16 x, uns16 y, uns8 text) {
	color |= 0x10;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(delayTime + 2);
	else	
		delay(delayTime);
}

/*
*	x, y are the coordinates of the bottom right corner where text ends
*/
void PLT1001v2Class::text_rightJustified(uns8 color, uns16 x, uns16 y, char* text) {
	color |= 0x20;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(TEXT_DELAY + 2);
	else	
		delay(TEXT_DELAY);
}

/*
*	x, y are the coordinates of the center of the text
*/
void PLT1001v2Class::text_centerJustified(uns8 color, uns16 x, uns16 y, char* text) {
	color |= 0x30;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(TEXT_DELAY + 2);
	else	
		delay(TEXT_DELAY);
}

void PLT1001v2Class::text_vertical(uns8 color, uns16 x, uns16 y, char* text) {
	color |= 0x40;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(TEXT_DELAY + 2);
	else	
		delay(TEXT_DELAY);
}

void PLT1001v2Class::text_column(uns8 color, uns16 x, uns16 y, char* text) {
	color |= 0x50;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(TEXT_DELAY + 2);
	else	
		delay(TEXT_DELAY);
}

void PLT1001v2Class::text_vertColumn(uns8 color, uns16 x, uns16 y, char* text) {
	color |= 0x60;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x10);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(TEXT_DELAY + 2);
	else	
		delay(TEXT_DELAY);
}


void PLT1001v2Class::scroll(uns8 color, uns16 x, uns16 y, uns16 wd, uns16 ht, char* text) {
	color &= 0x0F;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x11);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(ht >> 8);
	Wire.write(ht);
	Wire.write(wd >> 8);
	Wire.write(wd);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(delayTime + 2);
	else	
		delay(delayTime);
}

void PLT1001v2Class::scrollVertical(uns8 color, uns16 x, uns16 y, uns16 wd, uns16 ht, char* text) {
	color |= 0x10;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x11);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(ht >> 8);
	Wire.write(ht);
	Wire.write(wd >> 8);
	Wire.write(wd);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(delayTime + 2);
	else	
		delay(delayTime);
}

void PLT1001v2Class::scrollColumn(uns8 color, uns16 x, uns16 y, uns16 wd, uns16 ht, char* text) {
	color |= 0x20;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x11);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(ht >> 8);
	Wire.write(ht);
	Wire.write(wd >> 8);
	Wire.write(wd);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(delayTime + 2);
	else	
		delay(delayTime);
}

void PLT1001v2Class::scrollVerticalColumn(uns8 color, uns16 x, uns16 y, uns16 wd, uns16 ht, char* text) {
	color |= 0x30;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x11);
	Wire.write(color);
	Wire.write(x >> 8);
	Wire.write(x);
	Wire.write(y >> 8);
	Wire.write(y);
	Wire.write(ht >> 8);
	Wire.write(ht);
	Wire.write(wd >> 8);
	Wire.write(wd);
	Wire.write(text);
	Wire.endTransmission();
	if (fontType == 7)
		delay(delayTime + 2);
	else	
		delay(delayTime);
}

void PLT1001v2Class::scrollStop() {
	Serial.println("stop begin");
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x12);
	Wire.endTransmission();
	Serial.println("stop end");
}

uns8 PLT1001v2Class::status() {
	uns8 response;
	Wire.beginTransmission(PLT1001_ADDR);
	Wire.write(0x13);
	Wire.endTransmission();
	
	Wire.requestFrom(PLT1001_ADDR, 1);
	if (Wire.available()) {
		response = Wire.read();
	}
	delay(5);
	return response;
}

PLT1001v2Class plt1001;
