#include "Actions.h"
#include <iostream>
using namespace std;

namespace ACTIONS {

	int jlArray[3];
	int jlArrayPos = 0;

	void nullJLArray() {
		for (int i = 0; i < 4; i++){
			jlArray[i] = 0;
		}
	}

	void initBoard() {
		for (int i = 0; i < jlMax; i++) {
			for (int j = 0; j < jlMax; j++) {
				jl[i][j].rec.x = 100 + j * 90;
				jl[i][j].rec.y = 100 + i * 90;
			}
		}
	}

	void jewelSelect() {
		for (int i = 0; i < jlMax; i++) {
			for (int j = 0; j < jlMax; j++) {
				if (CheckCollisionPointRec(GetMousePosition(), jl[i][j].rec)&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON)&& jl[i][j].selected == false) {
					if (jl[i][j].id==jlArray[0]||jlArray[0]==0) {
						jl[i][j].selected = true;
						jlArray[jlArrayPos] = jl[i][j].id;
						jlArrayPos++;
					}
				}
			}
		}
	}

	void jewelDeselect() {
		for (int i = 0; i < jlMax; i++) {
			for (int j = 0; j < jlMax; j++) {
				if (CheckCollisionPointRec(GetMousePosition(), jl[i][j].rec) && IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) && jl[i][j].selected == true) {
					jl[i][j].selected = false;

#if DEBUG
					cout << "DETECT" << endl;
#endif
					jlArrayPos--;
					jlArray[jlArrayPos] = 0;
					
				}
			}
		}
	}


	void checkArray(){
		if (jlArray[0]==jlArray[0]&& jlArray[1] == jlArray[0] && jlArray[2] == jlArray[0]){
			for (int i = 0; i < jlMax; i++) {
				for (int j = 0; j < jlMax; j++) {
					if (jl[i][j].selected){
						jl[i][j].selected = false;
						jl[i][j].color = BLACK;
						nullJLArray();
						jlArrayPos = 0;
					}
				}
			}
		}
	}
}