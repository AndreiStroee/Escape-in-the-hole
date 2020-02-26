#include "Game.h"

void Game::set_up()
{
	// set up the holes
	underground.set_hole_no_at_position(0, 4, 3);
	underground.set_hole_no_at_position(1, 15, 10);
	underground.set_hole_no_at_position(2, 7, 15);

	// mouse state already set up in its contructor

   // set up snake
	while ((snake.get_x() != mouse.get_x()) && (snake.get_y() != mouse.get_y())) {
		snake.position_at_random();
	}
	snake.spot_mouse(&mouse);

	//set up nut
	while ((nut.get_x() != mouse.get_x()) && (nut.get_y() != mouse.get_y())) {
		nut.position_at_random();
	}
}

void Game::tunnel() {
	if (find_hole_number_at_position(mouse.get_x(), mouse.get_y()) == 0) {
		mouse.set_position(15, 10);
	}
	else if (find_hole_number_at_position(mouse.get_x(), mouse.get_y()) == 1) {
		mouse.set_position(7, 15);
	}
	else {
		mouse.set_position(15, 10);
	}
}

string Game::get_player_name()
{
	return "Player: " + player.get_name();
}

string Game::get_player_score()
{
	stringstream ss;
	ss << "Score: " << player.get_score();
	return ss.str();
}

void Game::reset_game()
{
	mouse.reset();
	nut.reset();
	snake.reset();
}

void Game::process_input(const int& key)
{
	mouse.scamper(key);
	snake.chase_mouse();
	apply_rules();
}

vector<vector<char>> Game::prepare_grid()
{
	// create the 2D grid
	vector<vector<char>> grid;

	// for each row
	for (int row = 1; row <= SIZE; ++row)
	{
		// create a row to add to the 2D grid
		vector<char> line;

		// for each column
		for (int col = 1; col <= SIZE; ++col)
		{
			// is the snake at this position?
			if (row == snake.get_y() && col == snake.get_x())
			{
				line.push_back(snake.get_symbol());
			}
			// is the mouse at this position?
			else if (row == mouse.get_y() && col == mouse.get_x())
			{
				line.push_back(mouse.get_symbol());
			}
			else if (row == snake.get_tail()[0].get_y() && col == snake.get_tail()[0].get_x()) {
				line.push_back(snake.get_tail()[0].get_symbol());
			}
			else if (row == snake.get_tail()[1].get_y() && col == snake.get_tail()[1].get_x()) {
				line.push_back(snake.get_tail()[1].get_symbol());
			}
			else if (row == snake.get_tail()[2].get_y() && col == snake.get_tail()[2].get_x()) {
				line.push_back(snake.get_tail()[2].get_symbol());
			}
			else if (row == nut.get_y() && col == nut.get_x())
			{
				line.push_back(nut.get_symbol());
			}
			else
			{

				// is there a hole at this position?
				const int hole_no = find_hole_number_at_position(col, row);

				if (hole_no != -1)
				{
					line.push_back(underground.get_hole_no(hole_no).get_symbol());
				}
				else
				{
					// none of the above, must be nothing at this position
					line.push_back(FREECELL);
				}
			}


		}

		// now that the row is full, add it to the 2D grid
		grid.push_back(line);
	}

	return grid;
}

int Game::find_hole_number_at_position(const int& x, const int& y) const
{
	for (size_t h_no = 0; h_no < underground.getHoles().size(); ++h_no)
	{
		if (underground.get_hole_no(h_no).is_at_position(x, y))
		{
			return h_no;
		}
	}
	return -1; // not a hole
}

void Game::apply_rules()
{

	if (snake.has_caught_mouse())
	{
		player.update_score(-1);
		cout << "Score: ";
		cout << player.get_score();
		mouse.die();
	}
	else
	{
		if (mouse.has_reached_a_hole(underground) && nut.has_been_collected())
		{
			player.update_score(1);
			cout << "Score: " << player.get_score();
			mouse.escape_into_hole();
		}
		if (mouse.has_reached_a_hole(underground) && !nut.has_been_collected()) 
		{
			tunnel();
		}

	}

	nut.is_at_position(mouse.get_x(), mouse.get_y());
}

bool Game::is_running() const
{
	return mouse.is_alive() && !mouse.has_escaped();
}


string Game::get_end_reason()
{
	if (mouse.has_escaped() && nut.has_been_collected()) {
		return "You escaped underground!";
	}
	else if (mouse.has_escaped()) {
		return "get nut";
	}
	else {
		return "The snake ate you";
	}
}
