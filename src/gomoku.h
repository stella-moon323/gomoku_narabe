#pragma once

#include <array>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

enum class Color {
	Empty = 0, // 空き
	Black = 1, // 先手
	White = 2, // 後手
	ColorMax = 3,
};
const std::string board_color_name[] = {" . ", " o ", " x "};
const std::string player_color_name[] = {"None", "Black", "White"};

constexpr int BOARD_SIZE = 15;
constexpr int WIN_TO_LINE_NUM = 5;

struct pos2d {
	pos2d() : x(0), y(0) {}
	pos2d(const int _x, const int _y) : x(_x), y(_y) {}
	int x;
	int y;
};

// 方向
const pos2d direction[] = {
    {0, -1}, // 上
    {1, 0},  // 右
    {0, 1},  // 下
    {-1, 0}, // 左
    {1, -1}, // 右上
    {1, 1},  // 右下
    {-1, 1}, // 左下
    {-1, -1} // 左上
};

template <typename T>
int to_int(const T &val) {
	return static_cast<int>(val);
}

class gomoku {
public:
	gomoku() { init(); }

	// 初期化
	void init() {
		for (auto &row : board) {
			for (auto &c : row) {
				c = Color::Empty;
			}
		}
		current_turn = Color::Black;
		turn_count = 0;
	}

	// 勝敗判定
	Color judge() {
		Color winner = Color::Empty;
		for (int y = 0; y < BOARD_SIZE; ++y) {
			for (int x = 0; x < BOARD_SIZE; ++x) {
				winner = check_position(x, y);
				if (Color::Empty != winner) {
					return winner;
				}
			}
		}
		return winner;
	}

	// 表示
	void print() {
		int row_cnt = 1;
		std::cout << "     ";
		for (int n = 1; n <= BOARD_SIZE; ++n) {
			printf("%2d ", n);
		}
		std::cout << std::endl;
		for (auto &row : board) {
			printf("%2d : ", row_cnt);
			for (auto &c : row) {
				std::cout << board_color_name[to_int(c)];
			}
			std::cout << std::endl;
			++row_cnt;
		}
		std::cout << "Trun : " << (turn_count + 1) << std::endl;
		std::cout << "Current : " << player_color_name[to_int(current_turn)]
		          << std::endl;
	}

	// 空き場所を生成
	std::vector<pos2d> get_empty_pos() {
		std::vector<pos2d> move_list;
		for (int y = 0; y < BOARD_SIZE; ++y) {
			for (int x = 0; x < BOARD_SIZE; ++x) {
				if (Color::Empty == board[y][x]) {
					move_list.emplace_back(pos2d(x, y));
				}
			}
		}
		return move_list;
	}

	// 現在の手番を返す
	Color get_current_turn() { return current_turn; }

	// 手を進める
	bool move(const pos2d &pos) {
		if (Color::Empty != board[pos.y][pos.x]) {
			return false;
		}

		board[pos.y][pos.x] = current_turn;
		change_turn();
		++turn_count;
		return true;
	}

private:
	bool in_board(int x, int y) {
		return ((0 <= x) && (x < BOARD_SIZE) && (0 <= y) && (y < BOARD_SIZE));
	}

	// 指定された位置から5連があるか調べる
	Color check_position(int x, int y) {
		Color col = board[y][x];
		if (Color::Empty == col) {
			return Color::Empty;
		}
		for (const auto dir : direction) {
			if (check_line(x, y, dir, col)) {
				return col;
			}
		}
		return Color::Empty;
	}

	// 指定された方向へ5連があるか調べる
	bool check_line(const int x, const int y, const pos2d &dir,
	                const Color col) {
		int cnt = 1;
		int tmpX = x + dir.x;
		int tmpY = y + dir.y;
		while (in_board(tmpX, tmpY)) {
			if (col != board[tmpY][tmpX]) {
				return false;
			}
			++cnt;
			if (WIN_TO_LINE_NUM <= cnt) {
				return true;
			}
			tmpX += dir.x;
			tmpY += dir.y;
		}

		return false;
	}

	// 手番変更
	void change_turn() {
		current_turn =
		    static_cast<Color>(to_int(Color::ColorMax) - to_int(current_turn));
	}

private:
	std::array<std::array<Color, BOARD_SIZE>, BOARD_SIZE> board; // 局面
	Color current_turn; // 現在のプレイヤー
	int turn_count;
};
