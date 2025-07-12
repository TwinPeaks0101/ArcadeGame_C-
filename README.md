# Arcade Pong Game 🎮

This project is a simple implementation of the classic Pong arcade game using C++.

## 📌 Description

Two players control paddles on the left and right side of the screen to bounce a ball back and forth. The objective is to prevent the ball from passing your paddle and score points by making the opponent miss the ball.

## 🛠️ Technologies Used

- C++
- SFML Library (for graphics and input handling)

## 📁 Project Structure

- `main.cpp`: Game logic and main loop
- `Paddle.h / Paddle.cpp`: Paddle class implementation
- `Ball.h / Ball.cpp`: Ball class implementation
- `Game.h / Game.cpp`: Game management and rendering
- `assets/`: Includes font and sound files

## 🎮 Controls

- **Player 1:**  
  - Move Up: `W`  
  - Move Down: `S`

- **Player 2:**  
  - Move Up: `Up Arrow`  
  - Move Down: `Down Arrow`

## 🚀 How to Run

Make sure you have the SFML library installed.  
Then compile the project with:

```bash
g++ main.cpp Game.cpp Paddle.cpp Ball.cpp -lsfml-graphics -lsfml-window -lsfml-system -o pong
./pong