A record of installing a new ubuntu system 16.04

## history
	2017/05/06	init



Starting with default installation,
```
$ sudo apt-get install virtualbox

$ sudo apt-get install git gitk 
$ sudo apt-get install vim ctags cscope

$ sudo apt-get install openbox xinit
$ exec openbox-session; startx

```
Install docker https://docs.docker.com/engine/installation/linux/ubuntu/
$ sudo apt-get install curl

sudo dpkg --add-architecture i386
apt-get install libc6:i386 libstdc++6:i386 libncurses5:i386 

sudo adduser second_user dialout
sudo apt-get install manpages-dev manpages-posix-dev

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
netmask 255.255.255.0
network 192.168.56.0
```
## Install Inconsolata font
```
$ sudo apt-get install fonts-inconsolata
```
