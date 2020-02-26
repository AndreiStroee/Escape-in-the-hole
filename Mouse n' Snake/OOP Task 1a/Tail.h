#pragma once
#include "MovableGridItem.h"
#include "Constants.h"

class Tail : public MovableGridItem {
private:

public:
	Tail();
	void set_x(const int& x);
	void set_y(const int& y);
};