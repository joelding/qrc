# Image Processing
Thoughts of reviewing what I learned in school constantly come to my mind. But I never really got the chane to do so.

## History
  * 2017/10/20 init
  
## BMP, convert to NV12
* bitmap format: File Header + Info Header + (optional palette) + Raw Data
```
void Bitmap2Yuv420p_calc2(uint8_t *destination, uint8_t *rgb, size_t width, size_t height)
{
    size_t image_size = width * height;
    size_t upos = image_size;
    size_t vpos = upos + upos / 4;
    size_t i = 0;
    for( size_t line = 0; line < height; ++line )
    {
        if( !(line % 2) )
        {
            for( size_t x = 0; x < width; x += 2 )
            {
                uint8_t r = rgb[3 * i];
                uint8_t g = rgb[3 * i + 1];
                uint8_t b = rgb[3 * i + 2];

                destination[i++] = ((66*r + 129*g + 25*b) >> 8) + 16;

                destination[upos++] = ((-38*r + -74*g + 112*b) >> 8) + 128;
                destination[vpos++] = ((112*r + -94*g + -18*b) >> 8) + 128;

                r = rgb[3 * i];
                g = rgb[3 * i + 1];
                b = rgb[3 * i + 2];

                destination[i++] = ((66*r + 129*g + 25*b) >> 8) + 16;
            }
        }
        else
        {
            for( size_t x = 0; x < width; x += 1 )
            {
                uint8_t r = rgb[3 * i];
                uint8_t g = rgb[3 * i + 1];
                uint8_t b = rgb[3 * i + 2];

                destination[i++] = ((66*r + 129*g + 25*b) >> 8) + 16;
            }
        }
    }
}
```
ref
  * A command line tool to convert png, jpeg, etc to YUV. Dependency: FreeImage [link](https://github.com/stunpix/yuvit)
  * color models [link](https://software.intel.com/en-us/node/503873)
  * FreeImage, an Open Source library project for developers who would like to support popular graphics image formats [link](http://freeimage.sourceforge.net/)
  * BMP file structure [link](https://en.wikipedia.org/wiki/BMP_file_format#File_structure)
  * [link](http://www.pcschool.com.tw/campus/share/lib/160/)
  * rgb to yuv420 algorithm efficiency [link](https://stackoverflow.com/questions/9465815/rgb-to-yuv420-algorithm-efficiency)
## Stride
* When a video image is stored in memory, the memory buffer might contain extra padding bytes after each row of pixels. The _padding_ bytes affect how the image is store in memory, but do not affect how the image is displayed.
*  the number of bytes from the start of one row of pixels in memory to the start of the next row of pixels in memory
* aka pitch
原文網址：https://read01.com/PgjQ7.html
* Stride 的值一定大於圖像的寬度值

ref:
  * Image Stride [link](https://msdn.microsoft.com/zh-tw/library/windows/desktop/aa473780(v=vs.85).aspx)
  * Image Stride（內存圖像行跨度）[link](https://read01.com/zh-tw/PgjQ7.html#.Welc9nARVhE)  
  
