# VISCA Protocol

What is VISCA Protocol
* Video System Control Architecture
* designed by Sony
* a protocol to control professional cameras
* based on RS232 9600 bps, 8N1, no flow control

How to cross compile?
```
$ CC=arm_v5t_le-gcc AR=arm_v5t_le-ar ./configure --host=arm
$ make
```

A command data packet consists of:
* a 1-byte message header
	bit 7: always 1
	bits 6-4: source device number
	bit 3: 0 normal packet; 1 for broadcast packets
	bits 2-0: destination device number or 000 for broadcast
* 1 to 14-bytes of data
* a terminator byte of 0xFF.
* Each command data packet has a corresponding response data packet.

Any flowchart to indicate how commands go and take control of devices?



## references
* https://en.wikipedia.org/wiki/VISCA_Protocol
* https://damien.douxchamps.net/libvisca/
* https://sourceforge.net/projects/libvisca/
* https://github.com/mkoppanen/libVISCA2

## history
* 2017/05/19 init