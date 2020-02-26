#include "FixedGridItem.h"

FixedGridItem::FixedGridItem() {

}

FixedGridItem::FixedGridItem(char symbol, int x, int y) : GridItem(symbol), x(x), y(y) {

}

int FixedGridItem::get_x() const{
	return x;
}

int FixedGridItem::get_y() const{
	return y;
}

bool FixedGridItem::is_at_position(const int& x, const int& y) const{
	return this->x == x && this->y == y;
}
