#include "Ball.h"
#include "sgg/graphics.h"
#include "config.h"
#include <iostream>
#include "player.h"

/*Δημιουργία μπάλας & έλεγχος αν υπάρχει σύγκρουση με άλλα αντικείμενα*/

Disk Ball::getCollisionHull(float x, float y) const
{
	Disk disk;
	disk.cx = x;
	disk.cy = y;
	disk.radius = 18.0f;
	return disk;
}

/*Έλεγχος αν η μπάλα έχει περάσει πέρα από το ένα από τα δύο άκρα του καμβά. Αν ναι active = false */
void Ball::update()
{
	if (getX() <= CANVAS_WIDTH / 8 - 20 || getX() >= 7 * (CANVAS_WIDTH) / 8 + 20)
	{
		active = false;
	}
/*Ενημέρωση συντεταγμένων της μπάλας και προσαρμογή της κίνησης με τον χρόνο */
	position_x += direction.x * speed * graphics::getDeltaTime() / 10.0f;
	position_y -= direction.y * speed * graphics::getDeltaTime() / 10.0f;
	

	if (position_y > WINDOW_HEIGHT - 100 || position_y < 0.0f) {
/*Ανακατεύθυνση της μπάλας*/
		ChangeOrientationY();
	}

}
/*Αρχικοποίηση μπάλας*/
void Ball::draw()
{

	brush.outline_opacity = 0.0f;
	brush.texture = std::string(ASSET_PATH) + "ball.png";
	brush.fill_opacity = 1.0f;
	graphics::drawRect(position_x, position_y, 40, 50, brush);
}

void Ball::init()
{
	ball_start = rand() % 6 + 1;
	float ori = 133.0f * ball_start;
	direction.fromAngle(ori);
	speed = 3.0f;
}

Ball::Ball(){init();}

Ball::~Ball(){}