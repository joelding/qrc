# VIDEO DEMYSTIFIED
溫習、筆記、2018/11/01起

## SDI
- Ken Chih presented on 2018/11/28 KM
## HDMI 2.1
- 

**history**
- Eric Yao presented on 2018/11/28 KM

**references**
1. HDMI spec 2.1 overview [link](https://hdmiforum.org/wp-content/uploads/2017/01/HDMI_Forum_2.1SpecOverview_Jan2017_English.pdf)

Gamma correction
ref: [link](https://en.wikipedia.org/wiki/Gamma_correction)
* a nonlinear operation used to encode and decode __luminance__
* $V$~out~$=$$AV$~in~$^\gamma$
* 


## 1. Introduction to Video
 - Analog vs. Digital 
 - Video Data : RGB; composite video signal: Y, R-Y, G-Y; S-Video: Y or gray-scale, C or chroma; YPbPr
 - Digital Video : RGB: digitized version of analog RGB; YCbCr: digitized version of YPbPr
 - Video Timing : vertical sync: a new image is starting;  horizontal sync : a new scan line is starting
 - Video Resolution :  number of horizontal samples, vertical scan lines
 - Standard-Definition 
 - Enhanced-Definition 
 - High-Definition
 - Audio and Video Compression 
 - Application Block Diagrams 
 - DVD Players
 - Digital Media Adapters 
 - Digital Television Set-Top Boxes
## 3. Color Spaces
intuitive notions: hue/saturation/brightness
 - RGB Color Space: used in computer graphics and displays
 - sRGB
 - scRGB
 - YUV Color Space: used in video systems
 - YIQ Color Space 
 - YCbCr Color Space
 - RGB-YCbCr Equations: SDTV
 - RGB-YCbCr Equations: HDTV 
 - 4:4:4 YCbCr Format
 - 4:2:2 YCbCr Format
 - 4:1:1 YCbCr Format
 - 4:2:0 YCbCr Format
 - xvYCC Color Space
 - PhotoYCC Color Space 
 - HSI, HLS, and HSV Color Spaces
 - Chromaticity Diagram 
 - Non-RGB Color Space Considerations 
 - Gamma Correction 
 - Constant Luminance Problem 
 - References
## 4. Video Signals Overview
 - Digital Component Video Background: ITU-R BT.601, YCbCr or R'G'B'
   - Coding Ranges: the nominal 8-bit Y levels are 16–235, while the nominal 8-bit CbCr levels are 16–240; occasional excursion is ok, but never at the 0 and 255 levels. 0x00, 0xFF are reserved for timing information; 0x0000~0x0003, 0x3FC~0x3FF
- SDTV Sample Rate Selection
    - Y sampled at 13.5MHz; CbCr, 6.75MHz
   - 4:2:2 YCbCr 4×, 2×, and 2× 3.375 MHz
   - 480i: 858 samples/line; 576i: 864 samples/line; 720 active samples/line
   - aspect ratio 4:3 by using 13.5MHz; 16:9 by using 18MHz sample rate
- EDTV Sample Rate Selection
  - ITU-R BT.1358 
  - 480p, 576p
  - sample rate 27MHz for 4:3, 36MHz for 16:9
- HDTV Sample Rate Selection
  - ITU-R BT.709 
  - 720p, 1080i, 1080p
 - 480i and 480p Systems
 - 576i and 576p Systems
 - 720p Systems
 - 1080i and 1080p Systems
 - Other Video Systems
 - References

## 5. Analog Video Interfaces


- S-Video Interface
SCART Interface
SDTV RGB Interface
HDTV RGB Interface
Constrained Image
SDTV YPbPr Interface
VBI Data for 480p Systems
VBI Data for 576p Systems
HDTV YPbPr Interface
VBI Data for 720p Systems
VBI Data for 1080i Systems
Constrained Image
D-Connector Interface
Other Pro-Video Analog Interfaces
VGA Interface
References
## 6. Digital Video Interfaces
## 7. Digital Video Processing
- intro: deinterlace vs noninterlaced-to-interlaced conversion; frame rate conversion; video scaling; alpha mixing, chroma keyring; user control of contrast, hue, saturation, brightness
- Rounding Considerations (techniques) for example, 16 bits to 8 bits or 32 bits to 16 bits) in order to realize a cost-effective hardware implementation
  - Truncation
  - Conventional Rounding: round up or round down on the fractional data bits
  - Error Feedback Rounding: “never throw anything away”
  - Dynamic Rounding


- SDTV-HDTV YCbCr Transforms: SDTV and HDTV applications have different colorimetric characteristics. Thus, when SDTV (HDTV) data is displayed on an HDTV (SDTV) display, the YCbCr data should be processed to compensate.
  - SDTV to HDTV
  - HDTV to SDTV

- 4:4:4 to 4:2:2 YCbCr Conversion
- Display Enhancement
  - Brightness, Contrast, Saturation (Color), and Hue (Tint)
  - Color Transient Improvement
  - Luma Transient Improvement
  - Sharpness
  - Blue Stretch
  - Green Enhancement
  - Dynamic Contrast
  - Color Correction
  - Color Temperature Correction
- Video Mixing and Graphics Overlay
- Luma and Chroma Keying
  - Luminance Keying
  - Chroma Keying
  - Superblack and Luma Keying
- Video Scaling
Pixel Dropping and Duplication
Linear Interpolation
Anti-Aliased Resampling
Display Scaling Examples
Scan Rate Conversion
Frame or Field Dropping and Duplicating
Temporal Interpolation
2:2 Pulldown
3:2 Pulldown
3:3 Pulldown
24:1 Pulldown
Noninterlaced-to-Interlaced Conversion
Scan Line Decimation
Vertical Filtering
Interlaced-to-Noninterlaced Conversion
Video Mode: Intra-Field Processing
Video Mode: Inter-Field Processing
Film Mode
Frequency Response Considerations
DCT-Based Compression
Fixed Pixel Display Considerations
Expanded Color Reproduction
Detail Correction
Non-uniform Quantization
Scaling and Deinterlacing
References

## 8. NTSC, PAL, and SECAM Overview
## 9. NTSC and PAL Digital Encoding and Decoding
## 10. H.261 and H.263
## 11. Consumer DV
## 12. MPEG-1
## 13. MPEG-2
## 14. MPEG-4 and H.264
## 15. ATSC Digital Television
## 16. OpenCable Digital Television
## 17. DVB Digital Television
## 18. ISDB Digital Television
## 19. IPTV


## 參考書目

 1. Video Demystified: A Handbook for the Digital Engineer, 5th Edition by Keith Jack, Newnes  (May 14, 2007)
 2. Digital Video and HD: Algorithms and Interfaces (The Morgan Kaufmann Series in Computer Graphics) 2nd Edition by Charles Poynton, Morgan Kaufmann (February 7, 2012)
 3. Encyclopedia of Graphics File Formats, by James Murray [link](https://resources.oreilly.com/examples/9781565920583/tree/beb34c319e422d01ee485c5d423aad3bc8a69ce0)

> Written with [StackEdit](https://stackedit.io/).
