#include <array>
#include <string>
#include <iostream>

namespace {
enum class Color {
	Empty = 0,
	Black = 1,
	White = 2,
	ColorMax = 3,
};

const std::string board_color_name[] = {".", "o", "x"};
const std::string player_color_name[] = {"None", "Black", "White"};

constexpr int BOARD_SIZE = 13;

template <typename T>
int to_int(const T &val) {
	return static_cast<int>(val);
}
};

class gomoku {
public:
	gomoku() { init(); }

	void init() {
		for (auto &row : board) {
			for (auto &c : row) {
				c = Color::Empty;
			}
		}

		current_turn = Color::Black;
	}

	void print() {
		for (auto &row : board) {
			for (auto &c : row) {
				std::cout << board_color_name[to_int(c)];
			}
			std::cout << std::endl;
		}
		std::cout << "Current : " << player_color_name[to_int(current_turn)]
		          << std::endl;
	}

private:
	std::array<std::array<Color, BOARD_SIZE>, BOARD_SIZE> board;
	Color current_turn;
};
