# PLT1001 #

Arduino library and test sketches for the <a href="http://www.embeddedadventures.com/led_matrix_display_driver_plt-1001v4.html">PLT1001 LED Matrix Display driver</a>.

## Using the library ##
The PLT1001 Arduino library defaults to I2C protocol for communication between the Arduino and the PLT1001 driver board. 

	begin(&Serial1)
The library also supports hardware serial communication for boards like the Arduino Micro, in which case the function above should be added in the setup() portion of your sketch to enable UART communication. 

###Settings/Basic Commands###
	enableActiveHigh(false)
At the moment, the only LED panel we have that is active high is the <a href="http://www.embeddedadventures.com/LED_matrix_display_LDP-8008.html">LDP-8008</a>, in which case you'll want to change the parameter to "true". For all other panels (<a href="http://www.embeddedadventures.com/led_matrix_display_LDP-6432-P7.62v2.html">LDP-6432-P7.62</a>, <a href="http://www.embeddedadventures.com/led_matrix_display_LDP-6432.html">LDP-6432-P4</a>, <a href="http://www.embeddedadventures.com/LED_matrix_display_LDP-6416.html"> <a href="http://www.embeddedadventures.com/LED_matrix_display_LDP-6416.html">LDP-6416-P4</a>, or <a href="http://www.embeddedadventures.com/LED_matrix_display_LDP-6416-P7.62.html">LDP-6416-P7.62</a>), leave it at "false."

	setFont(uns8 font)
The PLT1001 firmware currently supports 8 different font types. The library defaults to 1 as the font. You'll want to do a check with the LED panel you are using to determine what font works best with your application.

	setScrollspeed(uns8 speed)
Call this function to change the scroll time duration. The timing refers to how long the current image is displayed before scrolling one pixel (in milliseconds), so a faster scroll speed means a smaller value passed.

	paint()
All the visual commands (texts, shapes, pixe, clear) for the PLT1001 driver board load the image into the memory. In order for the image to be driven to the LED panel, this function must be called. 

###Visuals###
	clear()
Clear the image memory. 

	pixel(uns8 color, uns16 x, uns16 y)
Draw a pixel at the coordinate (x, y). Note that (0, 0) is the top left pixel of the panel

	line(uns8 color, uns16 x1, uns16 y1, uns16 x2, uns16 y2)
Draw a line with left-most starting point at (x1, y1) to (x2, y2).

	rectangle(uns8 color, uns16 x, uns16 y, uns16 wd, uns16 ht)
Draw a rectangle whose bottom left corner starts at (x, y) and has width = wd and height = ht.




----------
<h2>TODO</h2>

- [] Include check for buffer overflow for I2C protocol
- [] Implement other scrolling functions
- [] Fix *title()* command through Serial communication
