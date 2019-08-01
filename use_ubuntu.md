# USE UBUNTU


## Setup Environment for Programming
- lxterminal (rather than xterm)
- git gitk
- curl
- vim ctags cscope
    - plugins安裝：
```
#安裝Vundle: Vim bundle, Vim 插件管理器
$ git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
$ cp ~/.vim/bundle/Vundle.vim/test/minirc.vim(or vimrc) ~/.vimrc
```
Add the following 
```
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
```
運行 vim 再運行 :PluginInstall 或通過命令列直接安裝 vim +PluginInstall +qall

- build-essential manpages-dev manpages-posix-dev
- 字型：fonts-inconsolata
- GStreamer編程：libgstreamer1.0-0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools
- mount SMB: install `cifs-utils`
```
$ sudo mount -t cifs //[ip address]/path /[mount point] -o username=[USERNAME],password=[PASSWD]
```