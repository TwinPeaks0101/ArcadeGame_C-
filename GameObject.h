#pragma once
#include "util.h"

/*Framework πάνω στο οποίο χτίζονται αντικείμενα του παιχνιδιού και διεπαφή για τον έλεγχο συγκρούσεων*/

class Collidable { //interface

public:
	virtual Disk getCollisionHull(float x, float y) const = 0;
};

class GameObject {

public:
	virtual void update();
	virtual void draw();
	virtual void init();
	GameObject();
	~GameObject();
};
