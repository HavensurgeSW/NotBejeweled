#ifndef ACTIONS_H
#define ACTIONS_H

#include "raylib.h"
#include "jewel.h"
#include "Player.h"

namespace M3 {
	namespace ACTIONS {
		void initBoard();

		void jewelSelect();
		void jewelDeselect();

		void checkArray();
		void nullJLArray();

		extern int jlArray[3];
	}
}

#endif