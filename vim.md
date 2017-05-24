# VIM

## history
  2017/05/08 init

## install
```
$ git clone https://github.com/tpope/vim-pathogen.git ~/tmp
$ cp -r ~/tmp/autoload ~/.vim/
$ git clone https://github.com/scrooloose/nerdtree.git ~/.vim/bundle/nerdtree
$ git clone https://github.com/wesleyche/SrcExpl.git
$ git clone https://github.com/vim-scripts/taglist.vim.git
$ wget http://cscope.sourceforge.net/cscope_maps.vim
```
  
## generic settings for .vimrc
```
"~/.vim/autoload/pathogen.vim
execute pathogen#infect()
syntax on
filetype plugin indent on

set nu
set hlsearch
set colorcolumn=80
set cino=(0
set foldmethod=syntax
set foldlevel=99
set clipboard=unnamed
colo desert

let g:NERDTreeWinPos = "right"

"screxpl.vim
nmap <F9> :ScrExplToggle<CR>
"~/.vim/plugin/taglist.vim
nmap <F10> :TlistToggle<CR>
"~/.vim/bundle/NERD_tree.vim
nmap <F11> :NERDTreeToggle<CR>
```

## references
1. https://github.com/scrooloose/nerdtree