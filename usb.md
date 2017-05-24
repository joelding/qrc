USB

target: this document collects summaries of learning USB

history:
	2017/05/02	init

http://wiki.csie.ncku.edu.tw/embedded/USB

USB由幾種Protocol Layers所組成，資料藉由Pipes傳輸。

Stream Pipes
可以被Host或者Device控制
資料的傳輸方向必須事先定義，定義為IN或或OUT

支援 Bulk Transfers, Isochronous Transfers, and Interrupt Transfers. (have no defined USB format)

Message Pipes
為Host控制來進行資料傳輸設定，允許雙向通訊。
只支援 Control Transfers。（have a defined USB format）


每個Endpoint只能有一個傳輸方向
Endpoint 0 例外，可以有IN和OUT的雙向傳輸（透過Message Pipe），用來控制裝置（Device)。

傳輸型態
控制傳輸（Control Transfers) ： 用於控制傳輸命令及狀態操作。像是設定裝置、取得裝置資訊、發送指令到裝置等。每個USB裝置都有一個Endpoint 0，USB Core就是使用他在裝置插入後進行設定。

中斷傳輸（Interrupt Transfers) ： 與一般常見的中斷不同，需要 host 端先詢問(Polling)才會執行。用一個固定速傳輸少量資料，像是USB鍵盤和滑鼠就是屬於這種方式。
    
批次傳輸（Bulk Transfers）：用於大量資料傳輸且需要確保資料無誤（如傳給印表機或隨身碟），沒有速度限制，若傳輸失敗就會重傳以確保正確。
    
同時傳輸（Isochronous Transfers) ： 同樣用於大量資料傳輸，但不確保資料是否到達。例如例如USB視訊裝置，使用者會期望傳輸聲音或影像的速率是穩定的，若有幾張frame遺失，沒有通過CRC資料也不會重傳。

packet 封包
* 是組成USB傳輸的最小單位
* 含有幾個「域」 field
* idle [Sync | Data Bytes | EOP] idle
  * Sync: 同步訊號/同步域 Synchronization Pattern 
  * Data Bytes: big-endian, LSB first
  * EOP: End of Packet
* PID type
  * token 令牌包
  * data 
  * handshake
  * special




Transaction 傳輸
* 指USB資料的傳輸
* 依傳輸型態而定，一個Transaction可能包含一個、兩個、三個封包
* 通大部分的傳輸常由三個封包組成 
[token packet | data packet | handshake/status packet]
* 可能是從Host傳向Device，或是從Device傳向Host。傳送方向是由Token packet中指定
* 利用Handshake(Status packet)判斷本次傳輸是否成功

為了確保同步，USB把時間切割成固定長度的小區間。低速和全速的時候是以 1 ms 為單位，稱為一個Frame；高速時再把一個Frame切成八等分，一個 0.125 ms 為單位，稱為microframes。

token package
* 每個Transaction以Token封包起始
* [PID | ADDR | ENDP | CRC5] 8, 7, 4, 5 bits
* OUT
* IN
* SOF
* SETUP
對於OUT和SETUP處理，位址與端點欄位用來選擇接收資料的端點。
對於IN處理，位址與端點欄位用來選擇傳送資料的端點。
[PID (SOF) | FrameNumber | CRC5] 8, 11, 5 bits

data package
[PID | DATA | CRC16] 8, 0-1023, 16 bits
low-speed裝置中，Data封包最大的資料量為8 bytes
full-speed裝置中，Data封包最大的資料量為1023 bytes
high-speed裝置中，Data封包最大的資料量為1024 bytes以上。其中 Data0 及 Data1 是兩個基本的資料封包，使用這些資料封包以提供一個機制來確定將傳送端和接收端之間的資料切換同步(data toggle synchronization)。另外在 USB2.0 當中更增加了 Data2 及 MData 資料封包，用於執行高速的即時傳輸(Isochronous Transfers)。

handshake package
除了即時型傳輸(Isochronous)外，所有的傳輸都保證資料的傳遞正確，如交握(Handshake)封包回應資料是否正確的被收到，若執行處理動作中發生錯誤，處理動作將重新執行。

Handshake封包由一個PID所組成，用來表示資料傳輸的狀態，部分Handshake封包說明如下。

ACK表示資料封包沒有bit stuff或是CRC錯誤，也就是PID欄位以及Data欄位沒有出現錯誤。
NAK表示裝置無法從主機接收資料或是無資料可以傳輸到主機。NAK也被當作流量控制的用途來使用，表示裝置暫時無資料傳送或無法接收資料。
STALL表示裝置無法傳送或接收資料，需要主機介入來清除延遲狀況。

[PID]

Thesycon USB Descriptor Dumper http://www.thesycon.de/eng/usb_descriptordumper.shtml


