## [BulletCount, BlasterCharge](https://github.com/profezzorn/ProffieOS/blob/master/functions/bullet_count.h)  
Usage: BulletCount  
    Return 0-N (number of bullets in the magazine.)  
    Will cause compilation error if your prop doesn't have bullets.  
    You must define BLASTER_SHOTS_UNTIL_EMPTY for this to be available.  
Usage: BlasterCharge  
    Return 0-32768 based on the fullness of the clip / magazine.  
    Will cause compilation error if your prop doesn't have bullets.  
    You must define BLASTER_SHOTS_UNTIL_EMPTY for this to be available.  
    Recommended to be used as the EXTENSION argument to InOutHelperL.  

## [PixelateX, Pixelate](https://github.com/profezzorn/ProffieOS/blob/master/functions/pixelate.h)  
Usage: PixelateX<COLOR, PIXEL_SIZE_FUNC>
    OR: Pixelate<COLOR, PIXEL_SIZE>
    COLOR: COLOR - color values to pixelate
    PIXEL_SIZE_FUNC: FUNCTION size of pixelation (defaults to 2)
    PIXEL_SIZE: NUMBER size of pixelation (defaults to 2)
    Returns: COLOR
    Pixelate a style.
    If you have a blade that has too many LEDs to run fast, you
    can use Pixelate<COLOR> to make it run faster, since it will
    only calculate "COLOR" half as many times.
    It can also be used as an effect of course.

## [ReadPinF, AnalogReadPinF](https://github.com/profezzorn/ProffieOS/blob/master/functions/readpin.h)  
Usage: ReadPinF<PIN>  
or: ReadPinF<PIN, PIN_MODE>  
returns INTEGER, 0 if pin is low and 32768 if pin is high  
PIN: int, pin you want your style to respond to  
PIN_MODE: int, one of INPUT, INPUT_PULLUP or INPUT_PULLDOWN, defaults to INPUT  

Usage: AnalogReadPinF<PIN>  
or: AnalogReadPinF<PIN, PIN_MODE>  
returns INTEGER, 0-32768 depending on input reading.  
PIN: int, pin you want your style to respond to  
PIN_MODE: int, one of INPUT, INPUT_PULLUP or INPUT_PULLDOWN, defaults to INPUT  
Notes:  
  * May cause slowdowns  
  * may not update every run() call  
  * pin modes other than INPUT may not be supported,  
  * Only analog-capable pins will work.  