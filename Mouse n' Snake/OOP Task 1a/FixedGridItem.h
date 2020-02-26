#pragma once
#include "GridItem.h"
class FixedGridItem : public GridItem {
protected:
	int x;
	int y;
public:
	FixedGridItem();
	FixedGridItem(char symbol, int x, int y);
	int get_x() const;
	int get_y() const;
	bool is_at_position(const int& x, const int& y) const;
};