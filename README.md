# keynote

Collection of keynotes

* cxx.md
* irremote.md
* cortexmcu.md
* ldd.md

TODO

U-boot environment variables show as following:
````````````````````````````````````````````````
netmask=255.255.255.0
ipaddr=192.168.1.10
serverip=192.168.1.103
````````````````````````````````````````````````
Why isn't the following effiective?
````````````````````````````````````````````````
bootargs=mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),3M(kernel),32M(rootfs),28M(test) ip=${ipaddr}:::${netmask}::eth0:off
````````````````````````````````````````````````
The following is effective:
````````````````````````````````````````````````
bootargs=mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),3M(kernel),32M(rootfs),28M(test) ip=192.168.1.10:::255.255.255.0::eth0:off
````````````````````````````````````````````````
Wolfgang Denk: The "bootm" command will just pass the content of the "bootargs" variable as command line to the Linux kernel - it will not modify it in any way. If you want variable substitution to take place, you must invoce the shell - one way or another.  The recommended and usually most efficient way is to (iteratively) build the kernel command line (i. e. the bootargs variable) dynamically; in this process you also get the variables substituted as you want it.

See the examples in the manual, or many of the built-in default
environment settings, for example in "include/configs/amcc-common.h"

[link](https://lists.denx.de/pipermail/u-boot/2012-May/123550.html)

````````````````````````````````````````````````
ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}:${hostname}:${netdev}:off
````````````````````````````````````````````````
