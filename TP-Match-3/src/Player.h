#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

namespace M3 {
	namespace PLAYER {
		struct Player {
			int score;
		};
		extern Player player;

		void initPlayer();
	}
}
#endif