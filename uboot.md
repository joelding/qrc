#U-BOOT
hands-on experience in u-boot. 2018/08/20
-------------------------------
#### KERNEL PARAMETER SETTING DYNAMIC OR STATIC IP IN U-BOOT
ip={ipaddr}:{serverip}:{gatewayip}:{netmask}:{hostname}:{interface}:off
ip=dhcp
``````````````````````````````````````````
setenv bootargs 'mem=256M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 rw 
mtdparts=hinand:1M(boot),4M(kernel),31M(rootfs),28M(test) ip=192.168.1.10::192.168.1.1:255.255.255.0::eth0:off'
``````````````````````````````````````````
