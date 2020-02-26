#include "Snake.h"
#include "Constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include <iostream>

Snake::Snake() : MovableGridItem(SNAKEHEAD, x, y), p_mouse(nullptr)
{
	Tail t1;
	Tail t2;
	Tail t3;

	position_at_random();
	// make the pointer safe before the snake spots the mouse
	tail.push_back(t1);
	tail.push_back(t2);
	tail.push_back(t3);

}

RandomNumberGenerator Snake::rng;

void Snake::reset() {
	position_at_random();
}

Snake::~Snake()
{
	
}


bool Snake::has_caught_mouse()
{
	return is_at_position(p_mouse->get_x(), p_mouse->get_y());
}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: the mouse needs to exist 
	assert(p_mouse != nullptr);

	this->p_mouse = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	move_tail(snake_dx, snake_dy);

	//go in that direction
	update_position(snake_dx, snake_dy);

}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (x < p_mouse->get_x())         // if snake on left of mouse
		dx = 1;                        // snake should move right
	else if (x > p_mouse->get_x())    // if snake on left of mouse
		dx = -1;						       // snake should move left

	if (y < p_mouse->get_y())         // if snake is above mouse
		dy = 1;                        // snake should move down
	else if (y > p_mouse->get_y())    // if snake is below mouse
		dy = -1;						       // snake should move up
}

void Snake::position_at_random()
{
	// WARNING: this may place on top of other things
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}

void Snake::move_tail(int& dx, int& dy) {
	for (int i = tail.size() - 1; i >= 0; i--)
	{
		if (i == 0) {
			tail[i].set_x(x);
			tail[i].set_y(y);
		}
		else {
			tail[i].set_x(tail[i - 1].get_x());
			tail[i].set_y(tail[i - 1].get_y());
		}
	}
}

vector<Tail> Snake::get_tail() {
	return tail;
}


