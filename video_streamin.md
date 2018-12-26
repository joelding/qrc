# 網絡音視頻核心開發技術
2018年10月份，因為公司專案開發人手不足的緣故，使得心中敏感的危機意識升高，也想好好學習怎樣在Linux嵌入式平台上開發video streaming的技術。但找到的書面資料有限，就算找到，是基於微軟平台。想寫公司訓練用、整理所學。


## Build GStreamer from source using Cerbero
1. Ubuntu 14.04 or older comes with older python. Latest cerbero needs python >= 3.5. 
   * install Python 3
`$ sudo apt-get install git curl build-essential`<br>`$ sudo apt-get install python3.5 python-dev` or add repository
`$ sudo add-apt-repository ppa:deadsnakes/ppa; sudo apt-get update`<br>`$ sudo apt-get install python3.5 python3.5-dev;`<br>`$ sudo rm /usr/bin/python3; sudo ln -s /usr/bin/python3.5 /usr/bin/python3`
   * For Python 3.x `$ sudo apt-get install python3-setuptools`
1. working directory: `workspace/cerbero`
2. Get a copy of Cerbero `git clone git://anongit.freedesktop.org/gstreamer/cerbero` , or clone from github `git clone https://github.com/freedesktop/gstreamer-cerbero.git`
3. Setup git `git config --global user.email "xxx@yyy.com"; git config --global user.name "XXX YYY"`<br>Get a copy of the configuration file in python [link](http://www.freedesktop.org/software/gstreamer-sdk/cerbero.cbc.template). Modify and put under `$HOME/.cerbero/cerbero.cbc` 
If it is missing, a message will show up: `WARNING: Using default configuration because /home/a003257/.cerbero/cerbero.cbc is missing`<br> To show the cross compile configure: `$ cerbero-uninstalled -c cross-lin-arm show-config`
4. List recipes `$ cerbero-uninstalled list`; list packages `$ cerbero-uninstalled list-packages`
5. Fire up `$ cerbero-uninstalled bootstrap`
6. Build a package `$ cerbero-uninstalled package gstreamer-1.0`
7. Clean everything `$ cerbero-uninstalled wipe`
8. Build an individual recipe and its dependencies ```
$ cerbero-uninstalled build <recipe_name>```
9. Build an individual recipe without its dependencies ```
$ cerbero-uninstalled buildone <recipe_name>```

**參考資料**
1. 官方文件 [link](https://gstreamer.freedesktop.org/documentation/installing/building-from-source-using-cerbero.html)
 
## GSTREAMER BASIC TUTORIAL
 - debug [link](https://gstreamer.freedesktop.org/documentation/tutorials/basic/debugging-tools.html)

|GST_DEBUG| levels |
|--|--|
| 0 | none |
| 1 | ERROR |
| 2 | WARNING |
| 3 | FIXME |
| 4 | INFO |
| 5 | DEBUG |
```
#export GST_DEBUG=2 #print both errors and warnings
```

## cross compile with hisiv500
10. edit a cbc file in config/cross-lin-hisiv500.cbc 
``` 
import os
from cerbero.config import Platform, Architecture, Distro, DistroVersion

target_platform = Platform.LINUX
target_distro = Distro.NONE_UCLIBC
target_arch = Architecture.ARMv7
variants = ['noalsa', 'nox11', 'nopulse', 'nocdparanoia', 'nosdl',
            'nov4l2', 'notestspackage', 'nopython']
host = "arm-hisiv500-linux"
tools_prefix = "arm-hisiv500-linux-"
```
11. confirm the configuration
`$ ./cerbero-uninstalled -c config/cross-lin-hisiv500.cbc show-config`

## 參考資料

 1. GStreamer official site [link](https://gstreamer.freedesktop.org/)
 2. Visual C++音频/视频处理技术及工程实践，  路锦正、  周冬梅， 电子工业出版社 2009
 3. 于广，  精通网络视频核心开发技术，  电子工业出版社 2011
 4. 张玲玲，  Visual C++音频/视频技术开发与实战，  清华大学出版社 2012
 5. Jack Jiang 技术福利：最全实时音视频开发要用到的开源工程汇总 [link](https://zhuanlan.zhihu.com/p/33663228)
 6. 从零开始学习音视频编程技术 [link](http://blog.yundiantech.com/)
 7. 精通Visual C++视频/音频编解码技术，  马兰、沈笑云、万棣， 人民邮电 2008-   __(精通Visual C++視訊/音訊編解碼技術 馬蘭,沈笑雲,萬棣,統一元氣資產管理 2009.01 新北圖書館)__

> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTIwNjY1Nzk3MzRdfQ==
-->