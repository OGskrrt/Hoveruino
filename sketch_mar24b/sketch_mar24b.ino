#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128 // OLED ekran genişliği
#define SCREEN_HEIGHT 64 // OLED ekran yüksekliği
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_ADDR);
unsigned long lastHitTime = 0;
unsigned long delayTime = 1000;
int gamestarted = 0;

int potPin = A3;
int ledPin1 = 1;
int ledPin2 = 2;
int ledPin3 = 3;
int hak = 3;

int button1Pin = 8; // Örnek olarak atandı, gerçek pin numarasına değiştirilmeli
int button2Pin = 10; // Örnek olarak atandı, gerçek pin numarasına değiştirilmeli
int button3Pin = 9;

int arri[4][12];
int arrj[4][12];
int rectWidth = 8;
int rectHeight = 4;

int hoverWidth = 28;
int hoverHeight = 2;
int hoverX;
int hoverY = 62;

int choice1 = 0;
int choice2 = 0;
int choice3 = 0;

int ballX = SCREEN_WIDTH / 2;
int ballY = SCREEN_HEIGHT / 2;
int ballRadius = 2;
float ballSpeedX = random(-3.0, 3.0);
float ballSpeedY = random(-3.0, 3.0);

boolean blocks[4][12]; // true: blok var, false: blok yok

void exitscreen();
void initscreen();
void game();

void setup() {
  pinMode(potPin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);

  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 başlatma hatası!"));
    for(;;);
  }
  int i, j;

  for(i = 0; i < 4 ; i++)
  {
    for(j = 0; j < 12 ; j++)
    {
       arrj[i][j] = j * (rectWidth + 1);
       arri[i][j] = i * (rectHeight + 1);
       blocks[i][j] = true; // Başlangıçta tüm bloklar var
    } 
  }
}

void loop() {
    //gamestarted = 0;
    switch (gamestarted){
      case 0:
        initscreen();
        break;
      case 1:
        game();
        break;
      case 2:
        //exitscreen();
        break;
    }
}

void exitscreen() {
  display.clearDisplay();
  
  display.setCursor(35, 20);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("Oyunumuza");
  display.setCursor(12, 30);
  display.print("gosterdiginiz ilgi");
  display.setCursor(15, 40);
  display.print("icin tesekkurler");

  display.display();
}


void initscreen() {
  display.clearDisplay();
  
  display.setCursor(40, 20);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("Start");
  
  if (digitalRead(8) == HIGH) {
    choice1 = 1;
    choice2 = 0;    
  }

  if (digitalRead(10) == HIGH) {
    choice2 = 1;
    choice1 = 0;  
  } 
  if(digitalRead(9) == HIGH){
    choice3 = 1;
  }
  else{
    choice3 = 0;
  }

  if (choice1 == 1) {
    display.drawRect(32, 15, 60, 17, WHITE);
  }
  
  display.setCursor(40, 40);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("Exit");
  
  if (choice2 == 1) {
    display.drawRect(32, 35, 60, 17, WHITE);
  }

  if(choice3 == 1){
    if(choice1 ==1){
      gamestarted = 1;
      choice1 = 0;
      choice3 = 0;
    }
    else if(choice2 == 1){
      gamestarted = 2;
    }
  }

  /*if (choice1 == 1 && choice3 == 1) {
    gamestarted = 1;
    choice1 = 0;
    choice3 = 0;
  }

  if (choice2 == 1 && choice3 == 1) {
    
  }*/
  
  display.display();
}




void game()
{
  display.clearDisplay();
    for(int i = 0;i < 4; i++)
    {
      for(int j = 0;j < 12; j++)
      {
        if (blocks[i][j]) { // Eğer blok varsa, çiz
          display.fillRect(arrj[i][j] + 10, arri[i][j] + 1, rectWidth, rectHeight, SSD1306_WHITE);
        }
      }
    }

    // Hover çizimi
    int potValue = analogRead(potPin);
    float x = (float)potValue / 1023.0 * (SCREEN_WIDTH - hoverWidth);
    hoverX = round(x);
    display.fillRect(hoverX, hoverY, hoverWidth, hoverHeight, SSD1306_WHITE);

    ballX += ballSpeedX;
    ballY += ballSpeedY;

    if (ballX + ballRadius >= SCREEN_WIDTH || ballX - ballRadius <= 0) {
      ballSpeedX = -ballSpeedX;
      ballX = constrain(ballX, ballRadius, SCREEN_WIDTH - ballRadius);
    }
    if (ballY + ballRadius >= SCREEN_HEIGHT || ballY - ballRadius <= 0) {
      ballSpeedY = -ballSpeedY;
      ballY = constrain(ballY, ballRadius, SCREEN_HEIGHT - ballRadius);
    }

    //tuğlaya çarpma
    bool collided = false;
    for(int i = 0; i < 4 && !collided; i++) {
      for(int j = 0; j < 12 && !collided; j++) {
        if (blocks[i][j]) {
          float left = arrj[i][j] - ballRadius;
          float right = arrj[i][j] + rectWidth + ballRadius;
          float top = arri[i][j] - ballRadius;
          float bottom = arri[i][j] + rectHeight + ballRadius;

          bool collideX = ballX + ballRadius >= left && ballX - ballRadius <= right;
          bool collideY = ballY + ballRadius >= top && ballY - ballRadius <= bottom;

          if (collideX && collideY) {
            float dx = min(abs(ballX - left), abs(ballX - right));
            float dy = min(abs(ballY - top), abs(ballY - bottom));

            if (dx < dy) {
              ballSpeedX = -ballSpeedX;
            } else {
              ballSpeedY = -ballSpeedY;
            }
            blocks[i][j] = false;
            collided = true;
          }
        }
      }
    }

    // hoverdan sekme
    if(ballX + ballRadius >= hoverX && ballX - ballRadius <= hoverX + hoverWidth &&
      ballY + ballRadius >= hoverY && ballY - ballRadius <= hoverY + hoverHeight) {
          ballSpeedX = random(-3.0, 3.0);
          if(ballSpeedX == 1)
            ballSpeedX += 1;
          if(ballSpeedX == -1)
            ballSpeedX -= 1;
          ballSpeedY = -ballSpeedY;
      }

    //tabana çarpıp canın gitmesi
    if (ballY + ballRadius >= SCREEN_HEIGHT) {
      if (millis() - lastHitTime >= delayTime) { // Belirli bir süre geçti mi kontrol et
        lastHitTime = millis(); // En son çarpma zamanını güncelle
        ballX = SCREEN_WIDTH / 2; // Topu başlangıç pozisyonuna yerleştir
        ballY = SCREEN_HEIGHT / 2;
        delayTime = 0;
        ballSpeedX = 2.0;
        ballSpeedY = 2.0;
      } else {
        ballSpeedX = 0;
        ballSpeedY = 0;
      }
      hak -= 1;
      if(hak == -1){
        display.print("Game Over");
        display.clearDisplay();
      }
        
      delay(1000);
    }
    display.fillCircle(ballX, ballY, ballRadius, SSD1306_WHITE);

    display.display();
}
