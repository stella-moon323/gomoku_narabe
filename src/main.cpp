#include <cstdio>

#include "gomoku.h"
#include "player/player_creator.h"

int main(int argc, char *argv[]) {
	gomoku g;
	auto player_black = player_creator::create<random_player>();
	auto player_white = player_creator::create<random_player>();
	Color winner = Color::Empty;

	while (true) {
		g.print();
		auto positions = g.get_empty_pos();

		pos2d pos;
		if (Color::Black == g.get_current_turn()) {
			pos = player_black->on_turn(g, positions);
		} else {
			pos = player_white->on_turn(g, positions);
		}

		printf("move[%d, %d]\n", pos.x + 1, pos.y + 1);
		if (!g.move(pos)) {
			throw;
			break;
		}

		winner = g.judge();
		if (Color::Empty != winner) {
			break;
		}
		printf("\n");
	}

	g.print();
	if (Color::Empty != winner) {
		printf("Winner : %s\n", player_color_name[to_int(winner)].c_str());
	} else {
		printf("Drow\n");
	}

	return 0;
}
