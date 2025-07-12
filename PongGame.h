#pragma once
#include "Player.h"
#include "Ball.h"

//Διαχείρηση ροής παιχνιδιού
//Κατάσταση παιχνιδιού , παίκτες , μέθοδοι για έναρξη , ενημέρωση και σχεδίαση παιχνιδιού
//Λειτουργίες για σύγκρουση, πόντους, δημιουργίας και διαγραφής μπαλών

class PongGame {
    typedef enum { STATUS_START, STATUS_PLAYING, STATUS_FINISH } status_t;

    Player* player1 = nullptr;
    Player* player2 = nullptr;
    std::vector<Ball*> balls;

    status_t status = STATUS_START;
    int numBalls = 1;

    void updateStartScreen();
    void updateLevelScreen();
    void drawStartScreen();
    void drawLevelScreen();
    void updateFinishScreen();
    void drawFinishScreen();
    void updateBalls();

public:
    void CheckActiveBall();
    bool checkCollision();
    void checkGoal();
    void ScoreUp(Player* player);
    void SpawnBall();
    PongGame();
    ~PongGame();
    void init();
    void update();
    void draw();
};

