#pragma once
#include "GameObject.h"
#include "config.h"
#include <iostream>
#include <vector>

//Θέση και κίνηση ρακετών , σκορ παίκτη
class Player : public GameObject, public Collidable {
	float speed = 10.0f;
	float pos_x = CANVAS_WIDTH / 8;
	float pos_y = CANVAS_HEIGHT / 2;
	float thesi_x = 7 * (CANVAS_WIDTH) / 8;
	float thesi_y = CANVAS_HEIGHT / 2;
	float player_goals = 0.0f;
/*Ενημέρωση της θέσης και εμφάνιση των ρακετών.
Επιπλέον η κλάση κληρονομεί και από την Collidable για τον έλεγχο σύγκρουσης*/
public:
	Disk getCollisionHull(float x, float y) const override;
	void update() override;
	void draw() override;
	void init() override;
	float getX1() { return pos_x; }
	float getY1() { return pos_y; }
	float getX2() { return thesi_x; }
	float getY2() { return thesi_y; }
	void setPlayerGoals();
	void resetPlayerGoals();

	float getPlayerGoals();

	Player();
	~Player();
};
