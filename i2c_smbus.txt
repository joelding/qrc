# I2C/SMBUS

## History
	* 2017/04/17	init
	* 2017/04/26	KM report with this topic

## References
* Fork of official Debian package https://github.com/ev3dev/i2c-tools.git


### cross compile
* no autotools
```
$ CC=arm-linux-gnueabihf-gcc make
```
* libi2c.a, libi2c.so.0.1.0

---------------------------------------------------------------------
The I2C specification
- inter-IC
- revision 1.0 in 1992; 2.1 in 2000
- revision v.6, 2014/04/04
- 2 bus lines: serial data SDA, serial clock SCL
- bidirectional standard mode 100kbit/s, fast mode 400kbit/s, fast mode plus 1Mbits/s, high-speed mode 3.4Mbits/s; unidirectional ultra fast-mode 5Mbits/s
- multi-master bus
- specifies only how to move bytes from one device to another
- logic level: VIL = 0.3VDD, VIH = 0.7VDD

START condition
- a high to low transition on SDA while SCL is high

STOP condition
- a low to high transition on SDA while SCL is high

byte format
- must be 8 bits long
- after 8 bits followed by an ack

ACK/NACK
- 9th clock pulse
- master releases SDA
- ACK: slave pull SDA low during the high period of the clock pulse
- NACK: SDA high during the high period of the clock puls


The SMBus specification 
- defines command oriented protocols
- not all I2C devices support

had enough lately 
---------------------------------------------------------------------
https://www.kernel.org/doc/Documentation/i2c/functionality
https://www.kernel.org/doc/Documentation/i2c/smbus-protocol
support revisions 1.0, 1.1, 2.0
support part of protocol features

