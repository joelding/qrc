QUICK REFERENCE CARD for COMMONLY USED LINUX COMMANDS

History
	17/04/01	init


$ scp username@[IP ADDRESS]:[PATH]/[FILE] [DEST] 由遠端主機複製檔案至本機
$ scp [FILE] username@[IP ADDRESS]:[PATH] 將檔案由本機複製到遠端主機

Ubuntu 64位元系統執行32位元程式
$ sudo dpkg --add-architecture i386
$ sudo apt-get update
$ sudo apt-get install libc6:i386 libstdc++6:i386 libncurses5:i386
$ sudo apt-get install zlib1g-dev:i386 # if necessary

$ du -sh ./folder_path #estimate file space usage in human readable format

$ scp username@[IP ADDRESS]:[PATH]/[FILE] [DEST]

Setup NFS server
$ sudo apt-get install nfs-kernel-server
$ sudo mkdir -m 777 /nfs
$ sudo cat "/nfs *(rw,sync,no_root_squash,subtree_check)" > /etc/exports
$ sudo service nfs-kernel-server restart

Create a md5sum file for downloaded files placed in a directory
$ md5sum * > MD5SUM



