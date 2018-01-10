#!/bin/sh

module="skeleton"
device="sk"

# rmmod
/sbin/rmmod $module $* || exit 1

# Remove nodes
#rm -f /dev/${device}-[0-3]
rm -f /dev/${device}-0
