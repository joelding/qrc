# LINUX DEVICE DRIVERS
Q: How to know which user process called the ioctl of the driver so that I can trace the application program? 2019/01/07
A: __[ closed ]__
ref:  [Getting user process pid when writing Linux Kernel Module](https://stackoverflow.com/questions/11915728/getting-user-process-pid-when-writing-linux-kernel-module)
```
pid_nr(get_task_pid(current, PIDTYPE_PID));
```
Q: (continue the previous question) Is it possible to know which command or program  called the driver? 2019/01/07
A: __[ close ]__
ref: # [How does the Linux kernel knows which process made a system call?](https://unix.stackexchange.com/questions/364502/how-does-the-linux-kernel-knows-which-process-made-a-system-call)
maybe using `find_pid_ns()`. This is not verified.

## Chapter 1 设备驱动简介
### 驱动程序的角色
- 驱动程序的角色是提供机制（提供什么能力）, 而不是策略（如何使用这些能力）
- 将所有关于如何使用硬件的事情留给应用程序
### 内核的角色
- 可以划分成下列几个部分:
  - 进程管理
  - 内存管理
  - 文件系统
  - 设备控制
  - 网络 
- 可以在运行时扩展增加( 也可以去除 )Linux内核的能力
- 每块可以在运行时添加到内核的代码, 被称为一个模块. Linux 内核提供了对许多模块类型的支持, 包括但不限于, 设备驱动. 每个模块由目标代码组成( 没有连接成一个完整可执行文件 ), 可以动态连接到运行中的内核中
通过 insmod 程序, 以及通过 rmmod 程序去连接.
### 设备和模块的分类
 3 种基本设备类型
- 字符设备
- 块设备
- 网络接口
### 安全问题
### 版本编号
### 版权条款
### 加入内核开发社团
## Chapter 2 建立和运行模块
- 學習方法：建立, 加载, 和修改例子模块
- 實驗環境建議使用直接从 kernel.org 的镜像网络下載的标准、主流内核進行實驗
- 2.6之前只要有一套当前版本的头文件就足够了; 2.6 模块针对内核源码树里找到的目标文件连接，需要一个配置好并建立好的内核树
## Chapter 3 字符驱动

## 參考書目

 1. Linux Device Drivers, e/3, by Jonathan Corbet, Alessandro Rubini, and Greg Kroah-Hartman [link](http://lwn.net/Kernel/LDD3) e/2 [link](http://lwn.net/Kernel/LDD2)
 2. Linux 设备驱动 e/3 [link](http://www.deansys.com/doc/ldd3/)

> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbNjU3MjE4MTUwLC0yMzQ5MDYzMDUsLTExMj
gwNjAyMjddfQ==
-->