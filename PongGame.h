#pragma once
#include "Player.h"
#include "Ball.h"

//���������� ���� ����������
//��������� ���������� , ������� , ������� ��� ������ , ��������� ��� �������� ����������
//����������� ��� ���������, �������, ����������� ��� ��������� ������

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

