# SETUP LINUX COMPUTER


## install Lubuntu 14.04 LTS
 1. 使用bash不要dash <br>`$ sudo dpkg-reconfigure dash` choose NO.
 2. x64操作系統相容x86軟體<br> `$ sudo dpkg --add-architecture i386` 
 3. 慣用軟體與設定 <br>`$ sudo apt-get install vim git gitk ctags cscope build-essential manpages-dev manpages-posix-dev fonts-inconsolata curl`
 4. mount SMB  <br>`$ sudo apt-get install cifs-utils`<br> `$ sudo mount -t cifs //[ip address]/path /[mount point] -o username=[USERNAME],password=[PASSWD]`
 5. 使用tty裝置<br> `$ sudo apt-get install minicom`<br>`$ groups [user]; $ sudo adduser [user] dialout`
 6. VIM安裝plugins：<br>`$ git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim`<br> `$ cp ~/.vim/bundle/Vundle.vim/test/minirc.vim(or vimrc) ~/.vimrc`
 7. 設定 `~/.vimrc`<br> 
```
set nocompatible
syntax on
filetype off
set rtp+=~/.vim/bundle/Vundle.vim/
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'tpope/vim-pathogen'
Plugin 'scrooloose/nerdtree'
Plugin 'wesleyche/SrcExpl'
Plugin 'taglist.vim'
Plugin 'chazy/cscope_maps'
Plugin 'godlygeek/tabular'
Plugin 'plasticboy/vim-markdown'
call vundle#end()
filetype plugin indent on

execute pathogen#infect()

set mouse=a
set nu
set hlsearch
"set colorcolumn=80
"set textwidth=76
set cino=(0
set foldmethod=syntax
set foldlevel=99
set clipboard=unnamed
set csre
colo desert
"set tabstop=4
"set shiftwidth=4
"set softtabstop=0 noexpandtab

nmap <F5> :TlistToggle<CR>
nmap <F6> :SrcExplToggle<CR>
let g:NERDTreeWinPos="left"
nmap <F7> :NERDTreeToggle<CR>
```
Quit vim再運行 vim `:PluginInstall` 或通過命令列直接安裝`$ vim +PluginInstall +qall`

 1. Partitioning/Home/Moving ref: [link](https://help.ubuntu.com/community/Partitioning/Home/Moving)
```
$ sudo blkid >> partition.log # Find the uuid of the Partition
$ sudo cp /etc/fstab /etc/fstab.$(date +%Y-%m-%d) #backup fstab
```
Edit `$ sudo vim /etc/fstab`
```
# (identifier) (location, eg sda5) (format, eg ext3 or ext4) (some settings)
UUID=???????? /media/home ext4 defaults 0 2
```
Mount this disk
```
$ sudo mkdir /media/home
$ sudo mount -a
```
Copy /home to the New Partition
```
$ rsync -aXS --progress --exclude='/*/.gvfs' /home/. /media/home/.
# diff -r /home /media/home -x ".gvfs/*" #Check Copying Worked
# vim /etc/fstab #Preparing fstab for the switch
```
Now it is time to really mount the disk
```
# (identifier) (location, eg sda5) (format, eg ext3 or ext4) (some settings)
UUID=???????? /home ext4 defaults 0 2
```
9. Get Docker CE for Ubuntu
```
$ sudo apt-get remove docker docker-engine docker.io #Uninstall old versions
$ sudo apt-get update
$ sudo apt-get install linux-image-extra-$(uname -r) linux-image-extra-virtual #allow Docker to use the aufs storage drivers
$ sudo apt-get install apt-transport-https ca-certificates curl software-properties-common #allow apt to use a repository over HTTPS
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - #Add Docker’s official GPG key
$ sudo apt-key fingerprint 0EBFCD88 #Verify that you now have the key with the fingerprint
$ sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
$ sudo apt-get update #Update the apt package index.
$ sudo apt-get install docker-ce #Install the latest version of Docker CE
$ ##### 安裝後設定 #####
$ sudo usermod -aG docker $USER # 准許一般用戶使用 Docker，不必使用sudo。logout 後生效
$ sudo service docker start # 啟動 Docker 服務
$ ##### 安裝後測試 #####
$ docker pull hello-world
$ docker run hello-world
``` 
10. setup Openbox

To add a menu tag `$ cp /etc/xdg/openbox/menu.xml ~/.config/openbox/`
```
<item label="virtualbox">
<action name="Execute"><execute>virtualbox</execute></action>
</item>
```
To add a hotkey/keybind `$ cp /etc/xdg/openbox/rc.xml ~/.config/openbox/`
```
<!-- Keybindings for running applications -->
<keybind key="W-e">
<action name="Execute">
<command>firefox</command>
</action>
</keybind>
<!-- or x-www-browser -->
<keybind key="C-A-t">
<action name="Execute">
<command>lxterminal</command>
</action>
</keybind>
<!-- Keybindings for windows -->
<keybind key="W-s">
<keybind key="x">
<action name="ToggleMaximizeFull"></action>
</keybind>
<keybind key="m">
<action name="Iconify"></action>
</keybind>
```
11. exFAT (FAT64), extended file allocation table Linux 
    * 作業系統需要通過exfat工具支援exFAT [link](https://github.com/relan/exfat)
    * `$ sudo apt-get install exfat-utils exfat-fuse`
13. 
reference: The Debian menu [link](http://openbox.org/wiki/Help:Menus#The_Debian_menu)
## ARCH AMD64 CROSS COMPILE FOR I386
`$ sudo apt-get install libc6-i386-dev`
`$ gcc -Wall -m32 [source code]`

## history
| date | description |
|--|--|
| 2017/05/06 | init |
|2018/10/17|move to StackEdit|


> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTI2NDI0NjQ0OF19
-->