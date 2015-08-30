#set(CMAKE_VERBOSE_MAKEFILE 1)

# 最低バージョン
cmake_minimum_required(VERSION 3.1.2)

# 環境変数設定
set(CMAKE_CXX_COMPILER clang++)

# フラグ設定
add_definitions(-O2 -g -std=c++14
	-Wall -Wextra -Winit-self -Wno-unused-parameter -Wfloat-equal)

# サブディレクトリ設定
#add_subdirectory(src)

# 実行ファイル設定
add_executable(gomoku
	src/main.cpp
)

# リンク設定
#target_link_libraries(gomoku)

