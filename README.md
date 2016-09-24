# PLT1001
Arduino library and test sketches for the <a href="http://www.embeddedadventures.com/led_matrix_display_driver_plt-1001v4.html">PLT1001 LED Matrix Display driver</a>.

The PLT1001 object defaults to using I2C protocol for communication between the Arduino and the PLT1001. The demo sketch includes the line to modify it to use a Serial protocol. 

TODO:
- [] Include check for buffer overflow for I2C protocol
- [] Implement other scrolling functions
- [] Fix *title()* command through Serial communication
