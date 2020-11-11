#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "raylib.h"
#include "jewel.h"
#include "Actions.h"
#include "HUD.h"
#include "Player.h"


#include <iostream>
using namespace std;


namespace M3 {
	class Mainframe {
	private:
		int _winWidth;
		int _winHeight;
		bool _pause;
		bool _mainBool;
		int _framecounter;
		int _secondcounter;


	public:
		enum class screenID {
			menu,
			game,
			pause
		};
		screenID screenId;
		Music menuTheme;
		Music gameTheme;
		Texture2D menubg;
		Texture2D gamebg;

		Mainframe();
		~Mainframe();
		void init();
		void setScene(int scene);
		void mainLoop();
		void menuScreen();
		void gameScreen();
		void pauseScreen();
		
		void update();
		void draw();
		void input();
		void collisions();

		void pause();
		void unpause();
		void checkMenu();
	};
}
#endif