# Embedded Linux

開發筆記

##### 如何在板子上debug一個會發生segmentation fault的程序？
* Download source code of gdb from official site (or mirror) GDB: The GNU Project Debugger [link](https://www.gnu.org/s/gdb/)
* Example from hisilicon to build ncurses and gdb.
``````````````````````
TOOLS_TOP_DIR := $(shell pwd)
TOOL_TAR_BALL := gdb-7.9.1.tar.gz
TOOL_TAR_BALL2 := ncurses-6.0.tar.gz
TOOL_NAME := gdb-7.9.1
TOOL_NAME2 := ncurses-6.0
TOOL_BIN := inst
TOOL_BIN2 := bin
OSDRV_CROSS ?= arm-hisiv500-linux
OSDRV_CROSS_CFLAGS ?= -mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4
all:
	-rm $(TOOLS_TOP_DIR)/$(TOOL_NAME) -rf;
	-rm $(TOOLS_TOP_DIR)/$(TOOL_NAME2) -rf;
	tar -xf $(TOOL_TAR_BALL2);
	mkdir -p $(TOOLS_TOP_DIR)/$(TOOL_BIN)/;
	pushd $(TOOLS_TOP_DIR)/$(TOOL_NAME2)/; \
		./configure --host=$(OSDRV_CROSS) CFLAGS="$(OSDRV_CROSS_CFLAGS)" \
		LDFLAGS="$(OSDRV_CROSS_CFLAGS)" --prefix=$(TOOLS_TOP_DIR)/$(TOOL_BIN)/; \
		make -j > /dev/null; \
		make install;\
	popd;
	tar -xf $(TOOL_TAR_BALL);
	mkdir -p $(TOOLS_TOP_DIR)/$(TOOL_BIN)/;
	pushd $(TOOLS_TOP_DIR)/$(TOOL_NAME)/; \
		./configure --host=$(OSDRV_CROSS) CFLAGS="$(OSDRV_CROSS_CFLAGS) -lm"\
		LDFLAGS="$(OSDRV_CROSS_CFLAGS)" --disable-tui\
		LDFLAGS=-L$(TOOLS_TOP_DIR)/$(TOOL_BIN)/lib --prefix=$(TOOLS_TOP_DIR)/$(TOOL_BIN2); \
		make -j > /dev/null; \
		make install;\
	popd;
	cp $(TOOLS_TOP_DIR)/$(TOOL_NAME)/gdb/gdb $(TOOLS_TOP_DIR)/gdb-$(OSDRV_CROSS) -rf; \

.PHONY: clean
clean:
	-pushd $(TOOLS_TOP_DIR)/$(TOOL_NAME)/ &&\
	make -C $(TOOLS_TOP_DIR)/$(TOOL_NAME)/ clean && \
	popd
	-pushd $(TOOLS_TOP_DIR)/$(TOOL_NAME2)/ &&\
	make -C $(TOOLS_TOP_DIR)/$(TOOL_NAME2)/ clean && \
	popd

.PHONY: distclean
distclean:
	-rm $(TOOLS_TOP_DIR)/$(TOOL_NAME) -rf;
	-rm $(TOOLS_TOP_DIR)/$(TOOL_NAME2) -rf;
	-rm $(TOOLS_TOP_DIR)/$(TOOL_BIN) -rf;
	-rm $(TOOLS_TOP_DIR)/$(TOOL_BIN2) -rf;
	-rm $(TOOLS_TOP_DIR)/gdb-$(OSDRV_CROSS) -rf;
``````````````````````

##### 如何在嵌入式板子上使用PC Ubuntu的dhclient來得到IP？ 2018/08/10
busybox可以使用udhcpc，即micro-hdcp-client。但udhcpc要到IP後，要寫向interface。Felix Lin給出了這樣的script
`````````````
#!/bin/sh
 
# udhcpc script edited by Tim Riker <Tim@Rikers.org>
 
[ -z "$1" ] && echo "Error: should be called from udhcpc" && exit 1
 
RESOLV_CONF="/etc/resolv.conf"
[ -n "$broadcast" ] && BROADCAST="broadcast $broadcast"
[ -n "$subnet" ] && NETMASK="netmask $subnet"
 
case "$1" in
  deconfig)
    /sbin/ifconfig $interface 0.0.0.0
    ;;
 
  renew|bound)
    /sbin/ifconfig $interface $ip $BROADCAST $NETMASK
 
    if [ -n "$router" ] ; then
      echo "deleting routers"
      while route del default gw 0.0.0.0 dev $interface ; do
        :
      done
 
      for i in $router ; do
        route add default gw $i dev $interface
      done
    fi
 
    echo -n > $RESOLV_CONF
    [ -n "$domain" ] && echo search $domain >> $RESOLV_CONF
    for i in $dns ; do
      echo adding dns $i
      echo nameserver $i >> $RESOLV_CONF
    done
    ;;
esac
 
exit 0
`````````````
`````````````
# udhcpc -i eth1 -s udhcpc.sh
`````````````
參考資料：
1. BusyBox 應用 – udhcpc by Felix Lin [link](http://felix-lin.com/linux/busybox-%E6%87%89%E7%94%A8-udhcpc/)
