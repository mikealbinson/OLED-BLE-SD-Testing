/*
* U8g based library that focuses on providing a MockU8g class that can be used for testing
* Additional U8g types can be added at the bottom of this doc to increase the functionality of this lib
* --Simplified from the U8g original so the functionality is more limited
*/

#ifndef _CPP_U8GLIBCLONE
#define _CPP_U8GLIBCLONE

#include <Print.h>
#include "Arduino.h"
#include "utility/u8g.h"


//Uses a mock U8G Object~~relies heavily on standard U8GLib so not suggested for use together

class U8GLIB : public Print
{
  private:
    u8g_t u8g;
    u8g_uint_t tx, ty;          // current position for the Print base class procedures
    uint8_t is_begin;

    void prepare(void) { tx = 0; ty = 0; is_begin = 0; }
    void cbegin(void) { if ( is_begin == 0 ) { is_begin = 1; u8g_Begin(&u8g); } }
    uint8_t initSPI(u8g_dev_t *dev, uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE);
    uint8_t initHWSPI(u8g_dev_t *dev, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE);
    uint8_t initI2C(u8g_dev_t *dev, uint8_t options);
  protected:
    uint8_t init8BitFixedPort(u8g_dev_t *dev, uint8_t en, uint8_t cs, uint8_t di, uint8_t rw, uint8_t reset);
  private:
    uint8_t init8Bit(u8g_dev_t *dev, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, uint8_t en, uint8_t cs1, uint8_t cs2, uint8_t di, uint8_t rw = U8G_PIN_NONE, uint8_t reset = U8G_PIN_NONE);
    uint8_t initRW8Bit(u8g_dev_t *dev, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, uint8_t cs, uint8_t a0, uint8_t wr, uint8_t rd, uint8_t reset);
  public:
  
    /* constructor */
    U8GLIB(void)
      { }
    U8GLIB(u8g_dev_t *dev)
      { prepare(); u8g_Init(&u8g, dev); }
    U8GLIB(u8g_dev_t *dev, u8g_com_fnptr com_fn)
      { prepare(); u8g_InitComFn(&u8g, dev, com_fn); }
    U8GLIB(u8g_dev_t *dev, uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset) 
      { initSPI(dev, sck, mosi, cs, a0, reset); }
    U8GLIB(u8g_dev_t *dev, uint8_t cs, uint8_t a0, uint8_t reset) 
      { initHWSPI(dev, cs, a0, reset); }
    U8GLIB(u8g_dev_t *dev, uint8_t options) 
      { initI2C(dev, options); }
    U8GLIB(u8g_dev_t *dev, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, uint8_t en, uint8_t cs1, uint8_t cs2, uint8_t di, uint8_t rw, uint8_t reset) 
      { init8Bit(dev, d0, d1, d2, d3, d4, d5, d6, d7, en, cs1, cs2, di, rw, reset); }
    U8GLIB(u8g_dev_t *dev, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, uint8_t cs, uint8_t a0, uint8_t wr, uint8_t rd, uint8_t reset) 
      { initRW8Bit(dev, d0, d1, d2, d3, d4, d5, d6, d7, cs, a0, wr, rd, reset); }

    uint8_t begin(void) { is_begin = 1; return u8g_Begin(&u8g); }
      
    void setPrintPos(u8g_uint_t x, u8g_uint_t y) { tx = x; ty = y; }
    u8g_t *getU8g(void) { return &u8g; }
    
    
    /* implementation of the write interface to the print class */
#if defined(ARDUINO) && ARDUINO >= 100
    size_t write(uint8_t c) { tx += u8g_DrawGlyph(&u8g, tx, ty, c); return 1;}
#else
    void write(uint8_t c) { tx += u8g_DrawGlyph(&u8g, tx, ty, c); }
#endif
    
     /* screen rotation */
    void undoRotation(void) { u8g_UndoRotation(&u8g); }
    void setRot90(void) { u8g_SetRot90(&u8g); }
    void setRot180(void) { u8g_SetRot180(&u8g); }
    void setRot270(void) { u8g_SetRot270(&u8g); }

     /* screen scaling */
    void undoScale(void) { u8g_UndoScale(&u8g); }
    void setScale2x2(void) { u8g_SetScale2x2(&u8g); }
    
     /* picture loop */
    void firstPage(void) { cbegin(); u8g_FirstPage(&u8g); }
    uint8_t nextPage(void) { return u8g_NextPage(&u8g); }
    
    /* system commands */
    uint8_t setContrast(uint8_t contrast) { cbegin(); return u8g_SetContrast(&u8g, contrast); }
    void sleepOn(void) { u8g_SleepOn(&u8g); }
    void sleepOff(void) { u8g_SleepOff(&u8g); }
    
    /* graphic primitives */
    void setColorEntry(uint8_t color_index, uint8_t r, uint8_t g, uint8_t b) { u8g_SetColorEntry(&u8g, color_index, r, g, b); }
    void setHiColor(uint16_t  rgb) { u8g_SetHiColor(&u8g, rgb); }
    void setHiColorByRGB(uint8_t r, uint8_t g, uint8_t b) { u8g_SetHiColorByRGB(&u8g, r, g, b); }
    void setRGB(uint8_t r, uint8_t g, uint8_t b) { u8g_SetRGB(&u8g, r, g, b); }
    
    void setColorIndex(uint8_t color_index) { u8g_SetColorIndex(&u8g, color_index); }
    uint8_t getColorIndex(void) { return u8g_GetColorIndex(&u8g); }
    
    void setDefaultForegroundColor(void) { u8g_SetDefaultForegroundColor(&u8g);  }
    void setDefaultBackgroundColor(void) { u8g_SetDefaultBackgroundColor(&u8g);  }
    void setDefaultMidColor(void) { u8g_SetDefaultMidColor(&u8g);  }
    
    u8g_uint_t getWidth(void) { return u8g_GetWidth(&u8g); }
    u8g_uint_t getHeight(void) { return u8g_GetHeight(&u8g); }
    uint8_t getMode(void) { return u8g_GetMode(&u8g); }

    void drawPixel(u8g_uint_t x, u8g_uint_t y) { return u8g_DrawPixel(&u8g, x, y); }

    
    /* bitmap handling */
    void drawBitmap(u8g_uint_t x, u8g_uint_t y, u8g_uint_t cnt, u8g_uint_t h, const uint8_t *bitmap) 
      { u8g_DrawBitmap(&u8g, x, y, cnt, h, bitmap); }
      
    /* font handling */
    void setFont(const u8g_fntpgm_uint8_t *font) {u8g_SetFont(&u8g, font); }
    int8_t getFontAscent(void) { return u8g_GetFontAscent(&u8g); }
    int8_t getFontDescent(void) { return u8g_GetFontDescent(&u8g); }
    int8_t getFontLineSpacing(void) { return u8g_GetFontLineSpacing(&u8g); }
    
    const char* drawStr(u8g_uint_t x, u8g_uint_t y, const char *s){ //ONLY FUNCTION REALLY USED
			u8g_DrawStr(&u8g, x, y, s);
			return 0; 
   }
    void setFontPosBaseline(void) { u8g_SetFontPosBaseline(&u8g); }
    void setFontPosBottom(void) { u8g_SetFontPosBottom(&u8g); }
    void setFontPosCenter(void) { u8g_SetFontPosCenter(&u8g); }
    void setFontPosTop(void) { u8g_SetFontPosTop(&u8g); }

    void setFontRefHeightText(void) { u8g_SetFontRefHeightText(&u8g); }
    void setFontRefHeightExtendedText(void) { u8g_SetFontRefHeightExtendedText(&u8g); }
    void setFontRefHeightAll(void) { u8g_SetFontRefHeightAll(&u8g); }  
    void setFontLineSpacingFactor(uint8_t factor) { u8g_SetFontLineSpacingFactor(&u8g, factor); }


    u8g_uint_t getStrPixelWidth(const char *s) { return u8g_GetStrPixelWidth(&u8g, s); }
    u8g_uint_t getStrPixelWidthP(u8g_pgm_uint8_t *s) { return u8g_GetStrPixelWidthP(&u8g, s); }
    u8g_uint_t getStrWidth(const char *s) { return u8g_GetStrWidth(&u8g, s); } 
    u8g_uint_t getStrWidthP(u8g_pgm_uint8_t *s) { return u8g_GetStrWidthP(&u8g, s); }
    
    void setHardwareBackup(u8g_state_cb backup_cb) { u8g_SetHardwareBackup(&u8g, backup_cb); }
 
    
    /* virtual screen */
    
    void setVirtualScreenDimension(u8g_uint_t width, u8g_uint_t height) { u8g_SetVirtualScreenDimension(&u8g, width, height); }
    uint8_t addToVirtualScreen(u8g_uint_t x, u8g_uint_t y, U8GLIB &child_u8g) { return u8g_AddToVirtualScreen(&u8g, x, y, &child_u8g.u8g); }

};

class U8GLIB_SSD1306_128X32 : public U8GLIB 
{
  public:
    U8GLIB_SSD1306_128X32(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_ssd1306_128x32_sw_spi, sck, mosi, cs, a0, reset)
      { }
    U8GLIB_SSD1306_128X32(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_ssd1306_128x32_hw_spi, cs, a0, reset)
      { }
    U8GLIB_SSD1306_128X32(uint8_t options = U8G_I2C_OPT_NONE) 
      : U8GLIB(&u8g_dev_ssd1306_128x32_i2c, options)
      { }
};

class U8GLIB_SSD1306_128X32MOCK : public U8GLIB    /////MY MOCK CLASS
{
  public:
    U8GLIB_SSD1306_128X32MOCK(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_ssd1306_128x64_sw_spi, sck, mosi, cs, a0, reset)
			{ byte mockFlag = 1; }
    U8GLIB_SSD1306_128X32MOCK(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_ssd1306_128x64_hw_spi, cs, a0, reset)
      { byte mockFlag = 1;}
    U8GLIB_SSD1306_128X32MOCK(uint8_t options = U8G_I2C_OPT_NONE) 
      : U8GLIB(&u8g_dev_ssd1306_128x64_i2c, options)
      { byte mockFlag = 1;}
};

#endif /* _CPP_U8GLIB */
