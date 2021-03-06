
# USE DEBIAN
Install, setup, and use Debian as development host.
## Install
```
$ su
# apt-get install vim git gitk ctags cscope build-essential fonts-inconsolata curl
```
## Default Hotkeys
* lxterminal `<Alt>t`
* Modify `~/.config/openbox/lxde-rc.xml`. Search for word "keybind".

## Format a new disk and move data
Umount the disk. Use `# cfdisk` to partition a new disk. Run `# mkfs.ext4 /dev/sda1` to format as ext4 file system.

https://help.ubuntu.com/community/Partitioning/Home/Moving
```
$ su
# blkid >> partition.log # Find the uuid of the Partitions
# cp /etc/fstab /etc/fstab.$(date +%Y-%m-%d) # backup fstab
# vim /etc/fstab
```
```
# (identifier) (location, eg sda5) (format, eg ext3 or ext4) (some settings)
UUID=xxxxx-xxxx-xxxx /media/home ext4 defaults 0 2
```
```
# mkdir /media/home # make a mount point
# mount -a
# rsync -aXS --progress --exclude='/*/.gvfs' /home/. /media/home/. # sync data
# diff -r /home /media/home -x ".gvfs/*" # Check Copying Worked ###
# vim /etc/fstab # Preparing fstab for the switch
```
```
# (identifier) (location, eg sda5) (format, eg ext3 or ext4) (some settings)
UUID=???????? /home ext4 defaults 0 2
```
## How to remove GParted disk?
reference: [link](https://askubuntu.com/questions/211477/how-to-remove-gpt-from-hdd)

`# gdisk /dev/sdX`
```
Command (? for help): x # for expert options

Expert command (? for help): z
About to wipe out GPT on /dev/sdx. Proceed? (Y/N): y
GPT data structures destroyed! You may now partition the disk using fdisk or
other utilities.
Blank out MBR? (Y/N): y
```

## How to create Gparted disk?

```
Command (? for help): ?
b	back up GPT data to a file
c	change a partition's name
d	delete a partition
i	show detailed information on a partition
l	list known partition types
n	add a new partition
o	create a new empty GUID partition table (GPT)
p	print the partition table
q	quit without saving changes
r	recovery and transformation options (experts only)
s	sort partitions
t	change a partition's type code
v	verify disk
w	write table to disk and exit
x	extra functionality (experts only)
?	print this menu

Command (? for help): o
This option deletes all partitions and creates a new protective MBR.
Proceed? (Y/N): y
```
```
# usermod -aG sudo username
```
## 安裝中文輸入法
```
$ su
# dpkg-reconfigure locales
[*] zh_TW.UTF-i UTF-8
```
* 中文輸入法框架有很多種，如 ibus, uim, scim, fctix 。`$ sudo apt-get install ibus ibus-chewing im-config` 
* 似乎沒有安裝額外字型的需要。若需要安裝以下：fonts-arphic-bkai00mp, fonts-arphic-bsmi00lp, fonts-arphic-gbsn00lp, fonts-arphic-gkai00mp, (optional) xfonts-intl-chinese, (optional) xfonts-intl-chinese-big
* im-setup 加入輸入法
* Reboot or log out the user

reference: [link](https://wiki.debian.org/gnome-chinese-input)

## Install Docker
* Reference: [link](https://docs.docker.com/install/linux/docker-ce/debian/)
* Follow instructions written in [install using the repository](https://docs.docker.com/install/linux/docker-ce/debian/#install-using-the-repository) Friday, 08. March 2019 03:10PM 




> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjA2MDQ4Njc1MiwyMDcwMTY0MDkwLDE2Mj
Q1NzE4NjAsLTMxMDMzMzk1MSw5MjU4MDA3NDYsLTgxNDcxOTc5
Niw3MzA5OTgxMTZdfQ==
-->
