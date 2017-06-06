# Linux System Programming
Notes of system programming on Linux

## History
* 2017/06/01 init

## Textbooks
1. Kerrisk, The Linux Programming Interface: A Linux and UNIX System Programming Handbook, No Starch Press, 2010
1. Love, Linux System Programming: Talking Directly to the Kernel and C Library, 2/e, O'Reilly, 2013
1. Buttlar, PThreads Programming: A POSIX Standard for Better Multiprocessing, O'Reilly, 1996
1. Butenhof, Programming with POSIX Threads, Addison-Wesley, 1997

## Questions while reading source codes

### What is the effect of usleep(0)

  usleep(0) appears in libvisca.c. The usleep() function suspends execution of the calling thread for __at least__ given microseconds. The value passed is used as a minimum. The system is free to use the smallest possible interval instead. [link](https://stackoverflow.com/questions/12823598/effect-of-usleep0-in-c-on-linux)

### What is the difference between ioctl/FIONREAD and select?

  In VISCA library, \_VISCA\_get\_packet() uses ioctl/FIONREAD. But why not use select? 
```
int bytes;
unsighed char buf[256];
ioctl(fd, FIONREAD, &bytes);
```
returns the number of bytes in the input buffer. This can be useful when polling a serial port and waiting for data, as your program can determine the number of bytes in the input buffer before attempting a read. UNIX provides this capability through the select(2) system call. This system call allows your program to check for input, output, or error conditions on one or more file descriptors. The file descriptors can point to serial ports, regular files, other devices, pipes, or sockets. You can poll to check for pending input, wait for input indefinitely, or timeout after a specific amount of time, making the select system call extremely __flexible__. [ref](https://www.cmrr.umn.edu/~strupp/serial.html)




