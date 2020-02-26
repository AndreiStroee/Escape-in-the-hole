#pragma once
#include <String>
#include "Score.h"
using namespace std;

class Player {
private: 
	string name;
	Score score;
public:
	Player();
	string get_name() const;
	int get_score() const;
	void update_score(int amt);
};