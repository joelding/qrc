A record of installing a new ubuntu system 16.04

## history
	2017/05/06	init

## 重裝新系統
```
$ sudo apt-get install git gitk vim ctags cscope build-essential manpages-dev manpages-posix-dev
$ sudo vim /etc/default/grub # comment GRUB_CMDLINE_LINUX_DEFAULT
$ sudo update-grub
$ sudo adduser a003257
```
## Install GStreamer on Ubuntu or Debian
```
$ apt-get install libgstreamer1.0-0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools
```
## x64操作系統相容x86軟體
```
$ sudo dpkg --add-architecture i386
$ sudo apt-get install libc6:i386 libstdc++6:i386 libncurses5:i386 
```
## 使用tty裝置
```
$ sudo adduser second_user dialout
```
## Install a window manager
```
$ sudo apt-get install lubuntu-desktop 
$ sudo apt-get install lubuntu-core
$ sudo apt-get install openbox xinit
$ exec openbox-session; startx
$ sudo apt-get install virtualbox
$ sudo usermod -a -G vboxsf <username> # add an existing user to vbox group
```
## Install Inconsolata font
```
$ sudo apt-get install fonts-inconsolata
```
Install docker https://docs.docker.com/engine/installation/linux/ubuntu/
```
$ sudo apt-get install curl
```
## VirtualBox/Ubuntu Guest 設定 Host Only + NAT 網卡連通內外網路
* reference: http://www.arthurtoday.com/2013/07/ubuntu-guest-enables-nat-and-hostonly-adapter.html
* VirtualBox 的 Host Only 網卡的預設網段是 192.168.56.0
```
$ lspci
00:03:0 Ethernet controller ... => enp0s3
00:08:0 Ethernet controller ... => enp0s8
```
Add the following lines to /etc/network/interfaces
```
auto enp0s8
iface enp0s8 inet static
address 192.168.56.88
network 192.168.56.0
netmask 255.255.255.0
```
```
$ sudo apt-get install openssh-server
```
## sudo 出現 unable to resolve host 錯誤解法
* https://blog.longwin.com.tw/2008/11/linux-sudo-unable-to-resolve-host-2008/
```
$ sudo vim /etc/hosts
```
add 127.0.0.1 <hostname>

## Ubuntu 安裝 NFS Serve
```
$ sudo apt-get install nfs-kernel-server
$ mkdir /nfs_share
$ chmod -R 777 /nfs_share
$ sudo vim /etc/exports
```
## 目錄可讀寫，同步寫入，用戶進入後即變為root
```
/nfs_share 203.68.230.*(rw,sync,no_root_squash,no_subtree_check)
$ sudo exportfs -r #更新
$ sudo /etc/init.d/nfs-kernel-server restart #重啟nfs服務
```
## 客戶端下指令：
```
$ mount -t nfs 10.1.9.158:/nfs_share /mnt
```
## show all boot process
Modify /etc/default/grub. Change GRUB\_CMDLINE\_LINUX\_DEFAULT="splash quiet" to "". Then, run update-grub.
