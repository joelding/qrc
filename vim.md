# VIM

## history
  2017/05/08 init
  
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

"screxpl.vim
nmap <F9> :ScrExplToogle<CR>
"~/.vim/plugin/taglist.vim
nmap <F10> :TlistToogle<CR>
"~/.vim/bundle/NERD_tree.vim
nmap <F11> :NERDTreeToogle<CR>
```
