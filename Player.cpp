#include "Player.h"
#include "sgg/graphics.h"
#include "config.h"

/* 'Ελεγχος ορίων, σχεδίαση των ρακετών, getters/setters για το σκορ */

void Player::update()
{             /*Κίνηση πρώτου παίκτη*/
	if (graphics::getKeyState(graphics::SCANCODE_W)) { 
		pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S)) {
		pos_y += speed * graphics::getDeltaTime() / 10.0f;
	}         /*Κίνηση δεύτερου παίκτη*/
	if (graphics::getKeyState(graphics::SCANCODE_UP)) {
		thesi_y -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
		thesi_y += speed * graphics::getDeltaTime() / 10.0f;
	}


	if (pos_y - 30 < 0) {
		pos_y = 30;
	}
	if (pos_y + 30 > CANVAS_HEIGHT) {
		pos_y = CANVAS_HEIGHT - 30;
	}


	if (thesi_y - 30 < 0) {
		thesi_y = 30;
	}
	if (thesi_y + 30 > CANVAS_HEIGHT) {
		thesi_y = CANVAS_HEIGHT - 30;
	}


}

void Player::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	graphics::drawRect(pos_x, pos_y, 10, 60, br);

	graphics::Brush bru;
	br.fill_color[0] = 1.0f;
	graphics::drawRect(thesi_x, thesi_y, 10, 60, bru);



	br.outline_opacity = 1.0f;
	br.texture = "";
	br.fill_color[0] = 0.3f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = .3f;
	br.fill_opacity = 0.3f;
	br.gradient = false;

}


void Player::init(){}

void Player::setPlayerGoals(){player_goals++;} /*Αυξάνει το σκορ του παίκτη κατά 1*/

void Player::resetPlayerGoals(){player_goals = 0.0f;}/*Μηδενίζει το σκορ του παίκτη*/

float Player::getPlayerGoals(){return player_goals;}/*Επιστρέφει το τρέχον σκορ του παίκτη*/

Player::Player(){}

Player::~Player(){}
Disk Player::getCollisionHull(float x, float y) const
{
	Disk disk;
	disk.cx = x;
	disk.cy = y;
	disk.radius = 5.0f;
	return disk;
}