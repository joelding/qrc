setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),31M(rootfs),28M(test) ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off

https://lists.denx.de/pipermail/u-boot/2012-May/123550.html

 網路名稱 (SSID) :
	  	DIR-615
安全模式 :
	  	自動 (WPA 或 WPA2) - 個人級
密碼類型: :
	  	TKIP 及 AES
預先共用金鑰(Pre-shared Key) :
	  	280bbb4e9ad829c73253395c6231969ece96a7e9b1e513db7cd7800bc1caa1f8 



git clone https://github.com/npat-efault/picocom.git

picocom$ CC=arm-hisiv500-linux-gcc make 

C-a C-q: quit

sudo picocom /dev/ttyUSB0 
-b 115200 #baud-rate
-f h #flow-control mode: hardware flow control (RTS/CTS) 

u-boot-2010.06/include/configs/hi3519v101.h:171:#define CONFIG_BOOTARGS "mem=96M console=ttyAMA0,115200"

irtx/main.c : Not working for now 11:52

