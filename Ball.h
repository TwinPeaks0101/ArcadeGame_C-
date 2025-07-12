#pragma once
#include "GameObject.h"
#include "config.h"
#include "sgg/graphics.h"
#include <iostream>
#include "Vector.h"
#include "util.h"
#include <random>

/*(position_x, position_y) και (direction)
για να καθορίζεται πού βρίσκεται και προς τα πού κινείται η μπάλα*/

class Ball : public GameObject, public Collidable {

	Vector2D direction = Vector2D(0.0f, -1.0f);
	float ball_start;
	float position_x = CANVAS_WIDTH / 2;
	float position_y = CANVAS_HEIGHT / 2;
	float size;
	float speed = 3.0f;
	bool active = true;
	bool collided = false;
	graphics::Brush brush;
public:
	Disk getCollisionHull(float x, float y) const override;
	float getX() { return position_x; }
	float getY() { return position_y; }
	bool isActive() { return active; }
	bool isCollided() { return collided; }
	void SetActive(bool a) { active = a; }
	void SetCollided(bool a) { collided = a; }

	//Μέθοδοι αλλαγής κατεύθυνσης
	void ChangeOrientationX() {
		direction.x *= -1.0f;
	}

	void ChangeOrientationY() {
		direction.y *= -1.0f;
	}

	void update() override;
	void draw() override;
	void init() override;
	Ball();
	~Ball();
};
