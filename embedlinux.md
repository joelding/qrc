# Embedded Linux

開發筆記

### 如何在嵌入式板子上使用PC Ubuntu的dhclient來得到IP？ 2018/08/10
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
