# PLT1001 #

Arduino library and test sketches for the <a href="http://www.embeddedadventures.com/led_matrix_display_driver_plt-1001v4.html">PLT1001 LED Matrix Display driver</a>.

## Using the library ##
NOTE: This library is only for the PLT-1001 driver board. It cannot be used with the PLT-2001 driver board.

The PLT1001 Arduino library defaults to I2C protocol for communication between the Arduino and the PLT1001 driver board. 

	begin(&Serial1)

The library also supports hardware serial communication for boards like the Arduino Micro, in which case the function above should be used in the setup() portion of your sketch to enable UART communication. Just replace the parameter with the hardware serial object you're using e.g. Serial1, Serial2, SerialUSB, etc.

	beginSoftwareSerial(&SoftwareSerial obj)

We've included support to control the PLT-1001 using the SoftwareSerial library. Use the command above to use it, and make sure to include the library in your sketch.


<h3>Settings/Basic Commands</h3>

	enableActiveHigh(true)
The displays in stock are all active high the moment. If your display does not work at first, change to active low.

	setFont(uns8 font)
The PLT1001 firmware currently supports 8 different font types. The library defaults to 1 as the font. You'll want to do a check with the LED panel you are using to determine what font works best with your application.

	setScrollspeed(uns8 speed)
Call this function to change the scroll time duration. The timing refers to how long the current image is displayed before scrolling one pixel (in milliseconds), so a faster scroll speed means a smaller value passed.

	paint()
All the visual commands (texts, shapes, pixe, clear) for the PLT1001 driver board load the image into the memory. In order for the image to be driven to the LED panel, this function must be called. 

<h3>Visuals</h3>

	clear()
Clear the image memory. 

	pixel(uns8 color, uns16 x, uns16 y)
Draw a pixel at the coordinate (x, y). Note that (0, 0) is the top left pixel of the panel

	line(uns8 color, uns16 x1, uns16 y1, uns16 x2, uns16 y2)
Draw a line with left-most starting point at (x1, y1) to (x2, y2).

	rectangle(uns8 color, uns16 x, uns16 y, uns16 wd, uns16 ht)
Draw a rectangle whose bottom left corner starts at (x, y) and has width = wd and height = ht.

<h4>Circles</h4>
	circle(uns8 color, uns16 x, uns16 y, uns8 radius)
Draw a hollow circle with center at (x, y). The other 3 circle functions, *filledCircle()* , *circle2()* , and *filledCircle2()*  have the same parameter formats. 
Circle2 is the same circle drawn, but slightly bigger and more square-looking than the regular *circle()*. Try it out and see if you like it!

<h4>Text</h4>
	text(uns8 color, uns16 x, uns16 y, "text")
The text drawn will have its bottom left corner starting at (x, y). "text" is accepted as String, char*, const char*, and uint8_t.

These next functions are all text-format functions and accept only char* arguments. They are only supported by I2C communication, not UART Serial.

	text_rightJustified()
The (x, y) determines the bottom right corner of the text.

	text_centerJustified()
The (x, y) determines the center position of the text.

	text_vertical()
The line of text will be shown as usual, but rotated 90 degrees.

	text_column()
The next example shows a visual of "sample" as displayed normally, then with the above function:
<br>*sample*<br>vs.
<br>*s*<br>*a*<br>*m*<br>*p*<br>*l*<br>*e*


## Wiring ##
<h3>Serial Connection</h3>
The PLT1001 can be controlled through UART Serial connection. Connect the appropriate pins to the RX and TX pins of the driver board and power it up.

<h3>I2C Connection</h3>
The PLT1001 also offers I2C support, with an extended list of commands that aren't available through Serial protocol. To control the driver board with your Arduino using I2C, connect the following: 

- SDA pin -> RB2
- SCL pin -> RB1

NOTE - firmware for the LDP-8008 does not support I2C commands yet. We will update it and post as soon as firmware has been updated.

## Firmware Updates ##
The PLT-1001 is capable of handling one type of display at a time. The firmware for each display can be found in our [firmware pack](https://www.embeddedadventures.com/downloads/plt1001v4_firmware_pack_3v02.zip), and instructions for updating your PLT-1001 can be found [here](https://www.embeddedadventures.com/downloads/Updating_PLT1001v4_firmware.pdf).

## Contact ##
Questions/comments/concerns regarding the code? Raise it up as a <a href="https://github.com/embeddedadventures/PLT1001/issues/new">new issue</a> and we will help as soon as possible. You may also contact support@embeddedadventures.com. Thanks!

----------
<h2>TODO</h2>

- [] Include check for buffer overflow for I2C protocol
- [] Implement other scrolling functions
