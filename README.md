# Arduino Breakout Game

## Overview

This project implements a simple brick-breaking game using Arduino and an OLED display. The game involves controlling a ball to break bricks on the screen, earning points and avoiding losing lives.

## Features

- **Start Screen:** Present with options to start the game or exit.
- **Palette Control:** Use a potentiometer to control the game palette horizontally.
- **Brick Breaking:** Bricks randomly placed on the screen, break them using the ball.
- **Scoring:** Seven-segment display shows the player's score.
- **Lives:** Player starts with three lives, lose one for each missed ball.
- **Rewards:** Chance of dropping a heart object with each broken brick, increases player's life.
- **Ambient Light Detection:** Background color changes based on ambient light detected by a light-dependent resistor (LDR).
- **Progressive Difficulty:** Ball speed increases with each level passed.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- OLED display (SSD1306)
- Potentiometer
- Light-dependent resistor (LDR)
- Buttons for user interaction
- LEDs for indicating remaining lives
- 7-segment display for showing the score

## Setup

1. **Connect Components:** Connect the OLED display, potentiometer, LDR, buttons, LEDs, and 7-segment display to the Arduino board following the provided pin assignments in the code.
2. **Upload Sketch:** Upload the provided Arduino sketch (`brick_breaker_game.ino`) to the Arduino board using the Arduino IDE or another compatible software.
3. **Play:** Power on the Arduino board and start playing the game!

## Usage

- **Control Palette:** Use the potentiometer to control the game palette and move it horizontally.
- **Start/Exit:** Press the start button to begin the game or exit button to quit.
- **Break Bricks:** Bounce the ball off the palette to break bricks and earn points.
- **Collect Hearts:** Hearts dropped by breaking bricks increase your remaining lives.
- **Avoid Misses:** Missing the ball reduces your remaining lives.
- **Game Over:** The game ends when all lives are lost, and your final score is displayed.

## Contributions

Contributions to improve the game code, add new features, or optimize performance are welcome! Fork the repository, make your changes, and submit a pull request.

## Sample Proteus Circuit Images

![Screenshot 2024-04-21 151319](https://github.com/OGskrrt/Hoveruino/assets/135557803/ac8234ec-4faf-46bb-80c0-8ed8fb31f9ce)
![Screenshot 2024-04-21 151342](https://github.com/OGskrrt/Hoveruino/assets/135557803/cbd592cf-0618-4b30-be37-da6e6ca935ac)


## In Game Images

![Screenshot 2024-04-21 151715](https://github.com/OGskrrt/Hoveruino/assets/135557803/63f53517-b07a-4c19-b10a-4de03f352bee)
![Screenshot 2024-04-21 151647](https://github.com/OGskrrt/Hoveruino/assets/135557803/ff0207ad-5b31-4ee6-866e-8e343f779a9b)
![Screenshot 2024-04-21 151626](https://github.com/OGskrrt/Hoveruino/assets/135557803/90eb07e2-8f85-47c3-9c5f-81bd1631864b)
![Screenshot 2024-04-21 151543](https://github.com/OGskrrt/Hoveruino/assets/135557803/e1a7f4d4-094b-4560-ba84-71ff824b0a45)
![Screenshot 2024-04-21 151413](https://github.com/OGskrrt/Hoveruino/assets/135557803/c96b6c12-cd6c-4c61-bd26-35b52975f638)
