void date_180822(void)
{
	/* interesting article
		https://hackaday.com/2018/08/21/arm-programming-with-bare-c/
https://jacobmossberg.se/posts/2018/08/11/run-c-program-bare-metal-on-arm-cortex-m3.html
		*/

	/* THVD1450 can only function as half-duplex
	 */

	/* in this post, it said RTS/CTS requires ioctl TIOCMSET to tune the flow
	 * https://www.linuxquestions.org/questions/programming-9/manually-controlling-rts-cts-326590/
	 */
	/* man tty_ioctl - ioctls for terminals and serial lines
	 * TIOCM_RTS/CTS TIOCMSET/TIOCMGET
	 */

	/* 1450 urgent fix of hdmi tx - called by dave
	 */

	/* test_ao, test_aoi2s are not working in the new 5.0 release
	 */

   	-> Device Drivers
       -> Character devices     
       -> Serial drivers     

       https://blog.csdn.net/yasin_lee/article/details/50052061
       PrimeCell® UART (PL011) Technical Reference Manual
       RTS （Require To Send，發送請求）为輸出信號，用於指示本設備准備好可接收數據，低電平有效，低電平說明本設備可以接收數據。
       CTS （Clear ToSend，發送允許）为輸入信號，用於判斷是否可以向對方發送數據，低電平有效，低電平說明本設備可以向對方發送數據。

       沒有串口控制器，用中斷和普通IO口即可實現RTS與CTS功能。
       RTS用GPIO實現，串口就緒拉低電平，串口忙拉高電平
       CTS用中斷實現，檢測到低電平，將串口數據發送出去，檢測到高電平則保留串口數據直到檢測到低電平为止。

       TODO: checkout scanf/getchar must enter '\n'??? 
       TODO: need to get RTS ? any better way to do it?
}





void date_180821(void)
{
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
}
