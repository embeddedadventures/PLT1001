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

/*	PLT1001 LED Matrix display driver Arduino library
	Written originally by Embedded Adventures
	v1.0 
*/


#ifndef __PLT1001_H
#define __PLT1001_H
#include "HardwareSerial.h"
#define DELAY_TIME 20

class PLT1001Class
{
private:
	HardwareSerial *mySerial;

public:
	/*Initialize the plt1001 class. In .ino, use plt1001.init(&Serial1)*/
	void init(HardwareSerial *cereal);		
	
	void end();
	
	void enableHigh();
	
	void enableLow();
	
	/*Clear the display*/
	void clear();
	
	/*Illuminate a pixel. (0,0) for x,y is the top left corner*/
	void pixel(int color, int x, int y);
	
	/*Draw a line from x1,y1 to x2,y2*/
	void line(int color, int x1, int y1, int x2, int y2);

	/*Draw a rectangle*/
	void rect(int color, int x, int y, int wt, int ht);
	
	/*Draw a circle with center x,y and radius*/
	void circle(int color, int x, int y, int radius);
	
	/*Draw a filled circle*/
	void circlef(int color, int x, int y, int radius);
	
	/*Draw a "squared" circle; an extra pixel inserted at top and side to completely fill a square space*/
	void circle2(int color, int x, int y, int radius);
	
	/*Set font to one of 7 types*/
	void font(int font);
	
	/*Print text. Bottom left corner of text starts at x,y*/
	void text(int color, int x, int y, char *str);
	
	void textv(int color, int x, int y, char *str);
	
	/*Print text that scrolls in a rectangle. Bottom left of rectangle starts at x,y. Height determined by font*/
	void scroll(int color, int x, int y, int width, char *str);
	
	/*Change scroll speed. spd = ms per change*/
	void scrollspeed(int spd);

	/*Display the version number*/
	void title();
	
	void displays();

	void paint();
};

extern PLT1001Class plt1001;

#endif