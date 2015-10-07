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

/*  PLT1001 LED Matrix display driver Arduino test sketch
    Written originally by Embedded Adventures
    Used for LDP8008 80x8 matrix display assessment
*/

#include <PLT1001.h>

void setup() {
  Serial.begin(115200);
  plt1001.init(&Serial1);
  delay(5000);
  plt1001.clear();
  Serial.println("Display initialized");
}

void loop() {
  demo_shapes();
  demo_pixels();
  demo_lines();
  demo_text("EA plt1001");

  plt1001.scrollspeed(40);
  plt1001.paint();
  delay(50);
  plt1001.scroll(3, 0, 7, 80, "This is a demonstration of scrolling");
  
  plt1001.clear();
}

void demo_text(char *str) {
  for (int i = 1; i < 5; i++) {
    plt1001.font(i);
    plt1001.paint();
    plt1001.text(3, i * 1, 7, str);
    plt1001.paint();
    delay(750);
    plt1001.clear();
  }
}

void demo_shapes() {
  plt1001.rect(1, 0, 7, 7, 7);
  plt1001.circle(2, 11, 4, 3);
  plt1001.rect(3, 16, 7, 7, 7);
  plt1001.circlef(2, 27, 4, 3);
  plt1001.rect(1, 32, 7, 7, 7);
  plt1001.circle2(2, 43, 3, 3);
  plt1001.paint();
  delay(1000);
  plt1001.clear();
}

void demo_pixels() {
  for (int i = 0; i < 10; i++) {
  plt1001.pixel(2, ((i * 8) + 1), 1);
  plt1001.pixel(2, ((i * 8) + 1), 6);
  plt1001.pixel(2, ((i * 8) + 6), 1);
  plt1001.pixel(2, ((i * 8) + 6), 6);
  plt1001.paint();
  delay(200);
  }
  plt1001.clear();
}

void demo_lines() {
  for (int i = 0; i < 4; i++) {
    plt1001.line(1, i, i, 79 - i, i);
    plt1001.paint();
    delay(300);
    //plt1001.clear();
  }
  for (int i = 3; i >= 0; i--) {
    plt1001.line(1, i, 7 - i, 79 - i, 7 - i);
    plt1001.paint();
    delay(300);
    //plt1001.clear();
  }
  plt1001.clear();
  delay(200);
  //Draw a bunch of Xs
  for (int i = 0; i < 10; i++) {
    plt1001.line(3, (8 * i), 0, ((8 * i) + 7), 7);
    plt1001.paint();
    delay(100);
    plt1001.line(3, (8 * i), 7, ((8 * i) + 7), 0);
    plt1001.paint();
    delay(100);
  }
  plt1001.clear();
}

