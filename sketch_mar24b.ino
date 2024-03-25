#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED ekran genişliği
#define SCREEN_HEIGHT 64 // OLED ekran yüksekliği
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_ADDR);

int arrX[8][4];
int arrY[8][4];
int rectWidth = 8;
int rectHeight = 4;

int hoverWidth = 16;
int hoverHeight = 2;
int hoverX;
int hoverY;

int ballX;
int ballY;
int ballWidth = 2;
int ballHeight = 2;

void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 başlatma hatası!"));
    for(;;);
  }

  for(int i = 0; i < 4 ; i++)
  {
    for(int j = 0; j < 8 ; j++)
    {
       arrX[i][j] = j + 1;
       arrY[i][j] = i + 1;  
    }
  }
  /*
  hareketsiz bir bileşen çizilecekse kullanılacak, şimdilik gerek yok
  display.clearDisplay();
  display.display();
  */
}

void loop() {

  display.clearDisplay();
  for(int i = 0;i < 4; i++)
  {
    for(int j = 0;j < 8; j++)
    {
      //display.drawRect((arrX[i][j] * (rectWidth + 1)) + 18, (arrY[i][j] * (rectHeight + 1)), rectWidth, rectHeight, SSD1306_WHITE); kank buna gerek yok ama silmedim göresin diye
      display.fillRect((arrX[i][j] * (rectWidth + 1)) + 18, (arrY[i][j] * (rectHeight + 1)), rectWidth, rectHeight, SSD1306_WHITE); //burda 18 sağ sol boşluğu sağlıyor(margin). 1 ise kareler arası boşlukları. okuduktan sonra silersin.
      //tam 8 * 4 olmuyor bakarsın
    }
  }
  
  display.display();
}