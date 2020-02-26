#pragma once

#include <cassert>
#include <vector>

#include "constants.h"
#include "FixedGridItem.h"

using namespace std;


class Hole : public FixedGridItem {
public:
	Hole();
	Hole(int x, int y);
private:

};

class Underground
{
public:
	Underground();
	Hole get_hole_no(int no) const;
	void set_hole_no_at_position(int no, const int& x, const int& y);
	vector<Hole> getHoles() const;
private:
	bool is_valid_hole_number(const int& n) const;
	vector<Hole> holes;
};