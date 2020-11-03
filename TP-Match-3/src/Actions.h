#pragma once
#include "jewel.h"
#include <iostream>


namespace M3 {
	void swap(Jewel p1, Jewel p2) {
		std::swap(p1.pos_mat.x, p2.pos_mat.x);
		std::swap(p1.pos_mat.y, p2.pos_mat.y);

		_jewels[static_cast<int>(p1.pos_mat.y)][static_cast<int>(p1.pos_mat.x)] = p1;
		_jewels[static_cast<int>(p2.pos_mat.y)][static_cast<int>(p2.pos_mat.x)] = p2;
	}
}
