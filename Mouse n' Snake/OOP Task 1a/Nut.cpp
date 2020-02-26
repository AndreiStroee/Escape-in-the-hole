#include "Nut.h"
#include "Constants.h"
#include "MovableGridItem.h"

Nut::Nut(): MovableGridItem(NUT, x, y) {

	position_at_random();
}

bool Nut::is_at_position(const int& x, const int& y){
	if (this->x == x && this->y == y) {
		collected = true;
		disappear();
		return true;
	}
	else {
		return false;
	}
}

bool Nut::has_been_collected() 
{
	return collected;
}

void Nut::reset() {
	this->x = x;
	this->y = y;
	this->collected = false;
	this->symbol = NUT;
	position_at_random();
}

void Nut::disappear() {
	if (has_been_collected()) {
		symbol = FREECELL;
	}
}

void Nut::position_at_random() {
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}