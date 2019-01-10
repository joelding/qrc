# EMBEDDED LINUX

 1. I always dream that I can become free from the shackles of KEIL ...

## Building a Root Filesystem
**How to make a jffs2/ubifs read-only filesystem?**
2018/11/21 while handling 0x1985 issue**

### References
 1. Chris Simmonds (2015), *Mastering Embedded Linux Programming* , PACKT
 2. Hallinan (2011), *Embedded Linux primer: a practical real-world approach*, Pearson Education, Inc
 3. Yaghmour et al. (2008) *Building Embedded Linux Systems: Concepts, Techniques, Tricks, and Traps*, Second Edition, O'Reilly 
 4. jffs2_scan_inode_node(): Data CRC failed on node at … Read … calculated … https://www.crifan.com/question_jffs2_scan_inode_node__data_crc_failed_on_node_at__read__calculated_/

Q: Linux如何查看与/dev/input目录下的event对应的设备 2019/01/10
ref: [link](https://blog.csdn.net/MyArrow/article/details/10582667)
```
# cat /proc/bus/input/devices
```
code snippet for reading the /proc/bus/input/devices [link](https://github.com/kernc/logkeys/issues/89)

> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTI3NzQ1OTQ1NSwtOTcyNjM4NTczLDQ4Nz
g2NjU1OV19
-->