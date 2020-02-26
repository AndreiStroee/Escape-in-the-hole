#pragma once
#include <string>
class Score {
private:
	int amount = 0;
public:
	Score();
	int get_amount() const;
	void update_amount(int amt);
};