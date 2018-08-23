# TEMP FILE

------------------------------------------

````````````````````````````````````````````````````````````````````````
2018/08/23



$ cd osdrv/opensource/uboot/u-boot-2010.06
$ ARCH=arm CROSS_COMPILE=arm-hisiv500-linux- make hi3519v101_nand_config
$ cd ../../../../avt_dailybuild/
$ cp osdrv/opensource/uboot/u-boot-2010.06/u-boot.bin .
$ ./mkboot_se5820.sh reg_info_hi3519v101_se5820v0.bin u-boot_se5820v0.bin
$ mv u-boot_se5820v0.bin 180823/

$ cd ../osdrv/opensource/kernel/linux-3.18.y/
$ cp arch/arm/configs/se5820v0_nand_defconfig .config
$ ARCH=arm CROSS_COMPILE=arm-hisiv500-linux-  make -j8 uImage
$ cd ../../../../

 osdrv/opensource/kernel/linux-3.18.y/arch/arm/configs/hi3519v101_big_little_nand_defconfig 
index a6017a5..c47db52 100644
@@ -345,6 +345,9 @@ CONFIG_ARCH_HI3519V101=y
 # CONFIG_ARCH_HI3556 is not set
 CONFIG_PMC=y
 # CONFIG_ARCH_HI3536C is not set
+# CONFIG_ARCH_HI3531D is not set
+# CONFIG_ARCH_HI3520DV400 is not set
+# CONFIG_ARCH_HI3521D is not set
 # CONFIG_ARCH_KEYSTONE is not set
 # CONFIG_ARCH_MESON is not set
 # CONFIG_ARCH_MXC is not set
@@ -915,6 +918,7 @@ CONFIG_MTD_NAND=y
 # CONFIG_MTD_NAND_PLATFORM is not set
 # CONFIG_HISI_NAND_FS_MAY_NO_YAFFS2 is not set
 # CONFIG_HISI_NAND_ECC_STATUS_REPORT is not set
+# CONFIG_MTD_NAND_HINFC610 is not set
 CONFIG_HIFMC100_NAND=y
 CONFIG_HIFMC100_MAX_NAND_CHIP=1
 # CONFIG_HIFMC100_NAND_EDO_MODE is not set
@@ -1072,6 +1076,7 @@ CONFIG_BLK_DEV_SD=y
 # CONFIG_MD is not set
 # CONFIG_TARGET_CORE is not set
 CONFIG_NETDEVICES=y
+CONFIG_MII=y
 CONFIG_NET_CORE=y
 # CONFIG_BONDING is not set
 # CONFIG_DUMMY is not set
@@ -1176,8 +1181,39 @@ CONFIG_USB_NET_DRIVERS=y
 # CONFIG_USB_PEGASUS is not set
 # CONFIG_USB_RTL8150 is not set
 # CONFIG_USB_RTL8152 is not set
-# CONFIG_USB_USBNET is not set
+CONFIG_USB_USBNET=y
+CONFIG_USB_NET_AX8817X=y
+CONFIG_USB_NET_AX88179_178A=m
+CONFIG_USB_NET_CDCETHER=y
+# CONFIG_USB_NET_CDC_EEM is not set
+CONFIG_USB_NET_CDC_NCM=y
+# CONFIG_USB_NET_HUAWEI_CDC_NCM is not set
+# CONFIG_USB_NET_CDC_MBIM is not set
+# CONFIG_USB_NET_DM9601 is not set
+# CONFIG_USB_NET_SR9700 is not set
+# CONFIG_USB_NET_SR9800 is not set
+# CONFIG_USB_NET_SMSC75XX is not set
+# CONFIG_USB_NET_SMSC95XX is not set
+# CONFIG_USB_NET_GL620A is not set
	
+# CONFIG_USB_NET_PLUSB is not set
+# CONFIG_USB_NET_MCS7830 is not set
+# CONFIG_USB_NET_RNDIS_HOST is not set
+CONFIG_USB_NET_CDC_SUBSET=y
+# CONFIG_USB_ALI_M5632 is not set
+# CONFIG_USB_AN2720 is not set
+CONFIG_USB_BELKIN=y
+CONFIG_USB_ARMLINUX=y
+# CONFIG_USB_EPSON2888 is not set
+# CONFIG_USB_KC2190 is not set
+CONFIG_USB_NET_ZAURUS=y
+# CONFIG_USB_NET_CX82310_ETH is not set
+# CONFIG_USB_NET_KALMIA is not set
+# CONFIG_USB_NET_QMI_WWAN is not set
+# CONFIG_USB_NET_INT51X1 is not set
 # CONFIG_USB_IPHETH is not set
+# CONFIG_USB_SIERRA_NET is not set
+# CONFIG_USB_VL600 is not set
 # CONFIG_WLAN is not set
 
 #
@@ -1218,7 +1254,7 @@ CONFIG_KEYBOARD_ATKBD=y
 # CONFIG_KEYBOARD_QT1070 is not set
 # CONFIG_KEYBOARD_QT2160 is not set
 # CONFIG_KEYBOARD_LKKBD is not set
-# CONFIG_KEYBOARD_GPIO is not set
+CONFIG_KEYBOARD_GPIO=y
 # CONFIG_KEYBOARD_GPIO_POLLED is not set
 # CONFIG_KEYBOARD_TCA6416 is not set
 # CONFIG_KEYBOARD_TCA8418 is not set
@@ -1797,7 +1833,48 @@ CONFIG_FB_CMDLINE=y
 CONFIG_DUMMY_CONSOLE=y
 # CONFIG_FRAMEBUFFER_CONSOLE is not set
 # CONFIG_LOGO is not set
-# CONFIG_SOUND is not set
+CONFIG_SOUND=y
+# CONFIG_SOUND_OSS_CORE is not set
+CONFIG_SND=y
+CONFIG_SND_TIMER=y
+CONFIG_SND_PCM=y
+CONFIG_SND_HWDEP=y
+CONFIG_SND_RAWMIDI=y
+# CONFIG_SND_SEQUENCER is not set
+# CONFIG_SND_MIXER_OSS is not set
+# CONFIG_SND_PCM_OSS is not set
+# CONFIG_SND_DYNAMIC_MINORS is not set
+CONFIG_SND_SUPPORT_OLD_API=y
+CONFIG_SND_VERBOSE_PROCFS=y
+# CONFIG_SND_VERBOSE_PRINTK is not set
+# CONFIG_SND_DEBUG is not set
+# CONFIG_SND_RAWMIDI_SEQ is not set
+# CONFIG_SND_OPL3_LIB_SEQ is not set
+# CONFIG_SND_OPL4_LIB_SEQ is not set
+# CONFIG_SND_SBAWE_SEQ is not set
+# CONFIG_SND_EMU10K1_SEQ is not set
+CONFIG_SND_DRIVERS=y
+# CONFIG_SND_DUMMY is not set
+# CONFIG_SND_ALOOP is not set
+# CONFIG_SND_MTPAV is not set
+# CONFIG_SND_SERIAL_U16550 is not set
+# CONFIG_SND_MPU401 is not set
+
+#
+# HD-Audio
+#
+CONFIG_SND_ARM=y
+# CONFIG_SND_ARMAACI is not set
+CONFIG_SND_SPI=y
+CONFIG_SND_USB=y
+CONFIG_SND_USB_AUDIO=y
+# CONFIG_SND_USB_UA101 is not set
+# CONFIG_SND_USB_CAIAQ is not set
+# CONFIG_SND_USB_6FIRE is not set
+# CONFIG_SND_USB_HIFACE is not set
+# CONFIG_SND_BCD2000 is not set
+# CONFIG_SND_SOC is not set
+# CONFIG_SOUND_PRIME is not set
 
 #
 # HID support
@@ -1819,6 +1896,7 @@ CONFIG_HID_APPLE=y
 CONFIG_HID_BELKIN=y
 CONFIG_HID_CHERRY=y
 CONFIG_HID_CHICONY=y
+# CONFIG_HID_PRODIKEYS is not set
 # CONFIG_HID_CP2112 is not set
 CONFIG_HID_CYPRESS=y
 # CONFIG_HID_DRAGONRISE is not set
@@ -2146,6 +2224,7 @@ CONFIG_CLKSRC_OF=y
 CONFIG_CLKSRC_MMIO=y
 CONFIG_ARM_ARCH_TIMER=y
 CONFIG_ARM_ARCH_TIMER_EVTSTREAM=y
+# CONFIG_ARM_ARCH_TIMER_VCT_ACCESS is not set
 # CONFIG_ATMEL_PIT is not set
 # CONFIG_SH_TIMER_CMT is not set
 # CONFIG_SH_TIMER_MTU2 is not set
@@ -2250,6 +2329,7 @@ CONFIG_MSDOS_FS=y
 CONFIG_VFAT_FS=y
 CONFIG_FAT_DEFAULT_CODEPAGE=437
 CONFIG_FAT_DEFAULT_IOCHARSET="iso8859-1"
+# CONFIG_EXFAT_FS is not set
 # CONFIG_NTFS_FS is not set
 
 #
@@ -2636,6 +2716,7 @@ CONFIG_CRYPTO_AES=y
 # CONFIG_CRYPTO_USER_API_HASH is not set
 # CONFIG_CRYPTO_USER_API_SKCIPHER is not set
 CONFIG_CRYPTO_HW=y
+# CONFIG_CRYPTO_DEV_HISILICON is not set
 # CONFIG_BINARY_PRINTF is not set
 
 #



git checkout ece87b8ea6519558dbcfa615d2d1123bc514682d -- file1/to/restore


setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=jffs2 rw mtdparts=hinand:1M(boot),4M(kernel),56M(rootfs),3M(userfs),1M(boot1),4M(kernel1),56M(rootfs1),3M(userfs1) ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off



avt_dailybuild/


````````````````````````````````````````````````````````````````````````
````````````````````````````````````````````````````````````````````````
2018/08/22

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
       CTS （Clear To Send，發送允許）为輸入信號，用於判斷是否可以向對方發送數據，低電平有效，低電平說明本設備可以向對方發送數據。

       沒有串口控制器，用中斷和普通IO口即可實現RTS與CTS功能。
       RTS用GPIO實現，串口就緒拉低電平，串口忙拉高電平
       CTS用中斷實現，檢測到低電平，將串口數據發送出去，檢測到高電平則保留串口數據直到檢測到低電平为止。

       TODO: checkout scanf/getchar must enter '\n'??? 
       TODO: need to get RTS ? any better way to do it?
}

````````````````````````````````````````````````````````````````````````
````````````````````````````````````````````````````````````````````````
2018/08/21

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

````````````````````````````````````````````````````````````````````````