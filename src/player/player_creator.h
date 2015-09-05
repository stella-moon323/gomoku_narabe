#pragma once

#include <memory>
#include <algorithm>
#include <type_traits>
#include "player.h"
#include "random/random_player.h"

class player_creator {
public:
	template <typename T, typename C = typename std::enable_if<
	                          std::is_base_of<player, T>::value>::type>
	static std::unique_ptr<player> create() {
		return std::unique_ptr<player>{new T{}};
	}
};
