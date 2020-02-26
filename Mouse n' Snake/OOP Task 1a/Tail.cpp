#include "Tail.h"

Tail::Tail() : MovableGridItem(TAIL, x, y) {

}

void Tail::set_x(const int& x) {
	this->x = x;
}

void Tail::set_y(const int& y) {
	this->y = y;
}