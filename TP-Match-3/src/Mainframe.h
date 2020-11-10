#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "raylib.h"
#include "jewel.h"
#include "Actions.h"
#include "HUD.h"
//#include "Player.h"
//#include "Actions.h"

#include <iostream>
using namespace std;


namespace M3 {
	class Mainframe {
	private:
		int _winWidth;
		int _winHeight;
		bool _pause;
		bool _mainBool;

	public:
		enum class screenID {
			menu,
			game
		};
		screenID screenId;

		Mainframe();
		~Mainframe();
		void init();
		void setScene(int scene);
		void mainLoop();
		void menuScreen();
		void gameScreen();
		
		void update();
		void draw();
		void input();
		void collisions();
	};
}
#endif