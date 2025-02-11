#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

int k = 0;

#define TFT_MOSI D7 // SDA Pin on ESP32 -- MOSI (TX) M -> S  // 8 - 8266
#define TFT_SCLK D5 // SCL Pin on ESP32
#define TFT_CS D1   // Chip select control pin
#define TFT_DC D2   // Data Command control pin
#define TFT_RST D0  // Reset pin (could connect to RST pin)

// ESP8266 <-> SCREEN
// D7      <-> SDA
// D5      <-> SCL
// D1      <-> CS
// D2      <-> DC
// D0      <-> RST
// GND     <-> GND
// 3V      <-> VCC
// 3V      <-> BLK

//Adafruit_ST7789 colordisplay = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
Adafruit_ST7789 colordisplay = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// put function declarations here:
void setupColorDisplay();
void colorDisplayDrawText(int16_t x, int16_t y, String text, int16_t color);
void colorDisplayClearTextLine(int16_t x, int16_t y, int16_t color);

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);

  setupColorDisplay();
  colorDisplayDrawText(20, 90, "Test text", ST77XX_BLACK);
}

void loop() {
  // put your main code here, to run repeatedly:

   digitalWrite(LED_BUILTIN, LOW);
   delay(500);
   digitalWrite(LED_BUILTIN, HIGH);
   delay(500);

  colorDisplayClearTextLine(150,90, ST77XX_RED);
  colorDisplayDrawText(150, 90, String(k), ST77XX_BLACK);
  k++;
}

void setupColorDisplay()
{
  colordisplay.init(240, 280, SPI_MODE0);
  colordisplay.setRotation(2);
  colordisplay.fillScreen(ST77XX_RED);

  colordisplay.setTextSize(2);
}

void colorDisplayDrawText(int16_t x, int16_t y, String text, int16_t color)
{
  colordisplay.setCursor(x, y);
  colordisplay.setTextColor(color);
  colordisplay.println(text);
}

void colorDisplayClearTextLine(int16_t x, int16_t y, int16_t color)
{
  colordisplay.setCursor(x, y);
  colordisplay.setTextColor(color);
  colordisplay.fillRect(x, y, 240, 20, color);
}