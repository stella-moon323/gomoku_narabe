#include <cstdio>

#include "gomoku.h"

int main(int argc, char *argv[]) {
	gomoku g;

	g.print();

	Color winner = g.judge();
	printf("Winner : %s\n", player_color_name[to_int(winner)].c_str());

	return 0;
}
