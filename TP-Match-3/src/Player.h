#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

struct Player {
	bool carryActive;
	Vector2 pos;
};
Player player;

void playerClick() { player.carryActive = true; }

#endif