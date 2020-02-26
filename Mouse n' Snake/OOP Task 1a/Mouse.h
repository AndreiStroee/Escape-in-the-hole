#pragma once

#include "constants.h"
#include "Underground.h"
#include "MovableGridItem.h"
#include "RandomNumberGenerator.h"

class Mouse : public MovableGridItem {
public:
	Mouse();
	bool is_alive() const;
	bool has_escaped() const;
	bool has_reached_a_hole(const Underground& ug);
	void die();
	void escape_into_hole();
	void scamper(const int& key);
	void reset();
private:
	bool alive;
	bool escaped;
	int mouse_dx;
	int mouse_dy;
	//void position_in_middle_of_grid();
	void position_at_random();
	RandomNumberGenerator rng;
};
