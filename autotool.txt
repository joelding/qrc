# AUTOTOOL

## History
* 2017/10/16 init

## Makefile assignment =, :=, +=, ?=
* = 是最基本的賦值 values within it are recursively expanded when the variable is used, not when it's declared
* := 會覆蓋變數之前的值 values within it are expanded at declaration time
* ?= 變數為空時才給值，不然則維持之前的值
* += 將值附加到變數的後面
```       
	x = hello
	y = $(x) world!
	x = hi
all:
	@echo $(y)
```
result: hi world!
```
	x := hello
	y := $(x) world!
	x := hi
all:
	@echo $(y)
```
result: hello world!

references:
* Makefile的賦值運算符(=, :=, +=, ?=) [link](http://dannysun-unknown.blogspot.tw/2015/03/makefile.html)
