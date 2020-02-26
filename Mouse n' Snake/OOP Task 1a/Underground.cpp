#include "Underground.h"
#include "FixedGridItem.h"

Hole::Hole() {

}


Hole::Hole(int x, int y): FixedGridItem(HOLE, x, y)
{

}


// number of holes in underground
static const int MAXHOLES(3);

Underground::Underground() : holes(MAXHOLES)
{
}

Hole Underground::get_hole_no(int no) const
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	return holes.at(no);
}

void Underground::set_hole_no_at_position(int no, const int& x, const int& y)
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	Hole h(x, y);

	switch (no)
	{
		case 0: holes.at(0) = h; break;
		case 1: holes.at(1) = h; break;
		case 2: holes.at(2) = h; break;
	}
}

bool Underground::is_valid_hole_number(const int& no) const
{
	return no >= 0 && no < (int)holes.size();
}

vector<Hole> Underground::getHoles() const{
	return holes;
}