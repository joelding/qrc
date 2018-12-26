# TEMP FILE


## MTD SUBSYSTEM
**JFFS2**
* Journalling Flash File System Version 2
* developer: Redhat
* init with supporting NOR Flash only
	* version >= 2.6 supporting NAND Flash
* support _wear leveling_
* actually resides on the Flash device and allows the user to read/write data to Flash
* not stored on the Flash device and then copied into RAM during boot (i.e. ramdisk)

Memory Technology Devices


At least three file systems have been developed as JFFS2 replacements: LogFS, UBIFS, and YAFFS.

On AM335x, JFFS2 support has been super-seeded by UBIFS.
Reasons for disabling JFFS2 support

**MTD Utilities**
* flash_* family
* built as cross-compiled user space code
* list MTD partitions `# cat /proc/mtd`
* erase `# flash_erase /dev/mtd1`
* write `# flashcp /workspace/coyote-40-zImage /dev/mtd1`

**UBIFS**
* unsorted block image file system
* origin: NOKIA and University of Szeged
* considered as successor to JFFS2
* benefit
  *   shorted mount time over JFFS2
* work on top of raw flash instead of block devices

**references**
1. official site [link](http://www.linux-mtd.infradead.org/doc/ubifs.html)
2. Hallinan, Embedded Linux Primer, 2e, 2011 Pearson Education Inc
3. An Introduction to SPI-NOR Subsystem [link](http://events17.linuxfoundation.org/sites/events/files/slides/An%20Introduction%20to%20SPI-NOR%20Subsystem%20-%20v3_0.pdf)


## 2018/11/16/FRI
|廠牌|容量  |總線標誌|Speed Class標示法|UHS Speed Class標示法|Video Speed Class標示法 |檔案格式|配置單位大小|
|--|--|--|--|--|--|--|--|--|--|
|PQI|32GB | I |C10|U1|N/A |NTFS|預設配置大小|


## 2018/11/12
```
# cat /proc/fs/ufsd/version 
NTFSJ support included
Build_for__AverMedia_T533C_k3.18.20_2018-11-08_lke_9.6.3_b7
 Evaluation copy - not for resale! 
$Id: ufsdvfs.c 325982 2018-09-17 10:29:23Z zaytsev2 $
driver (UFSD_HEAD lke_9.6.3_b7, paragon, acl, ioctl, sd2(5), tr, car) loaded at 
bf010000, sizeof(inode)=368
Kernel .config hash: original 0x52183c0c, current can't check.
```
* Underneath the file system files are represented by inodes. 
* A file in the file system is basically a link to an inode. 
* When you delete a file it removes one link to the underlying inode. The inode is only deleted (or deletable/over-writable) when all links to the inode have been deleted.
 
|hard link|symbolic link|
|--|--|
| an additional name for an existing file |a special kind of file that points to another file, much like a shortcut  |
|cannot be created for directories, cannot cross filesystem boundaries or span across partitions|can link to directories, or to files on remote computers networked through NFS|
|preserve the contents of the file; deleting a target file for a symbolic link makes that link useless |does not contain the data in the target file; deleting a target file for a symbolic link makes that link useless|
|`$ ln filename hardlink`|`$ ln -s filename softlink`|

```
$ touch test; ls -l
-rw-rw-r-- 1 a003257 a003257    0 Nov 12 14:00 test
```
Note: creating a file forms a hard link to the underlying inode.
```
$ ln test test2; ls -l
-rw-rw-r-- 2 a003257 a003257    0 Nov 12 14:00 test
-rw-rw-r-- 2 a003257 a003257    0 Nov 12 14:00 test2
```
Note: Now 2 hard links exist after creating a hard link to the previous file
```
$ ln test test3; ls -l
-rw-rw-r-- 3 a003257 a003257    0 Nov 12 14:00 test
-rw-rw-r-- 3 a003257 a003257    0 Nov 12 14:00 test2
-rw-rw-r-- 3 a003257 a003257    0 Nov 12 14:00 test3
```
Note: Now 3 hard links exist after creating a hard link to the previous file
```
-rw-rw-r-- 1 a003257 a003257   10 Nov 12 14:10 test
lrwxrwxrwx 1 a003257 a003257    4 Nov 12 14:11 test2 -> test
```
## TODO
 - [MUST READ IT SOON](#must-read-it-soon)
 - SIKULI
 - WINDOWS PROGRAMMING
 - [KOCHA and UDEV](#kocha-and-udev)
 - [MTD SUBSYSTEM](#mtd-subsystem)
 - [SOP for SE5820 DEMO BOARDS](#sop-for-se5820-demo-boards)
 - [HI3519V101 SPI PORT](#hi3519v101-spi-port)
 - [MEMORY LEAK](#memory-leak)
 - [時間管理黃金法則](#時間管理黃金法則) 呂宗昕 商周出版 2008
 - [GSTREAMER BASIC TUTORIAL](#gstreamer-basic-tutorial)
 - [BIBLE STUDY](#bible-study)
 - [HOW TO GET SD CARD MODE](#how-to-get-sd-card-mode)
 - [UPGRADE EMBEDDED LINUX](#upgrade-embedded-linux) WITHOUT USING MTD UTILITLIES
 - [SYSTEM SOFTWARE](#system-software)
 - [COMMON LINUX COMMANDS](#common-linux-commands)
 - [HOW TO PROPERLY HANDLE JFFS2](#how-to-properly-handle-jffs2)


## PHYTOOL
- official site [link](https://github.com/wkz/phytool)
- Linux MDIO register access
- tested ok on hi3519v101 platform
- cross compile `$ CC=arm-hisiv500-linux-gcc make`
- history
- 2018/10/25 init 


## ETHTOOL
 - official site [link](https://mirrors.edge.kernel.org/pub/software/network/ethtool/)
 - standard Linux utility for controlling network drivers and hardware, particularly for wired Ethernet devices
 - cross compile `$ ./configure --host=arm-hisiv500-linux`
 - history
   - 2018/10/25 init

## HOW TO PROPERLY HANDLE JFFS2
* recording date: 2018/10/02
```
Registering SWP/SWPB emulation handler
jffs2: CLEANMARKER node found at 0x00000000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00020000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00040000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00060000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00080000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x000a0000 has totlen 0xc != normal 0x0
usb 3-1.4: new full-speed USB device number 3 using ehci-platform
jffs2: CLEANMARKER node found at 0x000c0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x000e0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00100000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00120000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00140000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00160000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00180000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x001a0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x001c0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x001e0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00200000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00220000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00240000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00260000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00280000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x002a0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x002c0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x002e0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00300000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00320000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00340000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00360000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00380000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x003a0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x003c0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x003e0000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00400000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00420000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00440000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00460000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x00480000 has totlen 0xc != normal 0x0
jffs2: CLEANMARKER node found at 0x004a0000 has totlen 0xc != normal 0x0
VFS: Mounted root (jffs2 filesystem) on device 31:2.
devtmpfs: mounted

```
```
jffs2: notice: (54) check_node_data: wrong data CRC in data node at 0x004b4728: 
read 0xd6f8555a, calculated 0x79d7fa74.
jffs2: notice: (54) check_node_data: wrong data CRC in data node at 0x004b3a78: 
read 0x917ea828, calculated 0x4b7b0c28.
jffs2: notice: (54) check_node_data: wrong data CRC in data node at 0x004b33c4: 
read 0xd7b5c656, calculated 0xb6fe25c9.
```

## COMMON LINUX COMMANDS
* dd
	* verbose: `$ dd if=/media/sdb1/somefile.img of=/dev/sdc count=100MB status=progress`
	* with unblocked device to generate a random content file of 16Mbytes size: `$ dd bs=1024 count=16384 </dev/urandom >/somepath/output.bin`
* hexdump
	* `$ hexdump -C somefile.bin`
mmcblk0p1

## SYSTEM SOFTWARE
**history**
* 2018/09/25 init

Q: How to read dependencies of an executable file?
A: arm-hisiv500-linux-readelf -d [an application program]

Q: How to copy a file while keeping all its attributes?
A: cp -pa [files] [destination directory]

**references**
1. Beck, System Software: An Introduction to Systems Programming, 3e, Pearson 1996
2. 系統程式，陳鍾誠，旗標出版社 ISBN：978-957-442-827-4

## MUST READ IT SOON
1. Introduction to Computer OrganizationARM Assembly Language Using the Raspberry Pi - by Plantz [link](http://bob.cs.sonoma.edu/IntroCompOrg-RPi/intro-co-rpi.html)



## UPGRADE EMBEDDED LINUX WITHOUT USING MTD UTILITLIES
* Is it possible to write the other half of the flash chip without using mtd utilities? 2018-09-21
* 
## HOW TO GET SD CARD MODE
2018/09/14 SE5820 under SI test. Bill asked.

* **hdparm**
  * implemented by busybox, available on hi3519v101 sdk 
  * get/set hard disk parameters
```
# hdparm -t /dev/xx
```
**SD/SDIO 的傳輸模式有以下 3 種** 
-   SPI mode（required）
-   1-bit mode
-   4-bit mode

**Linux支援**
-  2.6.17 正式加入 SD/MMC 驅動程式
- 只能在 ARM 平臺上使用
- Open source 的實作即是 SD-MMC 的驅動程式。
- Core API 「可以做到」支援 SD/SPI mode only
- 因為有辦法做到支援 SPI mode，當然 1-bit mode 也可以做出來。，網路上有人將 1-bit mode 擴充至 4-bit mode，有版權問題。
- 完整的 SD stack 要付費，SD Card Association product license agreement 不允許 open source 的驅動程式實作。

On hi3519 platform, when an SD card was inserted, the following message showed up on the console:
```
himci: card connected!
mmc1: cannot verify signal voltage switch
himci: turning mmc1: valid phase shift [2, 13] Final Phase 7
mmc1: new ultra high speed SDR104 SDXC card at address 0007
mmcblk0: mmc1:0007 SD512 477 GiB
 mmcblk0: p1
```



**references**
1. wiki SD卡 [link](https://zh.wikipedia.org/wiki/SD%E5%8D%A1)
2. SD/eMMC: new speed modes and their support in Linux [youtube](https://youtu.be/mxdKXlANup4) [handout](https://bootlin.com/pub/conferences/2017/elce/clement-sd-mmc-high-speed-support-in-linux/clement-sd-mmc-high-speed-support-in-linux-kernel.pdf)
3. TI, Linux MMC/SD Driver Guide [link](http://processors.wiki.ti.com/index.php/Linux_Core_MMC/SD_User%27s_Guide)

## BIBLE STUDY
09/17 -   歷代志上 第二十一章
大衛在耶布斯人阿珥楠的禾場為耶和華築壇，獻燔祭和平安祭。耶和華應允，火從天降在燔祭壇上。耶和華的帳幕和燔祭壇在基遍的高處； 大衛不敢前去求問神，因為懼怕。 大衛說：這就是耶和華神的殿，為以色列人獻燔祭的壇。
意即，要以阿珥楠的禾場為基地建殿。
***哪裡怪怪的？***







__Cross compile with buildroot__
12. Download buildroot [link](https://buildroot.org/download.html) or `$ git clone git://git.buildroot.net/buildroot`
13. Decompress
14. Target options
```
Target Architecture (ARM (little endian))  --->
Target Binary Format (ELF)  --->
Target Architecture Variant (cortex-A17/A7 big.LITTLE)  --->
Target ABI (EABIhf)  --->
Floating point strategy (NEON)  --->
ARM instruction set (ARM)  ---> 
```


## 時間管理黃金法則
第一章  掌握時間，增加財富
1. 富人工作者與窮人工作者—大前研一的M型社會
2. 上班族的三大時間策略—郭台銘的鴻海帝國
3. 不疾而速的時間法則—李嘉誠的四句箴言
4. 時間管理的迷思與陷阱—彼得．杜拉克的時間管理
	* 杜拉克將時間管理的基本，整理成簡明的三個步驟： (1) 記錄並分析時間 (2) 管理時間 (3) 整合時間
	* Time is the scarcest resource and unless it is managed nothing else can be managed. Peter Drucker
5. 追求正值的休閒時間成長率—打敗負利率時代
6. 成功上班族必備的三大能力—銀行理專的九宮格
1．掌握時間，增加財富的通關測驗

第二章 時間管理策略
7. 三抓三放，簡化工作—熱愛時間的比爾蓋茲
8. 時間管理的微笑曲線—施振榮的微笑曲線
9. 重要與緊急的四象限圖—巴菲特的投資哲學
10. 同心圓的N字型法則—半導體業新人的四怕
	* X軸重要、Y軸緊急
	* 
12. 時間管理的四P與四C理念—企管行銷的四P與四C
13. 時間管理的微分與積分法則—何飛鵬的快速工作祕訣
．時間管理策略的通關測驗

第三章 提升工作效率
13工作效率與環境干擾度—嚴長壽的提前一小時上班
14高效率的工作日程表—上班時間的乾坤大挪移
15提升工作效率的祕密武器—澳洲國家公園的螢火蟲
16工作飛輪的四大動力—王建民的隧道視野
17提升工作效率的「SMART」法則—希臘神話的普羅米修斯
18職場達人的工作導電材—Google張成秀的時間競賽
．提升工作效率的通關測驗

第四章 控管上班時間
19控管時間的「CSDA」原則—侯文詠的怪盜大床
20管理時間的「辦公室三幫手」—星巴克總經理的時間筆記
21減少開會的「四制」概念—張忠謀的三類會議
22正向應對會議的四大法則—哈佛大學的心理測驗
23縮短開會時間的方法—穿著Prada的惡魔
．控管上班時間的通關測驗

第五章 製造上班時間
24製造生命與工作的時間—挑戰命運的最後演講
25製造藍海時間的方法—時間管理的「藍海策略」
26善用零碎時間的祕訣—何薇玲董事長的時間管理
27重疊時間配置法—《關鍵下一秒》的分身
28時間與金錢的巧妙轉換—謝震武的寶貴時間
．製造上班時間的通關測驗

第六章 節省上班時間
29同類法則的應用概念—《星際大戰》的絕地武士
30節省時間的四象限圖—夏韻芬的三把刀
31電子郵件及雜務的處理原則—Wii的「減法策略」
32節約無效益的等待時間—時間差攻擊法
33節約時間的真正人生意義—成功鑽石商人的圓圈日
．節省上班時間的通關測驗


## MEMORY LEAK
* history: 2018/09/11 ~
* OOM

### references
1. wiki [link](https://en.wikipedia.org/wiki/Memory_leak)
### how to debug? tools?




## HI3519V101 SPI PORT
* 2018/09/04 ~
* adopt low level driver src code from mxic website

sample code: Documentation/spi/spidev_test.c
tools hi_spi.h


## KOCHA and UDEV

c285/src/dvsdk-demos_4_02_00_01/dm365/interface/avm/
* kocha_debug.h
* kocha_interface.h
* kocha_impl.c
* kocha_primary.c
* kocha_internal.h

### mdev_mount2.sh
* a script brought up by mdev; just like disk-hotplug.sh and usbdev-hotplug.sh in udev of hi3519v101 SDK
* /etc/mdev.conf calls mdev_mount2.sh
* check NTFS for dirty

### NETLINK
* Netlink socket family
* Linux核心介面（Linux kernel interfaces）
* 可用於行程間通訊，Linux内核与用户空间的进程间、用户进程间的通讯
* 不可像网络套接字用于主机间通讯
* 只能用于同一主机上进程通讯，并通过PID来标识它们
* communication between kernel and user space (AF_NETLINK)

**libudev** — API for enumerating and introspecting local devices
  * libudev Reference Manual [link](http://presbrey.scripts.mit.edu/doc/libudev/)
  * sample code [link](https://github.com/robertalks/udev-examples) example 2 talks about block devices
  * **Can programs writen in libudev work with mdev?** 
    * Yes. 
    * refer to section 19.8.1 busybox mdev - Hallinan, Embedded Linux Primer 2e
    * how to replace udev in Linux with mdev [link](https://wiki.gentoo.org/wiki/Mdev)
* references:
  * Linux Programmer's Manual               NETLINK(7)
  * 
### UDEVADM
* udev的管理工具
``````````````````````````````````````````````````````````````````````````
# udevadm monitor --kernel --property --udev
``````````````````````````````````````````````````````````````````````````
``````````````````````````````````````````````````````````````````````````
# udevadm info --query=path --name=/dev/sda
# udevadm info -q path -n /dev/sda
/devices/soc/10120000.ehci/usb3/3-1/3-1.1/3-1.1:1.0/host0/target0:0:0/0:0:0:0/bl
ock/sda
```
```
# udevadm info -a -p `udevadm info -q path -n /dev/sda
```````````````````````````````````````````````````````````````````````````
* /etc/udev/rules.d/11-usb-hotplug.rules
```````````````````````````````````````````````````````````````````````````
#
# Create By Czy
#

KERNEL=="sd*", SUBSYSTEM=="block", RUN+="/etc/udev/disk-hotplug.sh"
KERNEL=="usbdev*", SUBSYSTEM=="usb_device", RUN+="/etc/udev/usbdev-hotplug.sh"
```````````````````````````````````````````````````````````````````````````
```````````````````````````````````````````````````````````````````````````
# blkid /dev/sda1
/dev/sda1: UUID="6A2E-6397"
```````````````````````````````````````````````````````````````````````````



Mounting Partitions Automatically [link](https://help.ubuntu.com/community/AutomaticallyMountPartitions)

ntfsprogs [link](https://en.wikipedia.org/wiki/Ntfsprogs)


NTFS-3G Read-Write NTFS Driver [link](https://www.tuxera.com/community/open-source-ntfs-3g/)
The latest stable version is ntfs-3g_ntfsprogs-2017.3.23, released on March 28, 2017.
ntfs-3g_ntfsprogs-2017.3.23$ ./configure CC=arm-hisiv500-linux-gcc --host=arm-hisiv500-linux

reading c285 code from dvsdk-demos_4_02_00_01/dm365/interface

kocha_main_thread()
* avm/kocha_primary.c
* a thread function


## HOW TO DETERMINE [WHICH MODE THE SD CARD IS RUNNING
* history: 2018/09/13 In SI test, Bill asked which SD card mode he was testing and observing on oscilloscope. hi3519v101 supports several. But which one 






```````````````````````````````````````````````````````````````````````````


```````````````````````````````````````````````````````````````````````````
2018/08/31 FRI

```````````````````````````````````````````````````````````````````````````

```````````````````````````````````````````````````````````````````````````
2018/08/30 THU

http://sikulix.com/


setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),123M(rootfs) init=/sbin/init.sh ip=dhcp




```````````````````````````````````````````````````````````````````````````
```````````````````````````````````````````````````````````````````````````
2018/08/29 WED

libphy: hisi_gemac_mii_bus: probed
hi_gmac_v200 10050000.ethernet (unnamed net_device) (uninitialized): using random MAC address b6:94:d0:cb:26:e7
attached PHY 1 to driver Generic PHY, PHY_ID=0x1cc916
higmac: ETH MAC supporte CCI.
Higmac dma_sg_phy: 0x8eb00000
ETH: rgmii, phy_addr=1

of_get_mac_address
is_valid_ether_addr

/**
 * Search the device tree for the best MAC address to use.  'mac-address' is
 * checked first, because that is supposed to contain to "most recent" MAC
 * address. If that isn't set, then 'local-mac-address' is checked next,
 * because that is the default address.  If that isn't set, then the obsolete
 * 'address' is checked, just in case we're using an old device tree.
 *
 * Note that the 'address' property is supposed to contain a virtual address of
 * the register set, but some DTS files have redefined that property to be the
 * MAC address.
 *
 * All-zero MAC addresses are rejected, because those could be properties that
 * exist in the device tree, but were not set by U-Boot.  For example, the
 * DTS could define 'mac-address' and 'local-mac-address', with zero MAC
 * addresses.  Some older U-Boots only initialized 'local-mac-address'.  In
 * this case, the real MAC is in 'local-mac-address', and 'mac-address' exists
 * but is all zeros.
*/

在device_get_mac_address 中一次检查mac-address/local-mac-address/address 这三个字串。
https://blog.csdn.net/tiantao2012/article/details/73658061

setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),123M(rootfs) ip=dhcp eth=${ethaddr}

ethaddr=${ethaddr} ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off



$ ARCH=arm CROSS_COMPILE=arm-hisiv500-linux- make menuconfig
$ ARCH=arm CROSS_COMPILE=arm-hisiv500-linux- make uImage -j8
hi_gmac_v200 10050000.ethernet (unnamed net_device) (uninitialized): using random MAC address

setenv bootargs mem=512M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=jffs2 rw mtdparts=hi_sfc:1M(boot),3M(kernel),28M(rootfs) ip=dhcp


a003257@a003257:~/avm/se5820/src/osdrv/opensource/uboot/u-boot-2010.06$ ARCH=arm CROSS_COMPILE=arm-hisiv500-linux- make env
http://shyuanliang.blogspot.com/2013/12/uboot-fwprintenv-fwsetenv.html

mount -t nfs -o nolock 192.168.1.100:/share /mnt
/mnt # ifconfig eth0 hw ether 00:18:1A:FF:A1:08
/mnt # ifconfig eth0 up

tmp=`/root/fw_printenv ethaddr`
tmp2=`echo $str | tr "=" "\n"`
for tmp3 in $tmp2
do
echo $tmp3
done
ifconfig eth0 down
ifconfig eth0 hw ether $tmp3
ifconfig eth0 up




```````````````````````````````````````````````````````````````````````````
```````````````````````````````````````````````````````````````````````````
2018/08/28 (TUE)

setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),123M(rootfs) ip=192.168.1.10:192.168.1.100:192.168.1.1:255.255.255.0::eth0:off



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

setenv ipaddr 192.168.1.10; setenv serverip 192.168.1.100; mw.b 82000000 ff 100000; tftp 82000000 u-boot_se5820v0.bin; nand erase 0 100000; nand write 82000000 0 100000

setenv ipaddr 192.168.1.10; setenv serverip 192.168.1.100; setenv bootcmd 'nand read 82000000 100000 400000; bootm 82000000'; setenv bootargs mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw mtdparts=hinand:1M(boot),4M(kernel),123M(rootfs); saveenv; reset

mw.b 82000000 ff f00000; tftp 82000000 uImage;nand erase 100000 400000; nand write 82000000 100000 400000; mw.b 82000000 ff 3000000; tftp 82000000 rootfs_hi3519v101_2k_4bit.yaffs2; nand erase 500000 3000000; nand write.yaffs 82000000 500000 c0a680



ip=192.168.1.10:192.168.1.103:192.168.1.1:255.255.255.0::eth0:off
ip=dhcp

http://lists.busybox.net/pipermail/busybox/2005-February/013688.html



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
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTM2NjY2NjgxNF19
-->