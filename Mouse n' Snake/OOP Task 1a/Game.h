#pragma once

#include <string>		
#include <assert.h>	
#include <vector>
#include <sstream>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "Nut.h"
#include "Player.h"
using namespace std;

class Game
{
private:
	Nut nut;
	Player player;
	Snake snake;
	Mouse mouse;
	Underground underground;
	void apply_rules();
	int find_hole_number_at_position(const int& x, const int& y) const;
public:
	void set_up();
	void process_input(const int& key);
	vector<vector<char>> prepare_grid();
	bool is_running() const;
	string get_end_reason();
	void reset_game();
	void tunnel();
	string get_player_name();
	string get_player_score();
};