# FLASH MEMORY AND EMBEDDED FILE SYSTEMS
2018年12月，SE5820板子陸續發生檔案系統毀損的現象。先前使用JFFS2時，就發生過問題。當時沒搞清楚問題所在。當必須面對問題時，發現認識不夠清楚。希望藉著這份筆記，釐清基本常識。
## Outline

 1. NAND 是怎樣運作？
 2. 檔案系統
 3. MTD
 4. 驅動

![enter image description here](http://wiki.csie.ncku.edu.tw/Flash_Construction_1.jpg)
W29N01HV
- __density__ 1G bit/128M byte, address 28
- __page size__ 2048+64 bytes
- __block size__ 64 pages/128K+4K bytes)
- __random read__ 25us
- __sequential read cycle__ 25us
- __page program__ 250us
- __block erase__ 2ms


## Temp
```
/***
 * 12/27
 */
U-boot can read out nand 
# mw.b 82000000 ff 20 #just 32 bytes
# nand read 82000000 500000 20

/**************************
 * 12/26
 **************************/

https://stackoverflow.com/questions/37407667/ubi-error-ubi-io-read-error-74-ecc-error
use nand erase ..., not nand scrub ...

https://bootlin.com/blog/creating-flashing-ubi-ubifs-images/

UBI
Unsorted Block Images
an abstraction layer for MTD devices


    the eraseblocks (PEB) ;
    the pages (or “minimum input/output size”) ;
    the subpages (it may be the same as the min i/o size) ;


mkfs.ubifs

https://blog.csdn.net/csdn66_2016/article/details/72769887
u-boot: 
  nand erase
  nand write
linux 
  flash_erase
  ubiformat /dev/mtd/mtd4 -f ubi.img


http://lists.infradead.org/pipermail/linux-mtd/2010-July/031106.html
Flashing UBI-images should not use nandwrite.
Note that ubiformat is still the preferred flashing method if the image is not being flashed for the first time, since it preserves existing erase counters (while using nandwrite or its equivalent does not).

https://elinux.org/UBIFS
```

```
/**************************
 * 12/25
 **************************/

Q: HW chip with ECC has "syndrome"???


in Makefile
	CFLAGS_[].o := -DDEBUG
for pr_debug()

```






```
/**************************
 * 12/24
 **************************/

arch/arm/configs/se5820v0_nand_defconfig


# insmod mtd_nandbiterrs.ko dev=6

==================================================
mtd_nandbiterrs: MTD device: 6
mtd_nandbiterrs: MTD device size 54525952, eraseblock=131072, page=2048, oob=64
mtd_nandbiterrs: Device uses 1 subpages of 2048 bytes
mtd_nandbiterrs: Using page=0, offset=0, eraseblock=0
mtd_nandbiterrs: incremental biterrors test
mtd_nandbiterrs: write_page
mtd_nandbiterrs: rewrite page
mtd_nandbiterrs: read_page
mtd_nandbiterrs: verify_page
mtd_nandbiterrs: Successfully corrected 0 bit errors per subpage
mtd_nandbiterrs: Inserted biterror @ 0/5
mtd_nandbiterrs: rewrite page
mtd_nandbiterrs: read_page
mtd_nandbiterrs: error: read failed at 0x0
mtd_nandbiterrs: After 1 biterrors per subpage, read reported error -74
mtd_nandbiterrs: finished successfully.
==================================================


Makefile CFLAGS_[nand_base].o := -DDEBUG

struct mtd_oob_ops {
	unsigned int	mode;
	size_t		len;
	size_t		retlen;
	size_t		ooblen;
	size_t		oobretlen;
	uint32_t	ooboffs;
	uint8_t		*datbuf;
	uint8_t		*oobbuf;
};
```
```

/**************************
 * 12/21
 **************************/


nand-ecc-mode osdrv/opensource/kernel/linux-3.18.y/Documentation/devicetree/bindings/mtd/nand.txt
nand-bus-width
nand-on-flash-bbt
nand-ecc-strength
nand-ecc-step-size




good intro: MUST READ CAREFULLY
https://developer.ridgerun.com/wiki/index.php/Introduction_to_Nand_Memories
```



```
/**************************
 * 12/20
 **************************/

https://linux-mtd.infradead.narkive.com/xfvpiET6/ubifs-crc-error-calculated-from-ubifs-check-node

git clone git://git.infradead.org/mtd-utils.git



NAND erase: device 0 offset 0x500000, size 0x3400000
Skipping bad block at-   7% complete.
0x00900000
Erasing at 0x38e0000 -- 100% complete.
OK
nand write 0x82000040 0x500000 0x2c00000

NAND write: device 0 offset 0x500000, size 0x2c00000
pure data length is 46137344, len_incl_bad is 46268416
data length:0x2c00000, include bad block length: 0x2c20000
Skip bad block 0x00900000
 46137344 bytes written: OK
ETH0: PHY(phyaddr=1, rgmii) link UP: DUPLEX=FULL : SPEED=100M
MAC:   00-00-23-34-45-66
TFTP from server 192.168.1.2; our IP address is 192.168.1.100
Download Filename 'userfs'.
Download to add

sudo apt install zlib1g-dev liblzo2-dev uuid-dev
https://stackoverflow.com/questions/44721738/mtd-utils-2-0-0-1-configure-error-lzo-missing


CC=/opt/hisi-linux/x86-arm/arm-hisiv500-linux/target/bin/arm-hisiv500-linux-gcc ./configure  --host=arm-hisiv500-linux --with-ubifs --with-jffs --without-lzo

/********************************************
 * 使用linux的MTD tests support测试flash性能
 ********************************************/
https://blog.csdn.net/gp_scoprius/article/details/53257056

mtd_nandecctest.ko：nand flash的ECC校验测试

mtd_pagetest.ko：nand flash的page读写测试

mtd_speedtest.ko：MTD分区的读写速度测试

mtd_subpagetest.ko：nand flash的sub-page接口测试

mtd_oobtest.ko：nand falsh的OOB区域读写测试

mtd_readtest.ko：读取整个MTD分区

mtd_stresstest.ko：随机读写，擦除操作测试

mtd_torturetest.ko：该功能可用于做稳定性或者寿命测试，随机操作直到发生错误


http://www.linux-mtd.infradead.org/doc/general.html#L_mtd_tests

mtd-utils:
a set of test programs 
to verify your flash hardware and drivers
available as user space programs as well as kernel modules.

--------------------- 
作者：gp_scorpius 
来源：CSDN 
原文：https://blog.csdn.net/gp_scoprius/article/details/53257056 
版权声明：本文为博主原创文章，转载请附上博文链接！
```

> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbNTc3OTM5NDg5LC0xMTY3NzA3MzQ4LC0xNz
gzOTE1ODIyLDc5MDExODc0NCwxNzgyNDI1ODM0LDE2NTc2NTY3
MzUsMTA0NDc5MzU4NiwtMTQ0MjExMDU1Ml19
-->