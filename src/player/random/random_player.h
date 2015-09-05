#pragma once

#include <random>
#include "../player.h"

class random_player : public player {
public:
	random_player() {
		std::random_device rdev;
		rnd.seed(rdev());
	}
	virtual ~random_player() {}

	virtual pos2d on_turn(gomoku &g, const std::vector<pos2d> &positions) {
		return positions[generate_random(0, positions.size() - 1)];
	}

	int generate_random(int min, int max) {
		std::uniform_int_distribution<int> dist(min, max);
		return dist(rnd);
	}

private:
	std::mt19937 rnd;
};
