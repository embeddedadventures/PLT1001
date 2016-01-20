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

#ifndef __PLT1001-I2C_h
#define __PLT1001-I2C_h

#define uns8  unsigned char
#define uns16 unsigned int
#define PLT1001_ADDR	0x20
#define delayTime		5
#define TEXT_DELAY		10	

class PLT1001v2Class {
private:
	uns8	fontType;
	
public:
	void 	title();
	double	version();
	char* 	board();
	int 	numDisplays();
	void 	paint();
	void 	clear();
	void 	enableActive(uns8 en);
	void 	setDisplays(uns8 n);
	void 	test(uns8 test);
	void 	invert(uns8 i);
	void 	setBrightness(uns8 level);
	void 	setFont(uns8 font);
	void 	setScrollspeed(uns8 speed);
	void 	pixel(uns8 color, uns16 x, uns16 y);
	void 	circle(uns8 color, uns16 x, uns16 y, uns8 radius);
	void 	filledCircle(uns8 color, uns16 x, uns16 y, uns8 radius);
	void 	circle2(uns8 color, uns16 x, uns16 y, uns8 radius);
	void 	filledCircle2(uns8 color, uns16 x, uns16 y, uns8 radius);
	void 	line(uns8 color, uns16 x1, uns16 y1, uns16 x2, uns16 y2);
	void 	rectangle(uns8 color, uns16 x1, uns16 y1, uns16 x2, uns16 y2);
	void 	text(uns8 color, uns16 x, uns16 y, char* text);
	void 	text(uns8 color, uns16 x, uns16 y, const char* text);
	void 	text(uns8 color, uns16 x, uns16 y, String text);
	void 	text(uns8 color, uns16 x, uns16 y, uns8 text);
	void 	text_rightJustified(uns8 color, uns16 x, uns16 y, char* text);
	void 	text_centerJustified(uns8 color, uns16 x, uns16 y, char* text);
	void 	text_vertical(uns8 color, uns16 x, uns16 y, char* text);
	void 	text_column(uns8 color, uns16 x, uns16 y, char* text);
	void 	text_vertColumn(uns8 color, uns16 x, uns16 y, char* text);
	void 	scroll(uns8 color, uns16 x, uns16 y, uns16 wd, uns16 ht, char* text);
	//void 	scrollVertical(uns8 color, uns16 x, uns16 y, uns16 ht, uns16 wd, char* text);
	//void 	scrollColumn(uns8 color, uns16 x, uns16 y, uns16 ht, uns16 wd, char* text);
	void 	scrollVerticalColumn(uns8 color, uns16 x, uns16 y, uns16 ht, uns16 wd, char* text);
	void 	scrollStop();
	uns8	status();
};

extern PLT1001v2Class plt1001;


#endif