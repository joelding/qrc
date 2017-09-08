Docker 是新的虛擬化方式，比傳統的虛擬機啟動快、效能高。開發人員使用已經設定好的映像檔，可以節省設定編譯環境的時間。

基本概念：映像檔（ image ）
* 是一個唯讀的模板
* 可以是一個完整的 Ubuntu 作業系統環境，裡面安裝使用者需要的應用程式
* 可以用來建立容器

基本概念：容器（ container ）
* 是從映像檔建立的執行實例
* 在唯讀的映像檔上建立一層可寫層
* 可以啟動、開始、停止、刪除
* 每個容器彼此隔離

基本概念：倉庫 （ repository ）
* 集中存放映像檔檔案
* 倉庫分為公開（ Public ）和私有（ Private ）兩種
* 映像檔可以 push 上傳到倉庫

基本概念：倉庫註冊伺服器 （ Registry ）
* 存放多個倉庫，每個倉庫中又包含了多個映像檔，每個映像檔有不同的標籤（ tag ）。

Host PC 安裝 Docker：

在 Windows 、 macOS 、 Linux 上都可以使用Docker 。但對不同版本的操作系統，有不同的要求。例如在 Linux 上安裝 Docker 的條件，一定要 64 位元 Linux 、核心 3.10 以上。 Ubuntu 上安裝 Docker CE (Community Edition)
```
$ sudo apt-get update
$ sudo apt-get install apt-transport-https ca-certificates curl software-properties-common
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
$ sudo apt-get update
$ apt-cache madison docker-ce # 列出可下的版本
$ sudo apt-get install docker-ce # 安裝最新版本
$ sudo apt-get install docker-ce=<VERSION> # 安裝指定版本
```
Ubuntu 版本套件庫中內建 Docker 套件，可以直接安裝
```
$ sudo apt-get install docker.io
```
也可以加入 repository 隨時保持最新版本。安裝步驟與細節請自行按個人需求查閱官網。

安裝後設定：
```
$ sudo service docker start # 啟動 Docker 服務
$ sudo usermod -aG docker $USER # 准許一般用戶使用 Docker
```
安裝後測試：
```
$ docker pull hello-world
$ docker run hello-world
```
出現以下訊息則為成功：
```
Hello from Docker!
This message shows that your installation appears to be working correctly.
```
查詢指令：
```
$ docker –help
$ docker COMMAND --help
```
下載映像檔：
```
$ docker pull NAME
```
列出電腦上已有的映像檔：
```
$ docker images
```
利用 Dockerfile 建立映像檔：
```
$ docker build -t="REPOSITORY:TAG" .
```
列出所有容器：
```
$ docker ps -a
```
新建並啟動容器：
```
$ docker run -t -i REPOSITORY:TAG /bin/bash
```
新建、啟動容器、並掛載源碼目錄：
```
$ docker run -v LOCAL_DIRECTORY:MOUNT_DIRECTORY \
   -u `stat -c "%u:%g" LOCAL_DIRECTORY` \
   -t -i REPOSITORY:TAG /bin/bash
```
在容器中下 exit 命令來退出終端時，所建立的容器立刻終止。
```
$ docker run -v LOCAL_DIRECTORY:MOUNT_DIRECTORY --user USER -ti REPOSITORY:TAG /bin/bash
```
停止一個容器：
```
$ docker stop CONTAINER_ID
```
啟動執行一個已經終止的容器：
```
$ docker start -ia CONTAINER_ID
```
移除電腦上的容器：
```
$ docker rm CONTAINER
```
移除電腦上的映像檔：
```
$ docker rmi IMAGE
```
Dokerfile 範例
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
For building TI
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
