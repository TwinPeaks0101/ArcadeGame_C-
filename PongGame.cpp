#include "PongGame.h"
#include "sgg/graphics.h"
#include "config.h"
#include <iostream>
#include "Player.h"
#include "Ball.h"

/*Φορτώνει τους παίκτες, τη γραμματοσειρά και τη μουσική*/

void PongGame::init()
{
    player1 = new Player();
    player2 = new Player();
    graphics::setFont(std::string(ASSET_PATH) + "font.ttf");
    graphics::playMusic(std::string(ASSET_PATH) + "Discord.mp3", 0.2f, true, 0);
}

/*updateLevelScreen : Καλεί τις μεθόδους update για παίκτες,μπάλες,
ελέγχει συγκρούσεις, γκολ και διαχειρίζεται τη λογική για νίκη στους 5 πόντους*/
void PongGame::update()
{
    switch (status) {
    case STATUS_START:
        updateStartScreen();
        break;
    case STATUS_PLAYING:
        updateLevelScreen();
        break;
    case STATUS_FINISH:
        updateFinishScreen();
        break;
    default:
        std::cout << "Not implemented status" << std::endl;
    }
}

void PongGame::draw()
{
    switch (status) {
    case STATUS_START:
        drawStartScreen();
        break;
    case STATUS_PLAYING:
        drawLevelScreen();
        break;
    case STATUS_FINISH:
        drawFinishScreen();
        break;
    default:
        std::cout << "Not implemented status" << std::endl;
    }
}

void PongGame::updateStartScreen()
{
    if (graphics::getKeyState(graphics::SCANCODE_1)) {
        numBalls = 1;
    }
    if (graphics::getKeyState(graphics::SCANCODE_2)) {
        numBalls = 2;
    }
    if (graphics::getKeyState(graphics::SCANCODE_3)) {
        numBalls = 3;
    }

    if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
        status = STATUS_PLAYING;                  
    }
}

void PongGame::updateLevelScreen()
{
    if (player1)
    {
        player1->update();
    }

    if (player2)
    {
        player2->update();
    }

    CheckActiveBall();
    SpawnBall();
    checkCollision();
    checkGoal();
    updateBalls();

    //Κάθε παρτίδα παιχνιδιού τελειώνει στους 5 πόντους
    if (player1->getPlayerGoals() >= 5 || player2->getPlayerGoals() >= 5) {
        status = STATUS_FINISH;
    }
}

void PongGame::drawStartScreen()
{
    graphics::Brush br;
    br.texture = std::string(ASSET_PATH) + "initBack.png";
    br.outline_opacity = 0.0f;//no background outline 

    graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    //set font
    graphics::setFont(std::string(ASSET_PATH) + "font.ttf");


    graphics::Brush bru;

    char info[200];
    bru.fill_color[0] = 1.0f; //red
    bru.fill_color[1] = 0.0f; //green
    bru.fill_color[2] = 0.0f; //blue


    sprintf_s(info, "Pong   Game");
    graphics::drawText(320, 85, 45, info, bru);

    int yPos = 200;
    int gap = 50;  // Adjust the gap size

    //sprintf_s(info, "Press 1-2-3 for 1-2 or 3 balls ");
   // graphics::drawText(350, 350, 25, info, bru);
    bru.fill_color[0] = 255.0f; //red
    bru.fill_color[1] = 255.0f; //green
    bru.fill_color[2] = 0.0f; //blue
    sprintf_s(info, "Player 1");
    graphics::drawText(200, yPos, 20, info, bru);
    yPos += gap;

    bru.fill_color[0] = 255.0f; //red
    bru.fill_color[1] = 255.0f; //green
    bru.fill_color[2] = 255.0f; //blue
    sprintf_s(info, "Use   W   to   go   Up");
    graphics::drawText(150, yPos, 20, info, bru);
    yPos += gap;

    sprintf_s(info, "Use   S   to   go   Down");
    graphics::drawText(150, yPos, 20, info, bru);


    bru.fill_color[0] = 255.0f; //red
    bru.fill_color[1] = 255.0f; //green
    bru.fill_color[2] = 0.0f; //blue
    sprintf_s(info, "Player 2");
    graphics::drawText(600, 200, 20, info, bru);

    bru.fill_color[0] = 255.0f; //red
    bru.fill_color[1] = 255.0f; //green
    bru.fill_color[2] = 255.0f; //blue
    sprintf_s(info, "Use   Up   to   go   Up");
    graphics::drawText(550, 250, 20, info, bru);
    sprintf_s(info, "Use   Down   to   go   Down");
    graphics::drawText(550, 300, 20, info, bru);


    bru.fill_color[0] = 128.0f; //red
    bru.fill_color[1] = 0.0f; //green
    bru.fill_color[2] = 128.0f; //blue
    sprintf_s(info, "Press   Enter   to   Start!");
    graphics::drawText(200, 400, 36, info, bru);


    bru.fill_color[0] = 255.0f; //red
    bru.fill_color[1] = 255.0f; //green
    bru.fill_color[2] = 255.0f; //blue
    sprintf_s(info, "Score   5   Points   to   Win");
    graphics::drawText(380, 420, 14, info, bru);
}

void PongGame::drawLevelScreen()
{
    graphics::setFont(std::string(ASSET_PATH) + "font.ttf");
    graphics::Brush br;

    char score_c[40];
    sprintf_s(score_c, "%6.0f", player2->getPlayerGoals());
    graphics::drawText(500.0f, 50.0f, 25.0f, score_c, br);

    sprintf_s(score_c, "%6.0f", player1->getPlayerGoals());
    graphics::drawText(400.0f, 50.0f, 25.0f, score_c, br);

    br.texture = std::string(ASSET_PATH) + "blck.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    player1->draw();
    player2->draw();

    for (Ball* b : balls) {
        b->draw();
    }
}

void PongGame::updateFinishScreen()
{
    if (graphics::getKeyState(graphics::SCANCODE_R)) {
        status = STATUS_PLAYING;
        player1->resetPlayerGoals();
        player2->resetPlayerGoals();

    }
}

void PongGame::drawFinishScreen()
{
    graphics::setFont(std::string(ASSET_PATH) + "font.ttf");
    graphics::Brush br;
    br.texture = std::string(ASSET_PATH) + "initBack.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    char info[100];
    sprintf_s(info, "Game   Over!  ");
    graphics::drawText(350, 100, 25, info, br);

    sprintf_s(info, "Press   R   to   play   again!");
    graphics::drawText(250, 400, 30, info, br);

    if (player1->getPlayerGoals() > player2->getPlayerGoals()) {
        sprintf_s(info, " Player   1   won! ");
        graphics::drawText(350, 200, 25, info, br);

    }
    else {

        sprintf_s(info, " Player   2   won! ");
        graphics::drawText(350, 200, 25, info, br);
    }

    char score_c[20];
    sprintf_s(info, "Player 1:");
    graphics::drawText(250, 250, 25, info, br);

    sprintf_s(score_c, "%6.0f", player1->getPlayerGoals());
    graphics::drawText(250.0, 300.0, 25.0, score_c, br);



    sprintf_s(info, "Player 2:");
    graphics::drawText(550, 250, 25, info, br);


    sprintf_s(score_c, "%6.0f", player2->getPlayerGoals());
    graphics::drawText(550.0, 300.0, 25.0, score_c, br);
}

void PongGame::updateBalls()
{
    for (Ball* b : balls)
    {
        b->update();
    }
}

/*checkCollision : εντοπίζει αν η μπάλα χτύπησε κάποια ρακέτα
checkGoal : ελέγχει αν η μπάλα βγήκε από τα όρια,προσθέτοντας πόντο σε κάποιον παίκτη.*/

bool PongGame::checkCollision()
{
    if (!player1)
    {
        return false;
    }

    for (Ball* b : balls) {
        Disk d2 = b->getCollisionHull(b->getX(), b->getY());

        //Player 1
        for (int i = -25; i <= 25; i = i + 10)
        {
            Disk hull2 = player2->getCollisionHull(player2->getX2(), player2->getY2() + i);
            float dx = hull2.cx - d2.cx;
            float dy = hull2.cy - d2.cy;

            if (sqrt(dx * dx + dy * dy) < hull2.radius + d2.radius && !b->isCollided())
            {
                graphics::playSound(std::string(ASSET_PATH) + "ballHit.mp3", 0.4f, false);
                b->ChangeOrientationX();
                b->SetCollided(true);
                return true;
            }
        }

        //Player 2
        for (int i = -25; i <= 25; i = i + 10) {
            Disk hull1 = player1->getCollisionHull(player1->getX1(), player1->getY1() + i);
            float dx = hull1.cx - d2.cx;
            float dy = hull1.cy - d2.cy;
            if (sqrt(dx * dx + dy * dy) < hull1.radius + d2.radius && !b->isCollided())
            {
                graphics::playSound(std::string(ASSET_PATH) + "ballHit.mp3", 0.4f, false);
                b->ChangeOrientationX();
                b->SetCollided(true);
                return true;
            }
        }

        b->SetCollided(false);
    }
    return false;
}

void PongGame::checkGoal()
{
    //left wall
    for (Ball* b : balls) {
        if (b->getX() <= player1->getX1() - 20 && b->isActive())
        {
            graphics::playSound(std::string(ASSET_PATH) + "point.mp3", 0.4f, false);
            ScoreUp(player2);
        }

        //right wall 
        if (b->getX() >= player2->getX2() + 20 && b->isActive())
        {
            graphics::playSound(std::string(ASSET_PATH) + "point.mp3", 0.4f, false);
            ScoreUp(player1);
        }
    }
}

void PongGame::ScoreUp(Player* player)
{
    player->setPlayerGoals();
}

//Δημιουργία και διαγραφή μπαλών

void PongGame::SpawnBall()
{
    while (balls.size() < numBalls) {
        Ball* b = new Ball();
        std::cout << "Throwing a new ball to the game!!!" << std::endl;
        balls.push_back(b);
    }
}

void PongGame::CheckActiveBall()
{
    bool activeBallStatus[3] = { false, false, false };                     

    for (int i = 0; i < balls.size(); i++) {
        activeBallStatus[i] = balls[i]->isActive();
    }

    for (int i = balls.size() - 1; i >= 0; i--) {
        if (!activeBallStatus[i]) {
            delete balls[i];
            balls.erase(balls.begin() + i);
        }
    }
}

PongGame::PongGame(){}

PongGame::~PongGame(){}