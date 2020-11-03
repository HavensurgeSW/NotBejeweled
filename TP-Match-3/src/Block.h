#pragma once
#include "raylib.h"

namespace M3 {
	struct Block {
		Rectangle rec;
		int id;
		Color color;
	};

	const int gridSize = 6;
	extern Block block[gridSize][gridSize];

	Block genBlock(Block b, int x);
	void createBoard();
}