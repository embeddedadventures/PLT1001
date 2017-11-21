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
    Written for LDP3208 32x08 matrix display assessment
*/

#include <SoftwareSerial.h>
#include <PLT1001.h>

SoftwareSerial soft(6, 7);
PLT1001 plt1001;

void setup() {
  Serial.begin(115200);
  Serial.println("Welcome to the Emebdded Adventures PLT-1001 LED Matrix display driver example sketch!");
  Serial.print("Display - LDP3208\t");
  Serial.println("(www.embeddedadventures.com)");
  plt1001.beginSoftwareSerial(&soft);
  plt1001.enableActiveHigh(false);
  plt1001.title();
  delay(2000);
  plt1001.clear();
  plt1001.paint();
}

void loop() {
  //Enter something in the serial terminal to start a quick display test
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

void testCircles() {
  //Command Circle
  plt1001.text(1, 1, 6, "Circle");
  plt1001.paint();
  delay(750);
  plt1001.clear();
  plt1001.paint();
  delay(100);
  plt1001.circle(3, 3, 3, 2);
  plt1001.circle(2, 9, 3, 2);
  plt1001.circle(3, 28, 3, 2);
  plt1001.circle(2, 22, 3, 2);
  plt1001.paint();
  delay(2000);
  plt1001.clear();
  plt1001.paint();
  delay(500);
  //Command circle2
  plt1001.text(1, 1, 6, "Circle2");
  plt1001.paint();
  delay(750);
  plt1001.clear();
  plt1001.paint();
  delay(100);
  plt1001.circle2(3, 3, 3, 2);
  plt1001.circle2(2, 9, 3, 2);
  plt1001.circle2(3, 28, 3, 2);
  plt1001.circle2(2, 21, 3, 2);
  plt1001.paint();
  delay(2000);
  plt1001.clear();
  plt1001.paint();
}

void testRectangle() {
  plt1001.rectangle(2, 2, 5, 30, 4);
  plt1001.paint();
  delay(3000);
  plt1001.clear();
  plt1001.paint(); 
}

void testLine() {
  plt1001.text(1, 1, 6, "line");
  plt1001.paint();
  delay(750);
  plt1001.clear();
  plt1001.paint();
  delay(100);
  plt1001.line(3, 0, 7, 31, 7); //Bottom line
  plt1001.paint(); delay(100); 
  plt1001.line(3, 0, 0, 0, 7);  //Left side
  plt1001.paint(); delay(100); 
  plt1001.line(3, 0, 0, 31, 0); //Top line
  plt1001.paint(); delay(100); 
  plt1001.line(3, 31, 0, 31, 7);//Right side
  plt1001.paint(); delay(100); 
  
  plt1001.line(2, 2, 1, 1, 6);  //Left side
  plt1001.paint(); delay(100); 
  plt1001.line(2, 2, 1, 30, 1); //Top line
  plt1001.paint(); delay(100); 
  plt1001.line(2, 30, 1, 30, 6);//Right side
  
  plt1001.paint();
  delay(3000);
  plt1001.clear();
  plt1001.paint();
}

