#include "MovableGridItem.h"

MovableGridItem::MovableGridItem(char symbol, int x, int y): GridItem(symbol), x(x), y(y) {

}

int MovableGridItem::get_x() const{
	return x;
}

int MovableGridItem::get_y() const{
	return y;
}

bool MovableGridItem::is_at_position(const int& x, const int& y) const{
	return this->x == x && this->y == y;
}

void MovableGridItem::reset_position(int x, int y) {
	//add later
}

void MovableGridItem::update_position(const int& dx, const int& dy) {
	x += dx;
	y += dy;
}

void MovableGridItem::set_position(const int x, const int y) {
	this->x = x;
	this->y = y;
}

