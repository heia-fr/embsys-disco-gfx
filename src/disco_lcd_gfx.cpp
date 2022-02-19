#include "disco_lcd_gfx.h"

#include "Adafruit_GFX.h"
#include "stm32412g_discovery_lcd.h"

DiscoLcdGFX::DiscoLcdGFX(int16_t w, int16_t h) : Adafruit_GFX(w, h), lcdBackLight(PF_5, 1)
{
    BSP_LCD_InitEx(LCD_ORIENTATION_LANDSCAPE_ROT180);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
}

DiscoLcdGFX::DiscoLcdGFX() : DiscoLcdGFX(240, 240) {}

void DiscoLcdGFX::drawPixel(int16_t x, int16_t y, uint16_t color) {
    BSP_LCD_DrawPixel(x, y, color);
}

void DiscoLcdGFX::drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
    BSP_LCD_SetTextColor(color);
    BSP_LCD_DrawVLine(x, y, h);
}

void DiscoLcdGFX::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
    BSP_LCD_SetTextColor(color);
    BSP_LCD_DrawHLine(x, y, w);
}

void DiscoLcdGFX::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    BSP_LCD_SetTextColor(color);
    BSP_LCD_FillRect(x, y, w, h);
}

void DiscoLcdGFX::fillScreen(uint16_t color) {
    BSP_LCD_Clear(color);
}

void DiscoLcdGFX::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    BSP_LCD_SetTextColor(color);
    BSP_LCD_DrawRect(x, y, w, h);
}

void DiscoLcdGFX::switchBackLightOn() { lcdBackLight = 1; }
void DiscoLcdGFX::switchBackLightOff() { lcdBackLight = 0; }
