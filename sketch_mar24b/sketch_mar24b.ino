#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "pitches.h"

#define SCREEN_WIDTH 128 // OLED ekran genişliği
#define SCREEN_HEIGHT 64 // OLED ekran yüksekliği

// OLED ekranın I2C adresi (genellikle 0x3C veya 0x3D olur)
#define OLED_ADDR   0x3C

// OLED ekran nesnesi oluştur
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_ADDR);

void setup() {
  // Seri bağlantıyı başlat
  Serial.begin(9600);

  // OLED ekranın başlatılması
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 başlatma hatası!"));
    for(;;);
  }

  // OLED ekranı temizle
  display.clearDisplay();

  // Yazı boyutunu ayarla
  display.setTextSize(1); 
  // Yazı rengini beyaz yap
  display.setTextColor(SSD1306_WHITE); 
  // Metni tam ekranın ortasına yerleştir
  display.setCursor((SCREEN_WIDTH - 12*6) / 2, (SCREEN_HEIGHT - 8) / 2);
  // Metni yazdır
  display.println(F("Merhaba, Dünya!"));

  // Yazdırılanları OLED ekranına gönder
  display.display();
}

void loop() {
  // Boş döngü
}
