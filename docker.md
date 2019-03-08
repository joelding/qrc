# DOCKER
 1. [WHAT IS DOCKER](#what-is-docker)
 2. [TERMINOLOGIES](#terminologies)
 3. [INSTALL DOCKER](#install-docker)
 4. [COMMONLY USED COMMANDS](#commonly-used-commands)
 5. [DOCKERFILE EXAMPLES](#dockerfile-examples)
 6. [USE CASES](#use-cases)
	1. [TI DAVINCI SDK](#ti-davinci-sdk)
	2. [BUILD GSTREAMER WITH CERBERO FOR HISIV500](#build-gstreamer-with-cerbero-for-hisiv500)
 7. [REFERENCES](#references)

## WHAT IS DOCKER
* 新的虛擬化方式，比傳統的虛擬機啟動快、效能高。
* 開發人員使用已經設定好的映像檔，可以節省設定編譯環境的時間。
* 和傳統虛擬化方式的不同之處，可見容器是在作業系統層面上實作虛擬化，直接使用本地主機的作業系統，而傳統方式則是在硬體層面實作。

## TERMINOLOGIES
__映像檔（ image ）__
* 是一個唯讀的模板
* 可以是一個完整的 Ubuntu 作業系統環境，裡面安裝使用者需要的應用程式
* 可以用來建立容器

__容器（ container ）__
* 是從映像檔建立的執行實例
* 在唯讀的映像檔上建立一層可寫層
* 可以啟動、開始、停止、刪除
* 每個容器彼此隔離

__倉庫 （ repository ）__
* 集中存放映像檔檔案
* 倉庫分為公開（ Public ）和私有（ Private ）兩種
* 映像檔可以 push 上傳到倉庫

__倉庫註冊伺服器 （ Registry ）__
* 存放多個倉庫，每個倉庫中又包含了多個映像檔，每個映像檔有不同的標籤（ tag ）。




## INSTALL DOCKER
 * 在 Windows 、 macOS 、 Linux 上都可以使用Docker 。但對不同版本的操作系統，有不同的要求。例如在 Linux 上安裝 Docker 的條件，一定要 64 位元 Linux 、核心 3.10 以上。 
 * 準備
	* Ubuntu 14.04

```
$ sudo apt-get update
$ sudo apt-get install \
    linux-image-extra-$(uname -r) \
    linux-image-extra-virtual
```
```
$ ##### 安裝 Docker CE (Community Edition) #####
$ sudo apt-get update
$ sudo apt-get install apt-transport-https ca-certificates curl software-properties-common
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
$ sudo apt-get update
$ sudo apt-get install docker-ce # 安裝最新版本、或者
$ #apt-cache madison docker-ce # 列出可下的版本
$ #sudo apt-get install docker-ce=<VERSION> # 安裝指定版本
```
```
$ ##### 安裝後設定 #####
$ sudo usermod -aG docker $USER # 准許一般用戶使用 Docker，不必使用sudo。logout 後生效
$ sudo service docker start # 啟動 Docker 服務
$ ##### 安裝後測試 #####
$ docker pull hello-world
$ docker run hello-world
```
出現以下訊息則為成功：
```
Hello from Docker!
This message shows that your installation appears to be working correctly.
```

避免使用SSD做為docker的存儲裝置
`$ sudo vi /etc/systemd/system/docker.service.d/docker.root.conf`
```
[Service]
ExecStart=
ExecStart=/usr/bin/dockerd -g /new/docker/root -H fd://
```
```
$ sudo systemctl daemon-reload
$ sudo systemctl restart docker
$ sudo docker info - verify the root dir has updated
```
reference: [link](https://github.com/IronicBadger/til/blob/master/docker/change-docker-root.md) Friday, 08. March 2019 04:58PM 


## COMMONLY USED COMMANDS
|說明|指令  |
|--|--|
|查詢版本、組態|`$ docker info`|
|~~modify "Docker Root Dir: /var/lib/docker" to somewhere else~~|`$ rsync -aXS --progress /var/lib/docker/. /new/path/to/docker/.`<br>modify /etc/default/docker:<br> `# User DOCKER_OPTS to modify the daemon startup options`<br>`#DOCKER_OPTS="--dns 8.8.8.8 --dns 8.8.4.4"`<br>`DOCKER_OPTS="--dns 8.8.8.8 --dns 8.8.4.4 -g /new/path/to/docker"`<br> reference: [link](https://bobcares.com/blog/how-to-change-docker-directory/)<br>|
|查詢指令|`$ docker COMMAND --help`|
|用字串搜尋映像檔| `$ docker search NAME` |
|按前十名搜尋| `$ docker search -s 10 NAME` <br>例如：搜尋i386<br>`$ docker search i386/ubuntu` <br> `$ docker search 32bit/ubuntu`|
|search tags for a given image|__*TODO*__ log in https://hub.docker.com|and search|
|下載映像檔| `$ docker pull NAME:TAG`<br>例 `$ docker pull i386/ubuntu:trusty #14.04`|
|列出電腦上已有的映像檔| `$ docker images`|
|移除電腦上的映像檔| `$ docker rmi IMAGE`|
|利用 Dockerfile 全新建立映像檔| `$ docker build --no-cache -t="REPOSITORY:TAG" .`|
|利用 Dockerfile 建立映像檔，使用 cache 加速。（注意，套件更新可能會造成問題）| `$ docker build -t="REPOSITORY:TAG" .`|
|列出所有容器| `$ docker ps -a`|
|新建、啟動容器、並掛載host volume<br>在容器中下 exit 命令來退出終端時，所建立的容器立刻終止。 |`$ docker run -v HOST_DIRECTORY:GUEST_DIRECTORY -t -i REPOSITORY:TAG /bin/bash`|
|新建並啟動容器| `$ docker run -t -i REPOSITORY:TAG /bin/bash`|
|若Dockerfile先寫好使用者，則新建、啟動容器、並掛載host volume，可用一般使用者而非root| `$ docker run -v HOST_DIRECTORY:GUEST_DIRECTORY -u <name|UID>[:<group|GID>] -w /home/<name|UID> -ti REPOSITORY:TAG /bin/bash`|
|用一般使用者login|先用root啟動一個容器，執行<br>`# useradd <name>`<br>`# mkdir -p /home/<name>`<br>`# cp /root/* /home/<name>/ #copy.bashrc .profile`<br>`# chown -R <name>:<group>`<br>`# usermod -a -G sudo <name>`<br>再開另一個視窗用使用者login `$ docker exec -u <name|UID> -it CONTAINER_ID /bin/bash`|
|Log in a started container|`$ docker exec -it CONTAINER_ID /bin/bash`|
|停止一個容器| `$ docker stop CONTAINER_ID`|
|啟動執行一個已經終止的容器| `$ docker start -ia CONTAINER_ID`|
|移除電腦上的容器| `$ docker rm CONTAINER_ID`|


## DOCKERFILE EXAMPLES
```
FROM ubuntu:14.04
#FROM ubuntu:16.04
MAINTAINER Joel Ding <joel.ding@avermedia.com>

# replace dash with bash
RUN echo "dash dash/sh boolean false" | debconf-set-selections
RUN DEBIAN_FRONTEND=noninteractive dpkg-reconfigure dash

# add capability to run 32-bit application programs
RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install --fix-missing
RUN apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386 

# Set timezone
ENV TZ=Asia/Taipei
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Clean up
RUN apt-get -y clean
RUN mkdir -p /home/workspace
RUN echo "docker container need to mount to /home/workspace"
#RUN rm /tmp/dvsdk
```
Dockerfile copy a directory from host to image
```
COPY /path/to/host/src /path/to/image/dest 
```
Change directory
```
WORKDIR /path/to/workdir
```
Install necessary packages on Ubuntu
```
RUN apt-get install -y pkg-config apt-utils build-essential curl libncurses5-dev autoconf automake
```
Install u-boot tools
```
## for 14.04
#RUN apt-get install uboot-mkimage 
## for 16.04
RUN apt-get install u-boot-tools 
```
## USE CASES
### TI DAVINCI SDK
```
#RUN apt-get install -y lib32z1 libelf-dev python libncurses5-dev texinfo dc autoconf libcrypt-ssleay-perl ccache quilt libusb-dev libexpect-perl mono-devel libdbus-glib-1-dev libgtk2.0-dev bison flex

# Specific for IPNC RDK
#RUN apt-get install -y bison flex libacl1-dev zlib1g-dev liblzo2-dev uuid-dev mtd-utils python lib32z1 

# Specific for EZSDK


# Install toolchain

RUN mkdir /opt/codesourcery

RUN echo "Install Codesourcery ARM compiler for TI DM368"
RUN curl -s -L "https://sourcery.mentor.com/public/gnu_toolchain/arm-none-linux-gnueabi/arm-2009q1-203-arm-none-linux-gnueabi-i686-pc-linux-gnu.tar.bz2" | bunzip2 -d --stdout | tar -C /opt/codesourcery -xf -
RUN curl -s -L "https://sourcery.mentor.com/sgpp/lite/arm/portal/package830/public/arm-none-eabi/arm-2009q1-161-arm-none-eabi-i686-pc-linux-gnu.tar.bz2" | bunzip2 -d --stdout | tar -C /opt/codesourcery -xf -
ENV PATH $PATH:/opt/codesourcery/arm-2009q1/bin

#RUN echo "Install Codesourcery ARM compiler for Linux/U-boot TI OMAP L138"
#RUN curl -s -L "https://sourcery.mentor.com/public/gnu_toolchain/arm-none-linux-gnueabi/arm-2009q3-67-arm-none-linux-gnueabi-i686-pc-linux-gnu.tar.bz2" | bunzip2 -d --stdout | tar -C /opt/codesourcery -xf -
#RUN echo "Install Codesourcery ARM compiler for bare-metal TI OMAP L138"
#RUN curl -s -L "https://sourcery.mentor.com/sgpp/lite/arm/portal/package5353/public/arm-none-eabi/arm-2009q3-68-arm-none-eabi-i686-pc-linux-gnu.tar.bz2" | bunzip2 -d --stdout | tar -C /opt/codesourcery -xf -
#ENV PATH $PATH:/opt/codesourcery/arm-2009q3/bin

#RUN echo "Install CodeSoucery ARM compiler for bare-metal"
#RUN curl -s -L "https://sourcery.mentor.com/public/gnu_toolchain/arm-none-linux-gnueabi/arm-2011.03-41-arm-none-linux-gnueabi-i686-pc-linux-gnu.tar.bz2" | bunzip2 -d --stdout | tar -C /opt/codesourcery -xf -
#RUN curl -s -L "https://sourcery.mentor.com/GNUToolchain/package8734/public/arm-none-eabi/arm-2011.03-42-arm-none-eabi-i686-pc-linux-gnu.tar.bz2" | bunzip2 -d --stdout | tar -C /opt/codesourcery -xf -

RUN echo "Set common path"
ENV PATH $PATH:.

# Install DVSDK
#ADD responses.txt /tmp/
#RUN curl -s -L "http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/dvsdk/DVSDK_4_00/4_02_00_06/exports/dvsdk_dm368-evm_4_02_00_06_setuplinux" > /tmp/dvsdk
#RUN chmod a+wrx /tmp/dvsdk
#RUN echo "dash dash/sh boolean false" | debconf-set-selections
#RUN DEBIAN_FRONTEND=noninteractive dpkg-reconfigure dash
# Non-interactive doesn't allow us to pass the real location of g++
#RUN mkdir -p /root/CodeSourcery/Sourcery_G++_Lite
#RUN ln -s /opt/codesourcery/arm-2009q1/bin /root/CodeSourcery/Sourcery_G++_Lite/bin
#RUN /tmp/dvsdk --forcehost --response-file /tmp/responses.txt --mode console

+++ setup login user +++
# Set USER env var, required for SDK build
ENV USER root

# same as host user $UID $USER
# TODO: how to pass host environment to dockerfile?
RUN useradd -u 1001 joel2
```
--- setup login user ---
### BUILD GSTREAMER WITH CERBERO FOR HISIV500
`$ docker pull i386/ubuntu:14.04`
`$ docker run -v ~/avm/docker_workspace:/root -ti i386/ubuntu:14.04 /bin/bash`
`# apt-get update`
`# apt-get install build-essential git python3.5 python3-setuptools -y`
`# git config --global user.email joel.ding@avermedia.com`
`# git config --global user.name "Joel Ding"`
`# git clone git://anongit.freedesktop.org/gstreamer/cerbero`
`# git checkout -b user_branch_name tag_name`
`# cd`
`# echo "alias ls='ls --color=auto'" >> .bashrc`
`# echo 'export PATH="/opt/hisi-linux/x86-arm/arm-hisiv500-linux/target/bin:$PATH"' >> .bashrc`
`# rm /usr/bin/python3; ln -s /usr/bin/python3.5 /usr/bin/python3`

`# apt-get install libc++6`
```
The following extra packages will be installed:
  gcc-4.8-multilib gcc-multilib lib64asan0 lib64atomic1 lib64gcc-4.8-dev
  lib64gcc1 lib64gomp1 lib64itm1 lib64quadmath0 libx32asan0 libx32atomic1
  libx32gcc-4.8-dev libx32gcc1 libx32gomp1 libx32itm1 libx32quadmath0
  linux-libc-dev-arm64-cross linux-libc-dev-armel-cross
  linux-libc-dev-armhf-cross linux-libc-dev-powerpc-cross
  linux-libc-dev-ppc64el-cross
The following NEW packages will be installed:
  gcc-4.8-multilib gcc-multilib lib64asan0 lib64atomic1 lib64gcc-4.8-dev
  lib64gcc1 lib64gomp1 lib64itm1 lib64quadmath0 libc6-amd64 libc6-arm64-cross
  libc6-armel-armhf-cross libc6-armel-cross libc6-armhf-armel-cross
  libc6-armhf-cross libc6-dbg libc6-dbg-arm64-cross libc6-dbg-armel-cross
  libc6-dbg-armhf-cross libc6-dbg-powerpc-cross libc6-dbg-ppc64el-cross
  libc6-dev-amd64 libc6-dev-arm64-cross libc6-dev-armel-armhf-cross
  libc6-dev-armel-cross libc6-dev-armhf-armel-cross libc6-dev-armhf-cross
  libc6-dev-powerpc-cross libc6-dev-ppc64-powerpc-cross
  libc6-dev-ppc64el-cross libc6-dev-x32 libc6-pic libc6-powerpc-cross
  libc6-ppc64-powerpc-cross libc6-ppc64el-cross libc6-prof libc6-x32
  libx32asan0 libx32atomic1 libx32gcc-4.8-dev libx32gcc1 libx32gomp1
  libx32itm1 libx32quadmath0 linux-libc-dev-arm64-cross
  linux-libc-dev-armel-cross linux-libc-dev-armhf-cross
  linux-libc-dev-powerpc-cross linux-libc-dev-ppc64el-cross
0 upgraded, 49 newly installed, 0 to remove and 1 not upgraded.
Need to get 53.3 MB of archives.
```
`../glib/gatomic.c:675:2: error: #error G_ATOMIC_LOCK_FREE defined, but incapable of lock-free atomics.` 
[link](https://mail.gnome.org/archives/commits-list/2011-October/msg06698.html) If G_ATOMIC_LOCK_FREE is defined, our atomic operations are guaranteed to
    be done in hardware. Otherwise,  atomic operations are mutex-emulated ones.
```
gconvert.c:59:2: error: #error GNU libiconv not in use but included iconv.h is from libiconv
 #error GNU libiconv not in use but included iconv.h is from libiconv
```
```
# [GNU libiconv not in use but included iconv.h is from libiconv](https://www.cnblogs.com/iplus/archive/2012/11/06/4467369.html)

#error GNU libiconv not in use but included iconv.h is from libiconv  
解决办法 ：  
./configure --enable-iconv=no --with-libiconv=gnu
```
---

### gdk-pixbuf failed at __libc_free, __libc_malloc, __libc_realloc
Those functions are a part of GNU C library (glibc) specific functions. Failing over uclibc is not a surprise. ref: Linux OS C/C++ Dynamic Memory Interface Replacement [link](https://www.threadingbuildingblocks.org/docs/help/tbb_userguide/Linux_C_Dynamic_Memory_Interface_Replacement.html) 
__*Further question: would it be possible to run gtk+ over uclibc?*__
```
/root/cerbero/build/sources/linux_arm/gdk-pixbuf-2.36.2/tests/pixbuf-lowmem.c:48: undefined reference to `__libc_free'
pixbuf-lowmem.o: In function `malloc':
/root/cerbero/build/sources/linux_arm/gdk-pixbuf-2.36.2/tests/pixbuf-lowmem.c:69: undefined reference to `__libc_malloc'
pixbuf-lowmem.o: In function `calloc':
/root/cerbero/build/sources/linux_arm/gdk-pixbuf-2.36.2/tests/pixbuf-lowmem.c:79: undefined reference to `__libc_malloc'
pixbuf-lowmem.o: In function `free':
/root/cerbero/build/sources/linux_arm/gdk-pixbuf-2.36.2/tests/pixbuf-lowmem.c:97: undefined reference to `__libc_free'
pixbuf-lowmem.o: In function `realloc':
/root/cerbero/build/sources/linux_arm/gdk-pixbuf-2.36.2/tests/pixbuf-lowmem.c:114: undefined reference to `__libc_realloc'
collect2: error: ld returned 1 exit status
make[3]: *** [pixbuf-lowmem] Error 1
make[3]: Leaving directory `/root/cerbero/build/sources/linux_arm/gdk-pixbuf-2.36.2/tests'
make[2]: *** [all] Error 2
make[2]: Leaving directory `/root/cerbero/build/sources/linux_arm/gdk-pixbuf-2.36.2/tests'
make[1]: *** [all-recursive] Error 1
make[1]: Leaving directory `/root/cerbero/build/sources/linux_arm/gdk-pixbuf-2.36.2'
make: *** [all] Error 2

Recipe 'gdk-pixbuf' failed at the build step 'compile'
```
```
Recipe 'gdk-pixbuf' failed at the build step 'compile'
Select an action to proceed:
[0] Enter the shell
[1] Rebuild the recipe from scratch
[2] Rebuild starting from the failed step
[3] Skip recipe
[4] Abort
3
[(54/87) libcroco -> fetch ]
-----> Fetching tarball http://ftp.gnome.org/pub/GNOME/sources/libcroco/0.6/libcroco-0.6.11.tar.xz to /root/cerbero/build/sources/local/libcroco-0.6.11/libcroco-0.6.11.tar.xz
[(54/87) libcroco -> extract ]
-----> Extracting tarball to /root/cerbero/build/sources/linux_arm/libcroco-0.6.11
Unpacking /root/cerbero/build/sources/local/libcroco-0.6.11/libcroco-0.6.11.tar.xz in /root/cerbero/build/sources/linux_arm
[(54/87) libcroco -> configure ]
-----> copying /root/cerbero/data/autotools/config.guess to /root/cerbero/build/sources/linux_arm/libcroco-0.6.11/config.guess
-----> copying /root/cerbero/data/autotools/config.sub to /root/cerbero/build/sources/linux_arm/libcroco-0.6.11/config.sub
[(54/87) libcroco -> compile ]
[(54/87) libcroco -> install ]
[(54/87) libcroco -> post_install ]
[(55/87) vala-m4 -> fetch ]
-----> Fetching tarball http://ftp.gnome.org/pub/GNOME/sources/vala/0.35/vala-0.35.2.tar.xz to /root/cerbero/build/sources/local/vala-m4-0.35.2/vala-0.35.2.tar.xz
[(55/87) vala-m4 -> extract ]
-----> Extracting tarball to /root/cerbero/build/sources/linux_arm/vala-0.35.2
Unpacking /root/cerbero/build/sources/local/vala-m4-0.35.2/vala-0.35.2.tar.xz in /root/cerbero/build/sources/linux_arm
[(55/87) vala-m4 -> configure ]
[(55/87) vala-m4 -> compile ]
[(55/87) vala-m4 -> install ]
[(55/87) vala-m4 -> post_install ]
[(56/87) gobject-introspection-m4 -> fetch ]
-----> Fetching tarball http://ftp.gnome.org/pub/GNOME/sources/gobject-introspection/1.50/gobject-introspection-1.50.0.tar.xz to /root/cerbero/build/sources/local/gobject-introspection-m4-1.50.0/gobject-introspection-1.50.0.tar.xz
[(56/87) gobject-introspection-m4 -> extract ]
-----> Extracting tarball to /root/cerbero/build/sources/linux_arm/gobject-introspection-1.50.0
Unpacking /root/cerbero/build/sources/local/gobject-introspection-m4-1.50.0/gobject-introspection-1.50.0.tar.xz in /root/cerbero/build/sources/linux_arm
[(56/87) gobject-introspection-m4 -> configure ]
[(56/87) gobject-introspection-m4 -> compile ]
[(56/87) gobject-introspection-m4 -> install ]
[(56/87) gobject-introspection-m4 -> post_install ]
[(57/87) librsvg -> fetch ]
-----> Fetching tarball http://ftp.acc.umu.se/pub/GNOME/sources/librsvg/2.40/librsvg-2.40.16.tar.xz to /root/cerbero/build/sources/local/librsvg-2.40.16/librsvg-2.40.16.tar.xz
[(57/87) librsvg -> extract ]
-----> Extracting tarball to /root/cerbero/build/sources/linux_arm/librsvg-2.40.16
Unpacking /root/cerbero/build/sources/local/librsvg-2.40.16/librsvg-2.40.16.tar.xz in /root/cerbero/build/sources/linux_arm
[(57/87) librsvg -> configure ]
//////////////////////////////omitted//////////////////////////////
checking for native Win32... no
checking for LIBRSVG... no
configure: error: Package requirements (	gdk-pixbuf-2.0 >= 2.20 	glib-2.0 >= 2.12.0 	gio-2.0 >= 2.24.0 	libxml-2.0 >= 2.7.0 	pangocairo >= 1.32.6 	cairo >= 1.2.0 	cairo-png >= 1.2.0
        libcroco-0.6 >= 0.6.1) were not met:

No package 'gdk-pixbuf-2.0' found
```
---
**Recipe 'webrtc-audio-processing' failed at the build step 'compile'**
uclibc does not have bessel function!
```
beamformer/covariance_matrix_generator.cc: In function 'float webrtc::{anonymous}::BesselJ0(float)':
beamformer/covariance_matrix_generator.cc:24:14: error: 'j0' was not declared in this scope
   return j0(x);
              ^
beamformer/covariance_matrix_generator.cc:26:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^
make[3]: *** [beamformer/libwebrtc_audio_processing_la-covariance_matrix_generator.lo] Error 1
```
---
**--target=arm-linux-gcc hinders compiling libvpx** 
libvpx supports only a number of targets. Ref: section 5 cross development of README [link](https://github.com/webmproject/libvpx) --target=armv7-linux-gcc. --target=arm-linux-gcc is not an option.
```
[(37/87) libvpx -> configure ]
Running command './configure --prefix=/root/cerbero/build/dist/linux_arm --libdir=/root/cerbero/build/dist/linux_arm/lib --enable-pic --as=yasm --disable-unit-tests --size-limit=16384x16384 --enable-postproc --enable-multi-res-encoding --enable-temporal-denoising --enable-vp9-temporal-denoising --enable-vp9-postproc --enable-shared  --disable-examples --target=arm-linux-gcc '
  enabling pic
  disabling unit_tests
  enabling postproc
  enabling multi_res_encoding
  enabling vp9_temporal_denoising
  enabling vp9_postproc
  enabling shared
  disabling examples
  enabling vp8_encoder
  enabling vp8_decoder
  enabling vp9_encoder
  enabling vp9_decoder
Unrecognized toolchain 'arm-linux-gcc'
```
---
**需指定平台 ARCH=arm** [link](http://english0815.blogspot.com/2016/05/archarm.html)
```
[(44/87) openh264 -> compile ]
Running command 'make libraries'
arm-hisiv500-linux-g++  -Wall -g -O2 -Wl,-rpath-link=/root/cerbero/build/dist/linux_arm/lib  -Wall -g -O2 -Wl,-rpath-link=/root/cerbero/build/dist/linux_arm/lib  -O3 -DNDEBUG -m64 -DX86_ASM -Wall -fno-strict-aliasing -fPIC -MMD -MP -DGENERATED_VERSION_HEADER  -Wall -g -O2 -Wall -g -O2 -I./codec/api/svc -I./codec/common/inc -Icodec/common/inc   -c -o codec/common/src/common_tables.o codec/common/src/common_tables.cpp
arm-hisiv500-linux-g++: error: unrecognized command line option '-m64'
make: *** [codec/common/src/common_tables.o] Error 1
```
---
```
gstdvbsrc.c: In function 'gst_dvbsrc_modulation_get_type':
gstdvbsrc.c:308:6: error: 'QAM_4_NR' undeclared (first use in this function)
     {QAM_4_NR, "QAM 4 NR", "qam-4-nr"},
      ^
gstdvbsrc.c:308:6: note: each undeclared identifier is reported only once for each function it appears in
make[3]: *** [libgstdvb_la-gstdvbsrc.lo] Error 1
make[3]: Leaving directory `/root/cerbero/build/sources/linux_arm/gst-plugins-bad-1.0-1.12.4/sys/dvb'
make[2]: *** [dvb] Error 2
make[2]: Leaving directory `/root/cerbero/build/sources/linux_arm/gst-plugins-bad-1.0-1.12.4/sys'
make[1]: *** [all-recursive] Error 1
make[1]: Leaving directory `/root/cerbero/build/sources/linux_arm/gst-plugins-bad-1.0-1.12.4'
make: *** [all] Error 2

Recipe 'gst-plugins-bad-1.0' failed at the build step 'compile'

```
---
__libtool: Version mismatch error.__
```
libtool: Version mismatch error.  This is libtool 2.4.6, but the libtool: definition of this LT_INIT comes from libtool 2.4.2. libtool: You should recreate aclocal.m4 with macros from libtool 2.4.6
```
```
autoreconf --force --install
./configure
make
```
---
__a52dec.o: undefined reference to symbol 'pow'__
```
/opt/hisi-linux/x86-arm/arm-hisiv500-linux/bin/../lib/gcc/arm-hisiv500-linux-uclibcgnueabi/4.9.4/../../../../arm-hisiv500-linux-uclibcgnueabi/bin/ld: a52dec.o: undefined reference to symbol 'pow'
/opt/hisi-linux/x86-arm/arm-hisiv500-linux/bin/../target/lib/libm.so.0: error adding symbols: DSO missing from command line
collect2: error: ld returned 1 exit status
make[1]: *** [a52dec] Error 1
```
[uClibc]About using uClibc pow(double,double) function ref: [link](http://lists.busybox.net/pipermail/uclibc/2001-December/023094.html)
See also uClibc-ng [link](https://uclibc-ng.org/)

---
**libunwind failed - lacking execinfo.h**
see also [link](https://github.com/capnproto/capnproto/issues/510)
```
test-coredump-unwind.c:60:22: fatal error: execinfo.h: No such file or directory
 #include <execinfo.h>
                      ^
compilation terminated.
make[1]: *** [test-coredump-unwind.o] Error 1
make[1]: Leaving directory `/root/cerbero/build/sources/linux_arm/libunwind-1.1/tests'
make: *** [all-recursive] Error 1

Recipe 'libunwind' failed at the build step 'compile'
```
---
__gst-plugins-good-1.0-static lacks gdk-pixbuf__
```
Recipe 'gst-plugins-good-1.0-static' failed at the build step 'post_install'
Traceback (most recent call last):
  File "./cerbero/build/oven.py", line 143, in _cook_recipe
    stepfunc()
  File "/root/cerbero/recipes/custom.py", line 102, in post_install
    shutil.copyfile(src, dest)
  File "/usr/lib/python2.7/shutil.py", line 82, in copyfile
    with open(src, 'rb') as fsrc:
IOError: [Errno 2] No such file or directory: '/root/cerbero/build/sources/linux_arm/gst-plugins-good-1.0-static-1.12.4/static-build/root/cerbero/build/dist/linux_arm/lib/gstreamer-1.0/libgstgdkpixbuf.a'
```
---
__gst-plugins-ugly-1.0-static failed without building a52dec__
```

Recipe 'gst-plugins-ugly-1.0-static' failed at the build step 'post_install'
Traceback (most recent call last):
  File "./cerbero/build/oven.py", line 143, in _cook_recipe
    stepfunc()
  File "/root/cerbero/recipes/custom.py", line 102, in post_install
    shutil.copyfile(src, dest)
  File "/usr/lib/python2.7/shutil.py", line 82, in copyfile
    with open(src, 'rb') as fsrc:
IOError: [Errno 2] No such file or directory: '/root/cerbero/build/sources/linux_arm/gst-plugins-ugly-1.0-static-1.12.4/static-build/root/cerbero/build/dist/linux_arm/lib/gstreamer-1.0/libgsta52dec.a'


```
---

`# apt-get install libstdc++6:i386 gcc-multilib g++-multilib`
`# apt-get install  python3.5-dev libncurses5-dev`

海思的toolchain可能有選項預設不打開，導致gstreamer/cerbero無法用預設的方法編譯。可能要用減法的方法，把不會過的部份disable掉。

## REFERENCES
 1. Philip Zheng, Docker —— 從入門到實踐 [link](https://philipzheng.gitbooks.io/docker_practice/content/)
 2. Get Docker CE for Ubuntu [link](https://docs.docker.com/install/linux/docker-ce/ubuntu/)


> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEzNDA4NTU3MTddfQ==
-->