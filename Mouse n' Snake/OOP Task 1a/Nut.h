#pragma once
#include "Snake.h"
#include <iostream>
#include "MovableGridItem.h"
#include "RandomNumberGenerator.h"

class Nut: public MovableGridItem {
private: 
	bool collected;
	RandomNumberGenerator rng;
public:
	Nut();
	bool is_at_position(const int& x, const int& y);
	bool has_been_collected();
	void disappear();
	void position_at_random();
	void reset();
};