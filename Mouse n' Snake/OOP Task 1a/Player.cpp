#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(): name(name){ 
	cout << "Please enter your name: ";
	cin >> name;
}

std::string Player::get_name() const{	
	return name;
}

int Player::get_score() const{
	return score.get_amount();
}

void Player::update_score(int amt) {
	return score.update_amount(amt);
}
