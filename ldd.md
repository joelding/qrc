# LINUX DEVICE DRIVERS

### Target
* keynotes

### History
* 2018/07/13 init

### References
1. 

---------------------------------------------------------------------------

### How to create multiple instances, one for each device, with the same driver? 2018/07/13

* similar to what Lenz Moser asked [link](http://www.linuxforums.org/forum/kernel/132637-how-load-kernel-module-twice.html)
````````````````````
# insmod a.ko param=0
# insmod a.ko param=1
....
# insmod a.ko param=7
````````````````````

dev_alloc_name(<name>)

insmod: can't insert 'avt_tlv320aic31.ko': File exists

---------------------------------------------------------------------------

### 

---------------------------------------------------------------------------

### 

---------------------------------------------------------------------------

### 
