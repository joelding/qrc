# AUDIO CODEC
This file, starting from 2018-08-17, records user experience of operating audio codec chips.
#### TDM mode
* Time-divide multiplexing mode
* enabling data transfer over multiple codecs connecting to a single serial data bus
* 256-clock bit-clock mode
* offset
* The serial data output driver should be programmed as high-impedance state during all bit clocks except when valid data is being put onto the bus
* TLV320AIC3101: 
  * page 0/register 9/bit D3 bit clock rate contrl as 256-clock transfer mode used, resulting in 256 bit clocks per frame
