#include "Actions.h"
#include <iostream>
using namespace std;

namespace M3 {
	namespace ACTIONS {

		int jlArray[3];
		int jlArrayPos = 0;
		Sound jlbreak;
		Sound jlselect;
		Sound jldeselect;

		void initSounds(){
			jlbreak = LoadSound("../res/break.ogg");
			jlselect = LoadSound("../res/selectjl.ogg");
			jldeselect = LoadSound("../res/deselectjl.ogg");
		}

		void nullJLArray() {
			for (int i = 0; i < 4; i++) {
				jlArray[i] = 0;
			}
		}
		void initBoard() {
			for (int i = 0; i < JWL::jlMax; i++) {
				for (int j = 0; j < JWL::jlMax; j++) {
					JWL::jl[i][j].rec.x = 100 + j * 90;
					JWL::jl[i][j].rec.y = 100 + i * 90;
				}
			}
		}
		void jewelSelect() {

			if (jlArrayPos == 0){
				for (int i = 0; i < JWL::jlMax; i++) {
					for (int j = 0; j < JWL::jlMax; j++) {
						JWL::jl[i][j].canBeSelected = true;
					}
				}
			}
			else {
				for (int i = 0; i < JWL::jlMax; i++) {
					for (int j = 0; j < JWL::jlMax; j++) {
						JWL::jl[i][j].canBeSelected = false;
					}
				}
			}

			JWL::selectable();

			for (int i = 0; i < JWL::jlMax; i++) {
				for (int j = 0; j < JWL::jlMax; j++) {
					if (CheckCollisionPointRec(GetMousePosition(), JWL::jl[i][j].rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && JWL::jl[i][j].selected == false&&JWL::jl[i][j].canBeSelected) {
						if (JWL::jl[i][j].id == jlArray[0] || jlArray[0] == 0) {
							JWL::jl[i][j].selected = true;
							jlArray[jlArrayPos] = JWL::jl[i][j].id;
							jlArrayPos++;
							PlaySound(jlselect);
						
						}
					}
				}
			}
		}
		void jewelDeselect() {
			for (int i = 0; i < JWL::jlMax; i++) {
				for (int j = 0; j < JWL::jlMax; j++) {
					if (CheckCollisionPointRec(GetMousePosition(), JWL::jl[i][j].rec) && IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) && JWL::jl[i][j].selected == true) {
						JWL::jl[i][j].selected = false;

#if DEBUG
						cout << "DETECT" << endl;
#endif
						jlArrayPos--;
						jlArray[jlArrayPos] = 0;
						PlaySound(jldeselect);

					}
				}
			}
		}
		void checkArray() {
			if (jlArray[0] == jlArray[0] && jlArray[1] == jlArray[0] && jlArray[2] == jlArray[0]) {
				for (int i = 0; i < JWL::jlMax; i++) {
					for (int j = 0; j < JWL::jlMax; j++) {
						if (JWL::jl[i][j].selected) {
							JWL::jl[i][j].selected = false;
							JWL::jl[i][j].active = false;
							nullJLArray();
							jlArrayPos = 0;
							PLAYER::player.score += 10;
							PlaySound(jlbreak);
						}
					}
				}
			}
			JWL::regenJl();
		}
		void updateArray(){
			
		}

	}

}