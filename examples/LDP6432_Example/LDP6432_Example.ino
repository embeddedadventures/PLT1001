/*

Copyright (c) 2016, Embedded Adventures
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

/*  PLT1001 LED Matrix display driver Arduino test sketch
    Written originally by Embedded Adventures
    Written for LDP6432 64x32 matrix display assessment
*/


#include <Wire.h>
#include <PLT1001.h> 

PLT1001 plt1001;

void setup() {
  Serial.begin(115200);
  
  //Using I2C for communication
  plt1001.begin();
  
  //Using Serial1 on the Arduino Micro
  //plt1001.begin(&Serial1);
  
  Serial.println("Welcome to the PLT1001 LED Display Matrix Driver test sketch");
  Serial.println("Embedded Adventures (embeddedadventures.com)");
  delay(1000);
  plt1001.title();
  delay(1500);
  plt1001.clear();
  plt1001.paint();
  delay(500);
  plt1001.setScrollspeed(50);
  plt1001.scroll(3, 16, 15, 15, 8, "SCROLL");
  delay(5000);
  plt1001.clear();
  plt1001.paint();
  delay(500);
}

void loop() {
  pixelTest();
  delay(1000);
  plt1001.clear();
  plt1001.paint();
  lineTest();
  delay(1000);
  plt1001.clear();
  plt1001.paint();
  rect();
  delay(1000);
  plt1001.clear();
  plt1001.paint();
  circles();
  delay(1000);
  plt1001.clear();
  plt1001.paint();
  textTest();
  delay(1000);
  plt1001.clear();
  plt1001.paint();

}

void textTest() {
  plt1001.text(1, 8, 23, "TEXT L");
  plt1001.paint();
  delay(500);
  plt1001.clear();
  plt1001.paint();
  plt1001.text_rightJustified(1, 55, 23, "TEXT R");
  plt1001.paint();
  delay(500);
  plt1001.clear();
  plt1001.paint();
  plt1001.text_centerJustified(1, 32, 23, "TEXT C");
  plt1001.paint();
  delay(500);
  plt1001.clear();
  plt1001.paint();
  plt1001.text_vertical(2, 32, 23, "VERT");
  plt1001.paint();
  delay(500);
  plt1001.clear();
  plt1001.paint();
  plt1001.text_column(2, 12, 3, "COL");
  plt1001.paint();
  delay(500);
  plt1001.clear();
  plt1001.paint();
  plt1001.text_vertColumn(2, 16, 14, "VCOL");
  plt1001.paint();
}

void circles() {
  plt1001.circle(1, 12, 14, 4);
  plt1001.filledCircle(2, 21, 14, 4);
  plt1001.circle2(2, 41, 14, 4);
  plt1001.filledCircle2(1, 51, 14, 4);
  plt1001.paint();
}

void rect() {
  plt1001.rectangle(2, 12, 19, 40, 8);
  plt1001.paint();
}

void lineTest() {
  plt1001.line(3, 8, 8, 55, 8);
  plt1001.line(3, 8, 23, 55, 23);
  plt1001.paint();
}

void pixelTest() {
  plt1001.pixel(3, 0, 0);
  plt1001.pixel(1, 63, 0);
  plt1001.pixel(2, 0, 31);
  plt1001.pixel(3, 63, 31);
  plt1001.paint();
}



