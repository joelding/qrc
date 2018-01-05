# Makefile

ifneq ($(KERNELRELEASE),)
	obj-m += skeleton.o
#	skeleton-objs := main.o

# Cannot use wildcard in kernel module makefile - Stack Overflow
# reference https://stackoverflow.com/questions/18041772/cannot-use-wildcard-in-kernel-module-makefile	
	SRCS := $(notdir $(wildcard $M/*.c))
	skeleton-objs := $(SRCS:.c=.o)
else
#	ARCH := arm
	CC := arm-hisiv500-linux-

ifeq ($(ARCH),arm)
	KDIR := /home/a003257/avm/t533c/T533C_40/osdrv/opensource/kernel/linux-3.18.y
else
	KDIR := /lib/modules/`uname -r`/build
endif

all:

ifeq ($(ARCH),arm)
	ARCH=$(ARCH) CROSS_COMPILE=$(CC) $(MAKE) V=1 -C $(KDIR) M=$$PWD modules
else
	$(MAKE) V=1 -C $(KDIR) M=$$PWD modules
endif

clean:

ifeq ($(ARCH),arm)
	ARCH=$(ARCH) CROSS_COMPILE=$(CC) $(MAKE) V=1 -C $(KDIR) M=$$PWD clean
else
	$(MAKE) V=1 -C $(KDIR) M=$$PWD clean
endif

endif
