
# INSTALL DEBIAN
Installing Debian as development host.
## Install
```
$ su
# apt-get install vim git gitk ctags cscope build-essential fonts-inconsolata curl
```
## Setup hotkeys
|Hotkey|Command|
|--|--|
| `<Alt>t`|lxterminal|

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
[ref](https://askubuntu.com/questions/211477/how-to-remove-gpt-from-hdd)

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
# usermod -aG sudo username
```





> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbOTMyNTQyMjM2LDIwNzAxNjQwOTAsMTYyND
U3MTg2MCwtMzEwMzMzOTUxLDkyNTgwMDc0NiwtODE0NzE5Nzk2
LDczMDk5ODExNl19
-->