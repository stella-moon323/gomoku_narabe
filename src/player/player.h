#pragma once

#include "../gomoku.h"

class player {
public:
	player() {}
	virtual ~player() {}

	virtual pos2d on_turn(gomoku &g, const std::vector<pos2d> &positions) = 0;
};
