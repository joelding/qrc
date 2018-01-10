#!/bin/sh

module="skeleton"
device="sk"
mode="664"

group="a003257"

# insmod
/sbin/insmod ./$module.ko $* || exit 1

# retrieve major number
major=$(awk "\$2==\"$module\" {print \$1}" /proc/devices)

#rm -f /dev/${device}-[0-3]
rm -f /dev/${device}-0
mknod /dev/${device}-0 c $major 0
chgrp $group /dev/${device}-0
chmod $mode /dev/${device}-0
