#include "Score.h"
Score::Score() {}

int Score::get_amount() const{
	return amount;
}

void Score::update_amount(int amt) {
	amount += amt;
}
