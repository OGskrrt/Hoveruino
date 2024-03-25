#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Ekran genişliği
#define SCREEN_HEIGHT 64 // Ekran yüksekliği

#define OLED_RESET    -1 // RESET pini yok

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // I2C Adresi: 0x3C (for SSD1306 OLED)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 başlatılamadı. Bağlantıları kontrol edin."));
    while (true);
  }
  delay(2000); // 2 saniye bekle
}

void loop() {
  display.clearDisplay(); // Ekranı temizle
  
  // Yıldızları çiz
  drawStar(10, 10);
  drawStar(20, 20);
  drawStar(30, 30);
  
  display.display(); // Çizimleri ekranda göster
  delay(1000); // Bir saniye bekle
}

// Yıldız çizen fonksiyon
void drawStar(int x, int y) {
  display.drawPixel(x, y, WHITE); // Yıldızın ortasını çiz
  
  // Yıldızın kollarını çiz
  display.drawPixel(x - 1, y - 1, WHITE);
  display.drawPixel(x + 1, y - 1, WHITE);
  display.drawPixel(x - 1, y + 1, WHITE);
  display.drawPixel(x + 1, y + 1, WHITE);
}
