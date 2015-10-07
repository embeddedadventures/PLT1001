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


#include "Arduino.h"
#include "PLT1001.h"
#include "HardwareSerial.h"

void PLT1001Class::init(HardwareSerial *cereal) {
	mySerial = cereal;
	mySerial->begin(115200);
	title();
}

void PLT1001Class::enableHigh() {
	mySerial->print("enableactive 1\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::enableLow() {
	mySerial->print("enableactive 0\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::title() {
	mySerial->print("title\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::clear() {
	mySerial->print("clear\r");
	mySerial->print("paint\r");
	delay(DELAY_TIME);
}

void PLT1001Class::rect(int color, int x, int y, int wt, int ht) {
	mySerial->print("rect ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x);
	mySerial->print(" ");
	mySerial->print(y);
	mySerial->print(" ");
	mySerial->print(wt);
	mySerial->print(" ");
	mySerial->print(ht);
	mySerial->print("\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::paint() {
	delay(DELAY_TIME);
	mySerial->print("paint\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::pixel(int color, int x, int y) {
	mySerial->print("pixel ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x);
	mySerial->print(" ");
	mySerial->print(y);
	mySerial->print("\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::line(int color, int x1, int y1, int x2, int y2) {
	mySerial->print("line ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x1);
	mySerial->print(" ");
	mySerial->print(y1);
	mySerial->print(" ");
	mySerial->print(x2);
	mySerial->print(" ");
	mySerial->print(y2);
	mySerial->print("\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::circle(int color, int x, int y, int radius) {
	mySerial->print("circle ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x);
	mySerial->print(" ");
	mySerial->print(y);
	mySerial->print(" ");
	mySerial->print(radius);
	mySerial->print("\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::circle2(int color, int x, int y, int radius) {
	mySerial->print("circle2 ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x);
	mySerial->print(" ");
	mySerial->print(y);
	mySerial->print(" ");
	mySerial->print(radius);
	mySerial->print("\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::circlef(int color, int x, int y, int radius) {
	mySerial->print("circlef ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x);
	mySerial->print(" ");
	mySerial->print(y);
	mySerial->print(" ");
	mySerial->print(radius);
	mySerial->print("\r");
}

void PLT1001Class::font(int font) {
	mySerial->print("font ");
	mySerial->print(font);
}

void PLT1001Class::text(int color, int x, int y, char *str) {
	mySerial->print("text ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x);
	mySerial->print(" ");
	mySerial->print(y);
	mySerial->print(" \"");
	mySerial->print(str);
	mySerial->print("\"\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

/*Print text. Bottom left corner of first letter starts at x,y*/
void PLT1001Class::textv(int color, int x, int y, char *str) {
	mySerial->print("textv ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x);
	mySerial->print(" ");
	mySerial->print(y);
	mySerial->print(" \"");
	mySerial->print(str);
	mySerial->print("\"\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::scrollspeed(int spd) {
	mySerial->print("scrollspeed ");
	mySerial->print(spd);
	mySerial->print("\r");
	while (mySerial->available()) {
		Serial.print((char)mySerial->read());
	}
}

void PLT1001Class::scroll(int color, int x, int y, int width, char *str) {
	mySerial->print("scroll ");
	mySerial->print(color);
	mySerial->print(" ");
	mySerial->print(x);
	mySerial->print(" ");
	mySerial->print(y);
	mySerial->print(" ");
	mySerial->print(width);
	mySerial->print(" \"");
	mySerial->print(str);
	mySerial->print("\"\r");
	while (mySerial->available()) {
		while ((char)mySerial->read() != '<') {		}
	}
}

void PLT1001Class::end() {
	clear();
	text(1, 24, 7, "CLOSING PLT1001");
	paint();
	delay(1500);
	clear();
	mySerial->end();

}

PLT1001Class plt1001;