# TEMP FILE

------------------------------------------
TODO
1. SIKULI
1. KOCHA
1. UDEV
1. WINDOWS PROGRAMMING

------------------------------------------

````````````````````````````````````````````````````````````````````````
2018/08/28 (TUE)

setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),123M(rootfs) ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off



Petzold, Programming Windows 5e, 1998

Hart, Windows System Programming 4e, 2015

Nasarre & Richter, Windows via C/C++, 2007

Richter, Programming Applications for Microsoft Windows, 4e, 1999

Prosise, Programming Windows with MFC, 2e, 1999

刘歧 & 赵文杰, FFmpeg从入门到精通, 机械工业出版社 2018

NET/XAML: Languages: C#, C++, F#, VB
C++ and Win32: Win32 and COM API
* Languages: C++ with COM
  * the highest levels of performance or efficiency
  * access native OS features
  * DirectX technologies for low-level, high-performance graphics access


Desktop Programming [link](https://docs.microsoft.com/en-us/windows/desktop/desktop-programming)


````````````````````````````````````````````````````````````````````````
````````````````````````````````````````````````````````````````````````
2018/08/27 (MON)

# mount -t nfs -o nolock 192.168.1.103:/share /mnt


/***** TEST FOR SDI *****/

diff --git a/drv/extdrv/mdin400/app400.c b/drv/extdrv/mdin400/app400.c
index 734dd63..9550134 100755
--- a/drv/extdrv/mdin400/app400.c
+++ b/drv/extdrv/mdin400/app400.c
@@ -195,7 +195,7 @@ static void CreateMDIN400VideoInstance(void)
        // set video path
        stVideo.srcPATH = PATH_MAIN_A_AUX_B;//PATH_MAIN_A_AUX_B;//PATH_MAIN_A_AU
        
-       stVideo.auxPATH = AUX_OUT_PATH_MAIN; //AUX_OUT_PATH_VENC;       // set m
+       stVideo.auxPATH = AUX_OUT_PATH_VENC;    // AUX_OUT_PATH_MAIN; // set mai
 #ifdef DEMO_CVBS_OUT
        stVideo.auxPATH = AUX_OUT_PATH_VENC;    // KN01.1.A
 #endif 
@@ -783,6 +783,10 @@ void avm_input_position_offset_adjust(PMDIN_VIDEO_INFO pINF
                        MDINAUX_SetSrcOffset(&stVideo, 0, 0); 
                        break;
                }
+^M
+       MDIN4xx_SetSrcOffset(&stVideo, 0, 0); ^M
+       MDINAUX_SetSrcOffset(&stVideo, 0, 0); ^M
+^M
        SCALE_DBG_MES(("PORTA offset=%d,%d\n",offset_h_A,offset_v_A));
        SCALE_DBG_MES(("PORTB offset=%d,%d\n",offset_h_B,offset_v_B));
 }

$ git diff mpp_big-little/sample/Makefile.param
diff --git a/mpp_big-little/sample/Makefile.param b/mpp_big-little/sample/Makefi
index cbc8124..54b8dac 100755
--- a/mpp_big-little/sample/Makefile.param
+++ b/mpp_big-little/sample/Makefile.param
@@ -141,6 +141,7 @@ INC_FLAGS += -I$(SDK_PATH)/$(EXTDRV)/tw2865
 INC_FLAGS += -I$(SDK_PATH)/$(EXTDRV)/tlv320aic31
 INC_FLAGS += -I$(SDK_PATH)/$(EXTDRV)/sensor_spi
 INC_FLAGS += -I$(SDK_PATH)/$(EXTDRV)/ak7756en
+CFLAGS += -I$(SDK_PATH)/$(EXTDRV)/avt_7a50t
 
 ifeq ($(GYRO_TYPE), GYRO_INVENSENSE)
        INC_FLAGS += -I$(SDK_PATH)/$(EXTDRV)/gyro_invensense


````````````````````````````````````````````````````````````````````````
````````````````````````````````````````````````````````````````````````
2018/08/25 (SAT)

     

[免費下載] Windows 10 簡體/繁體中文版 ISO 光碟映像檔 v1803（官方正式版）

Windows 10 Product Activation Keys (All Versions)
62 Comments / By Maham Mukhtar / October 25, 2017 May 26, 2018 / Windows / Windows 10, Windows 10 Version 1607, Windows 10 Version 1703, Windows 10 Version 1709

Windows 10 Operating System was welcome by almost all users quite warmly and happily. Users switched to Windows 10 in great numbers due to lots of exciting and new features introduced in this OS.

Windows 10 comes in different versions that meet up with the needs of users in a different perspective. If you are a home and non-commercial user, then you may use Windows 10 Home, if you are a Pro and need Windows for your organization then you can use Windows 10 Enterprise or Pro version. There is a separate version for students which is Windows 10 Student.
Activate Windows
Activate Windows

During installation, Windows 10 will ask you for a product activation key. You will not be able to go ahead further without entering a valid key. If you want to test Windows or install Windows without entering your purchased license key, you can easily use the following generic Windows 10 activation product keys which will let you successfully install Windows with 30 days expiry. You can extend the expiry up to 90 days.

The Windows you installed on your system is s trial version and will expire after 90 days. And it is mandatory to activate your copy of Windows to avail all features of Windows properly. Keys are required for each version at the time of installation to activate your Windows for the lifetime.

Quick Summary [hide]

    1 Windows 10 Activation Keys
        1.1 Windows Server 2016 All Versions
        1.2 Windows 10 version 1607, version 1703, and version 1709
    2 Product keys for Windows 10 Version 1803
    3 Frequently asked questions for Windows 10 product keys
        3.1 How do I activate Windows 10 Pro or Home editions?
        3.2 How do I enter the product key for Windows 10?
        3.3 What is Windows 10 N or Windows 10 KN?
        3.4 How do I change the product key for Windows 10?
        3.5 What is a product key anyway?
        3.6 Must Read Articles:

Scroll below and find the activation key for your required version of Windows 10.
Windows 10 Activation Keys
Windows Server 2016 All Versions

Windows Server 2016 Datacenter

CB7KF-BWN84-R7R2Y-793K2-8XDDG

Windows Server 2016 Standard

WC2BQ-8NRM3-FDDYY-2BFGV-KHKQY

Windows Server 2016 Essentials

JCKRF-N37P4-C2D82-9YXRT-4M63B
Windows 10 version 1607, version 1703, and version 1709

These are the keys for all versions of Windows 10. You have to enter the key while installation when installation process will ask you to enter the relevant key.

Your Windows will be activated as soon as you enter the activation key.

Windows 10 Professional

W269N-WFGWX-YVC9B-4J6C9-T83GX

Windows 10 Professional N

MH37W-N47XK-V7XM9-C7227-GCQG9

Windows 10 Enterprise

NPPR9-FWDCX-D2C8J-H872K-2YT43

Windows 10 Enterprise N

DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4

Windows 10 Education

NW6C2-QMPVW-D7KKK-3GKT6-VCFB2

Windows 10 Education N

2WH4N-8QGBV-H22JP-CT43Q-MDWWJ

Windows 10 Enterprise 2015 LTSB

WNMTR-4C88C-JK8YV-HQ7T2-76DF9

Windows 10 Enterprise 2015 LTSB N

2F77B-TNFGY-69QQF-B8YKP-D69TJ

Windows 10 Enterprise 2016 LTSB

DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ

Windows 10 Enterprise 2016 LTSB N

QFFDN-GRT3P-VKWWX-X7T3R-8B639
Product keys for Windows 10 Version 1803

Windows 10 Enterprise Evaluation

MNXKQ-WY2CT-JWBJ2-T68TQ-YBH2V

Windows 10 Enterprise

XGVPP-NMH47-7TTHJ-W3FW7-8HV2C

Windows 10 Professional Workstation

WYPNQ-8C467-V2W6J-TX4WX-WT2RQ

Windows 10 Education

84NGF-MHBT6-FXBX8-QWJK7-DRR8H

Windows 10 Professional

VK7JG-NPHTM-C97JM-9MPGT-3V66T
https://www.itechtics.com/windows-10-product-activation-keys-versions/

Windows 10 Professional 	W269N-WFGWX-YVC9B-4J6C9-T83GX

````````````````````````````````````````````````````````````````````````
````````````````````````````````````````````````````````````````````````
2018/08/24 (FRI)

[mount mtdblock3]
jffs2: jffs2_scan_eraseblock(): Magic bitmask 0x1985 not found at 0x00060000: 0xfe5a instead
jffs2: jffs2_scan_eraseblock(): Magic bitmask 0x1985 not found at 0x00060004: 0xcc0a instead
jffs2: jffs2_scan_eraseblock(): Magic bitmask 0x1985 not found at 0x00060008: 0x9c53 instead
jffs2: jffs2_scan_eraseblock(): Magic bitmask 0x1985 not found at 0x0006000c: 0xe6fb instead
jffs2: jffs2_scan_eraseblock(): Magic bitmask 0x1985 not found at 0x00060010: 0xc419 instead
jffs2: jffs2_scan_eraseblock(): Magic bitmask 0x1985 not found at 0x00060014: 0xfa06 instead

http://www.infradead.org/pipermail/linux-mtd/2003-May/007786.html
http://www.linux-mtd.infradead.org/faq/jffs2.html#L_magicnfound

Memory Technology Devices

JFFS2

* Journalling Flash File System Version 2
* developer: Redhat
* init with supporting NOR Flash only; version >= 2.6 supporting NAND Flash
* actually resides on the Flash device and allows the user to read/write data to Flash
  * not stored on the Flash device and then copied into RAM during boot (i.e. ramdisk)




At least three file systems have been developed as JFFS2 replacements: LogFS, UBIFS, and YAFFS.



On AM335x, JFFS2 support has been super-seeded by UBIFS.
Reasons for disabling JFFS2 support

    UBIFS file system is recommended for NAND File system over JFFS2 as it is seen as JFFS2 successor with significant improvements in scalability and NAND support.
    Compatibility of ECC layout across all components. RBL, U-boot SPL all uses BCH8 ECC scheme. However supporting BCH8 with JFFS2 is not possible because of shortage of OOB area.
        Total OOB Bytes - 64 Bytes (for every 2048 bytes (512 * 4))
        JFFS2 clean marker requires 8 bytes ==> 64 - 8 = 56 bytes
        ECC requires 14 bytes for every 512 bytes of data. Total ECC bytes = 14 * 4 = 56 Bytes. ==> 56 - 56 = 0 byte
        Manufactures bad block marking requires 2 bytes ==> 0 - 2 = -2 bytes
        This shortage (-2) is the main reason for switching to UBIFS

http://processors.wiki.ti.com/index.php/AM335x_JFFS2_Support_Guide


11:10 GIVE UP ON JFFS2. TOO MANY PROBLEMS THAT I CANNOT FIX!

setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),56M(rootfs),3M(userfs),1M(boot1),4M(kernel1),56M(rootfs1),3M(userfs1) ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lib/gstreamer
export GST_PLUGIN_PATH=/lib/gstreamer/gstreamer-1.0
export GST_PLUGIN_SCANNER=/usr/bin/gst-plugin-scanner

setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),123M(rootfs) ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off

setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=jffs2 rw mtdparts=hinand:1M(boot),4M(kernel),56M(rootfs),3M(userfs) ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off


setenv ipaddr 192.168.1.10;setenv serverip 192.168.1.103

mw.b 82000000 ff 100000;tftp 82000000 u-boot_se5820v0.bin;nand erase 0 100000;nand write 82000000 0 100000

mw.b 82000000 ff f00000;tftp 82000000 uImage;nand erase 100000 400000;nand write 82000000 100000 400000

mw.b 82000000 ff 3000000;tftp 82000000 rootfs_hi3519v101_2k_4bit.yaffs2;nand erase 500000 3000000;nand write.yaffs 82000000 500000 c0a680

setenv bootcmd 'nand read 82000000 100000 400000;bootm 82000000'
setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),123M(rootfs)  ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off

http://lists.busybox.net/pipermail/busybox/2005-February/013688.html

ifconfig eth0 192.168.1.10; mount -t nfs -o nolock 192.168.1.103:/share /mnt

# cp -f /mnt/libasound.so.2 /lib; cp -f /mnt/libmp3enc.so /lib; cp -r /mnt/bak/lib/gstreamer/ /lib; cp /mnt/bak/gst-plugin-scanner /usr/bin/; 

# cp -f /mnt/bak/rcS /etc/init.d/; cp -f /mnt/bak/profile /etc/; cp -r /mnt/ko_se5820v0 .

# cp /mnt/sample_demo .

总之，先执行 /etc/inittab， 然后调用/etc/init.d/rcS， 最后是执行/etc/profile

````````````````````````````````````````````````````````````````````````
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

17:00 start using jffs2. saw a lot crc errors. the copied file crashed when start running (segmentation fault)

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
