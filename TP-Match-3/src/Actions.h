#ifndef ACTIONS_H
#define ACTIONS_H

#include "raylib.h"
#include "jewel.h"
#include "Player.h"

namespace M3 {
	namespace ACTIONS {
		void initBoard();
		void initSounds();

		void jewelSelect();
		void jewelDeselect();

		void checkArray();
		void nullJLArray();

		extern int jlArray[3];
		extern Sound jlbreak;
		extern Sound jlselect;
		extern Sound jldeselect;
	}
}

#endif