# FILE SYSTEMS

2018年12月，SE5820板子陸續發生檔案系統毀損的現象。先前使用JFFS2時，就發生過問題。當時沒搞清楚問題所在。當必須面對問題時，發現認識不夠清楚。希望藉著這份筆記，釐清基本常識。

## Outline
 1. NAND 是怎樣運作？
 2. 檔案系統
 3. MTD
 4. 驅動 `TODO: https://www.kernel.org/doc/html/v4.14/driver-api/mtdnand.html`
 5. Hamming code, reed-solomum, binary BCH
 6. Why Hisilicon's fmc so special that it requires its own tools to make image?
 7. Software vs hardware ECC? How to play with software ECC?
 8. How to make an image using UBIFS
 9. What is NAND subpage? `https://www.crifan.com/what_is_subpage__sub-page_sub-pages_for_nand_flash/`

![enter image description here](http://wiki.csie.ncku.edu.tw/Flash_Construction_1.jpg)
W29N01HV
- __density__ 1G bit/128M byte, address 28
- __page size__ 2048+64 bytes
- __block size__ 64 pages/128K+4K bytes)
- __random read__ 25us
- __sequential read cycle__ 25us
- __page program__ 250us
- __block erase__ 2ms
---
## Add UBIFS support to u-boot (TODO)

reference: [UBIFS Support](http://processors.wiki.ti.com/index.php/UBIFS_Support)
Refer to [u-boot: load a kernel that's in a ubi volume](https://lists.ozlabs.org/pipermail/openbmc/2017-August/008630.html)

Added the following to u-boot/include/configs/xxx.h, But no extra commands were added to u-boot.
```
#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS
#define CONFIG_RBTREE
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_LZO
```
According to [README](https://github.com/lentinj/u-boot/blob/master/doc/README.ubi), the following commands should become available.
```
-------------------

UBI usage in U-Boot

-------------------
Here the list of the currently implemented UBI commands:
=> help ubi
ubi - ubi commands
Usage:
ubi part [part] [offset]
- Show or set current partition (with optional VID header offset)
ubi info [l[ayout]] - Display volume and ubi layout information
ubi create[vol] volume [size] [type] - create volume name with size
ubi write[vol] address volume size - Write volume from address with size
ubi read[vol] address volume [size] - Read volume to address with size
ubi remove[vol] volume - Remove volume
[Legends]
volume: character name
size: specified in bytes
type: s[tatic] or d[ynamic] (default=dynamic)
```



## Temp
2/20
* how to read a single sector from a partition https://stackoverflow.com/questions/1753067/read-a-single-sector-from-a-disk

2/19 cross compile util-linux
```
git checkout v2.33.1 #checkout by tag
git checkout -b v2.33.1 #checkout branch
$ ./configure --host=arm-hisiv500-linux --prefix=`pwd`/../install --without-tinfo --disable-rpath
$ make -L
```

```
/***
 * 12/28
 */
MLC壽命比較短： UBI wear-leveling threadhold: SLC用4096； MLC則用256
進入操作系統：
# ----- format MTD devices and flash UBI image
# ubiformat /dev/mtd3
# ----- attach MTD device to UBI -----
# ubiattach /dev/ubi_ctrl -m MTD_NUM [-d UBI_NUM] /dev/ubi_ctrl
# ----- create UBI volume -----
# ubimkvol UBI_DEVICE -N NAME -s SIZE 

/***
 * 12/27
 */
U-boot can read out nand 
# mw.b 82000000 ff 20 #just 32 bytes
# nand read 82000000 500000 20
# md 82000000 20
# nand read.oob 82000000 500000 20
# md 82000000 20

http://cmchao.logdown.com/posts/60216
出廠時即有問題的block，每個nand chip 都會標明這個型別的顆粒至少有多少block是可以用的，而且保証第一個block一定是好的，且第一個block在某個erase/program次數不會出問題(這是為了nand boot)。


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
```
How to remove GPT?
https://askubuntu.com/questions/211477/how-to-remove-gpt-from-hdd
Use gdisk expert mode
$ sudo gdisk /dev/sdc
GPT fdisk (gdisk) version 0.8.8

Partition table scan:
  MBR: protective
  BSD: not present
  APM: not present
  GPT: present

Found valid GPT with protective MBR; using GPT.

Command (? for help): x
Expert command (? for help): z
About to wipe out GPT on /dev/sdc. Proceed? (Y/N): y
Warning: The kernel is still using the old partition table.
The new table will be used at the next reboot.
GPT data structures destroyed! You may now partition the disk using fdisk or
other utilities.
Blank out MBR? (Y/N): Y
```
Remove all filesystems
```
$ sudo wipefs --all /dev/sdc
```
Create a partion-less FAT32
```
$ sudo mkfs.vfat -n 'TRANSCEND' -I /dev/sdc
mkfs.fat 3.0.26 (2014-03-07)

```

***

# KM 2019H1 逐字講稿
- 主標題：SE5820的檔案系統
- 次標題：閃存檔案系統：UBIFS設定、測試與除錯；外接檔案系統：偵測熱插拔、掛載、修復 、掛載、修復**[TODO]**
- scheduled presentation: 2019/04/10

### Outline
1. 閃存檔案系統：UBIFS設定、測試與除錯
	1. [Introduction to UBIFS](#Introduction to UBIFS)
	1. [Verify Flash Hardware and Drivers with mtd-utils](#Verify Flash Hardware and Drivers with mtd-utils) 
	1. [Encountered Issues](#Encountered Issues) 
1. 外接檔案系統：偵測熱插拔、掛載與修復
	1. [A Short Review of C285 KOCHA](#A Short Review of C285 KOCHA)
	1. [SE5820's Method](#SE5820's Method) 
	1. 

### 閃存原理
1. NOR Flash
  * Intel於1988年發表
  * 支援隨機存取，讀資料的方式跟RAM接近，給address，data就能讀出。NOR的特點是原地執行(XIP, eXecute In Place)，這樣應用程序可以直接在flash memory內運行，不必再把資料讀到系統RAM中
  * 每次寫入/擦除都是以1 block為單位;1 block = 16~128 KBytes
  * 小容量(1~4MB)時具有很高的成本效益，但是很低的寫入和擦除速度大大影響了它的性能
  * NOR flash佔據了容量為1～16MB閃存市場的大部分，因隨機存取快，應用在手機中
  * NOR的擦寫週期壽命是一萬~十萬次
  * 適合用於儲存不需經常更新的程式，例如BIOS或韌體
1. NAND Flash
  * Toshiba於1989年發表
  * 適用於大容量，更低的寫入和擦除時間，高密度(單元尺寸是NOR Flash的一半)，高壽命(10倍左右)，低製造成本
  * I/O pin只有8個，只允許連續讀取，所以不適合用於電腦主記憶體(不支援隨機存取)
  * 讀寫操作以1 page為單位，擦除(Erase)以1 block為單位
  * 1 block = 32 pages;每個block的單位依照廠商製造的不同有區別，介於8~32 KBytes之間
  * NAND擦除單元更小，因此擦除速度(4ms)比NOR的(5s)快
  * 適合於資料儲存，例如:MMC、固態硬碟(SSD)、USB 3.0隨身碟、手機、數位相機
  * 甚至手機、MP3撥放器用NAND Flash當作存放多媒體檔案的媒介，原因在於成本、空間、還有寫入資料的速度
  * NAND閃存中每個區塊的最大擦寫次數是一百萬次

### Introduction to UBIFS

UBIFS的全名是Unsorted Block Images File Systems。

為什麼要採用UBIFS？SE5820開始的時候，是跟著EC530B用JFFS2。（EC530B使用NOR FLASH）換到SE5820上NAND FLASH以後，開始發生檔案系統崩潰，接著就死機、系統再也無法成功開機。以為換成海思文件推薦的檔案系統可以解決問題，後來發現並非採用哪一種檔案系統的問題。

### Verify Flash Hardware and Drivers with mtd-utils
測試程式可以是應用程式的形式、也可以是驅動的形式。應用程式的形式，可以直接從板子的console去執行；驅動的形式，則使用insmod (insert module)，載入驅動即執行測試。若執行成功，則驅動會載入核心。想要再次測試，需要移除驅動。若執行成功，則會驅動載入失敗。
`Device Drivers" -> "Memory Technology Device (MTD) support" -> "MTD tests support"`



參考資料：[MTD tests](http://www.linux-mtd.infradead.org/doc/general.html#L_mtd_tests) 

### Encountered Issues

### A Short Review of C285 KOCHA

C285 磁碟偵測系統命名為 Kocha。命名由來是當時的經理 Mr Stylon Wang 說，他曾經到日本旅行，行經一地名叫 Kocha。日文 Kocha 也是紅茶的意思。後來幾位同事 Mr Williams Chang、Mr Dave Shau、Mr Leo Lin 等可能都修改維護過這套系統。以上是記憶中的印象。目前留下來的 KM，撰寫人 是Mr Williams Chang。

C285使用mdev，即busybox自帶、一個簡化版的udev。當裝置插拔時，daemon(常駐程式) mdev 從 config (組態)檔 mdev.conf得知呼叫 script(腳本)檔 mdev_mount2.sh 來處理插入的裝置。

當裝置插入時，mdev\_mount2.sh 將資訊`Add@/dev/sd[a..][1..]`印列在 `/tmp/my_fifo`檔裡。拔出時，則是`Remove@/dev/sd[a..][1..]`。`my_fifo` 只是一個暫時的文字檔，當作FIFO使用。另外一個 thread運行 `kocha_main_thread()` ，等著看 `my_fifo` 有無資料。一旦有新的資料，就取出資料，放在一個大小為 513 bytes 的 buffer (暫存區)，再進行處理。

當裝置插入，mdev\_mount2.sh 試著使用 "fdisk -l" 得知檔案系統是 NTFS 抑或是 FAT32。若是 NTFS，則檢查 NTFS 裝置是否曾經不正常移除。檢查 NTFS 的方法，是呼叫 `fsutil dirty query /dev/sd[a..][1..]`。修復 NTFS，則呼叫 chkntfs。若是 FAT，則不檢查，直接呼叫 fsck.vfat 檢查修復。fsck.vfat 則連接到 dosfsck 。

mdev_mount2.sh 的工作止於檢查、修復檔案系統，其餘的工作全部交給 kocha 處理，包括偵測、mount/umount 、取得詳細資訊。

Kocha 把 `kocha_main_thread()`放在 pthread 裡啟動。這個 pthread 的用途，是從 `/tmp/my_fifo`取出資訊，寫入buffer，然後處理。

其他有許多細節，可能很難逐一讀清楚。但所有操作的目的，不外乎把內核寫在`/proc`的資訊取出。所以很大量的代碼，都在parse字串。原因是mdev是用戶空間程序，處理熱插拔，基於uevent\_helper機制。uevent\_helper機制就是把插拔後的資訊，寫入`/proc`底下的檔案。

一個可能的簡化方法，是直接省去mdev熱插拔的處理，在`kocha_main_thread()`監聽netlink上的信息。當發生熱插拔的時候，自行處理事件即可。亦即：自己寫等同mdev功能的代碼。至於磁碟的資訊，包括先前使用是否有不正常插拔等等，也可以自行處理，無須呼叫fdisk之類的工具程式，關鍵在於：檔案系統的資訊、錯誤，就在磁碟這個存儲裝置上。讀取磁碟本身，就足夠獲取所有一手資訊。

參考資料：[udev和mdev hotplug事件](https://blog.csdn.net/shell_albert/article/details/46924299) 

摘要：
>udev和mdev是兩個使用uevent機制處理熱插拔問題的用戶空間程序，兩者的實現機理不同。udev是基於netlink機制的，它在系統啟動時運行了一個deamon程序udevd，通過監聽內核發送的uevent來執行相應的熱拔插動作，包括創建/刪除設備節點，加載/卸載驅動模塊等等。mdev是基於uevent\_helper機制的，它在系統啟動時修改了內核中的uevnet\_helper變量（通過寫`proc/sys/kernel/hotplug`，值為`/sbin/mdev`。這樣內核產生uevent 時會調用uevent\_helper所指的用戶級程序，也就是mdev，來執行相應的熱拔插動作。 udev 使用的netlink機制在有大量uevent的場合效率高，適合用在PC機上；而mdev使用的uevent\_helper機制實現簡單，適合用在嵌入式系統中。另外要說明的一點是,uevent\_helper 的初始值在內核編譯時時可配置的，默認值為`/sbin/hotplug`。如果想修改它的值，寫`/proc/sys/kernel/hotplug`文件就可以了，例如：`echo “/sbin/mdev” > /proc/sys/kernel/hotplug`

>補充一點：如果使用的是udevd,那麼uevent\_helper變量應為空，即`echo “ ” > /proc/sys/kernel/hotplug`

>這段內容總結的很好，我也看了linux內核有關uevent的代碼，的確是這樣，這樣看來簡單的將mdev看做udev的簡化版也就不准確了。這樣在做嵌入式的文件系統就要注意了，一般只會使用mdev，目前我還不確定能不能只用udev，理論上是可以的，當然兩種一起用也是可以的，也就是mdev + udev ，但是這時要注意了，寫規則時一定要注意，避免讓它們重複執行。也就是說udev執行過的，mdev不要再執行了。其實udev最大的特點就是使用了netlink，實質上是一個scoket，這個特別的scoket用來監測uevent，當然，我們也可以自己寫一個函數用來監測任何uevent事件。

### SE5820's Method

SE5820使用udev
