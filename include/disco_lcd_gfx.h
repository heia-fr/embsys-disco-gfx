#ifndef DISCO_LCD_GFX_H_
#define DISCO_LCD_GFX_H_

#include "mbed.h"

#include "Adafruit_GFX.h"
#include "stm32412g_discovery_lcd.h"

class DiscoLcdGFX : public Adafruit_GFX {
   public:
    DiscoLcdGFX(int16_t w, int16_t h);
    DiscoLcdGFX();

    void drawPixel(int16_t x, int16_t y, uint16_t color) override;
    void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override;
    void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override;
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override;
    void fillScreen(uint16_t color) override;
    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override;

    void switchBackLightOn();
    void switchBackLightOff();
  private:
    DigitalOut lcdBackLight;
};


#endif /* DISCO_LCD_GFX_H_ */
