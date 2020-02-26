#pragma once

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "MovableGridItem.h"
#include "Tail.h"
#include <vector>

class Snake : public MovableGridItem {
private:
	vector<Tail> tail;
	Mouse* p_mouse;
	static RandomNumberGenerator rng;
public:
	void set_direction(int& dx, int& dy);
	Snake();
	~Snake();
	bool has_caught_mouse();
	void spot_mouse(Mouse* p_mouse);
	void chase_mouse();
	void position_at_random();
	void move_tail(int& dx, int& dy);
	vector<Tail> get_tail(); 
	void reset();
};

