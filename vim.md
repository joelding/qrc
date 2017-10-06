# VIM

## history
  2017/05/08 init

## install
```
$ mkdir -p ~/.vim/autoload ~/.vim/bundle
$ curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim

$ git clone https://github.com/scrooloose/nerdtree.git ~/.vim/bundle/nerdtree

$ git clone https://github.com/wesleyche/SrcExpl.git
$ cp -r ./SrcExpl/plugin ./.vim/
$ cp -r ./SrcExpl/doc ./.vim/

$ git clone https://github.com/vim-scripts/taglist.vim.git
$ cp -r ./taglist.vim/plugin ./.vim/
$ cp -r ./taglist.vim/doc ./.vim/

$ wget http://cscope.sourceforge.net/cscope_maps.vim
$ cp cscope_maps.vim ./.vim/plugin/

```
  
## generic settings for .vimrc
```
execute pathogen#infect()
syntax on
filetype plugin indent on

set mouse=a
set nu
set hlsearch
set colorcolumn=80
set tabstop=4
set cino=(0
set foldmethod=syntax
set foldlevel=99
set clipboard=unnamed
set csre
colo desert
set tabstop=4
set shiftwidth=4
set softtabstop=0 noexpandtab

nmap <F9> :TlistToggle<CR>
nmap <F10> :SrcExplToggle<CR>
let g:NERDTreeWinPos="right"
nmap <F11> :NERDTreeToggle<CR>
```

## references
1. https://github.com/scrooloose/nerdtree
