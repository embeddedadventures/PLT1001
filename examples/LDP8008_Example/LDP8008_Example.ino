/*

Copyright (c) 2017, Embedded Adventures
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
    Written for LDP8008 80x08 matrix display assessment
*/

#include <SoftwareSerial.h>
#include <PLT1001.h>

SoftwareSerial soft(6, 7);
PLT1001 plt1001;

void setup() {
  Serial.begin(115200);
  Serial.println("Welcome to the Emebdded Adventures PLT-1001 LED Matrix display driver example sketch!");
  Serial.print("Display - LDP8008\t");
  Serial.println("(www.embeddedadventures.com)");
  plt1001.beginSoftwareSerial(&soft);
  plt1001.enableActiveHigh(true);
  plt1001.title();
  delay(2000);
  plt1001.clear();
  plt1001.paint();
  mainText();
}

void loop() {
  if (Serial.available()) {
    Serial.read();
    plt1001.clear();
    plt1001.paint();
    delay(5);
    testCircles();
    delay(500);
    testRectangle();
    delay(500);
    testLine();
  }
}

void mainText() {
  plt1001.setFont(1);
  plt1001.setScrollspeed(20);
  plt1001.scroll(2, 8, 6, 64, 6, "Embedded Adventures PLT1001xLDP8008 example");
  plt1001.paint();
  delay(5000);
  delay(5000);
  plt1001.clear();
  plt1001.paint();
}

void testCircles() {
  //Command Circle
  plt1001.text(1, 26, 6, "Circle");
  plt1001.circle(3, 3, 3, 2);
  plt1001.circle(2, 9, 3, 2);
  plt1001.circle(3, 76, 3, 2);
  plt1001.circle(2, 70, 3, 2);
  plt1001.paint();
  delay(2000);
  plt1001.clear();
  plt1001.paint();
  delay(500);
  //Command circle2
  plt1001.text(1, 24, 6, "Circle2");
  plt1001.circle2(3, 3, 3, 2);
  plt1001.circle2(2, 10, 3, 2);
  plt1001.circle2(3, 75, 3, 2);
  plt1001.circle2(2, 68, 3, 2);
  plt1001.paint();
  delay(2000);
  plt1001.clear();
  plt1001.paint();
}

void testRectangle() {
  plt1001.text(1, 17, 6, "rectangle");
  plt1001.rectangle(2, 4, 5, 8, 4);
  plt1001.rectangle(2, 68, 5, 8, 4);
  plt1001.paint();
  delay(3000);
  plt1001.clear();
  plt1001.paint(); 
}

void testLine() {
  plt1001.text(1, 30, 6, "line");
  plt1001.line(3, 0, 7, 79, 7); //Bottom line
  plt1001.paint(); delay(100); 
  plt1001.line(3, 0, 0, 0, 7);  //Left side
  plt1001.paint(); delay(100); 
  plt1001.line(3, 0, 0, 79, 0); //Top line
  plt1001.paint(); delay(100); 
  plt1001.line(3, 79, 0, 79, 7);//Right side
  plt1001.paint(); delay(100); 
  
  plt1001.line(2, 1, 1, 1, 6);  //Left side
  plt1001.paint(); delay(100); 
  plt1001.line(2, 1, 1, 78, 1); //Top line
  plt1001.paint(); delay(100); 
  plt1001.line(2, 78, 1, 78, 6);//Right side
  
  plt1001.paint();
  delay(3000);
  plt1001.clear();
  plt1001.paint();
}

