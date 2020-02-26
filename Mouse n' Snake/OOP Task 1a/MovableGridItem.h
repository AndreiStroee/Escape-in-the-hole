#pragma once
#include "GridItem.h"
#include "RandomNumberGenerator.h"
class MovableGridItem : public GridItem {
protected:
	int x;
	int y;
public:
	MovableGridItem(char symbol, int x, int y);
	int get_x() const;
	int get_y() const;
	bool is_at_position(const int& x, const int& y) const;
	void reset_position(int x, int y);
	void update_position(const int& dx, const int& dy);
	void set_position(const int x, const int y);
};