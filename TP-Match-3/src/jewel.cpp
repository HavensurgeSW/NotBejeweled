#include "jewel.h"

namespace M3{
	namespace JWL {

		Jewel jl[jlMax][jlMax];
		void initJl() {
			for (int i = 0; i < jlMax; i++) {
				for (int j = 0; j < jlMax; j++) {
					jl[i][j].rec.height = 90;
					jl[i][j].rec.width = 90;
					jl[i][j].id = GetRandomValue(1, 5);
					jl[i][j].selected = false;
					jl[i][j].active = true;
					switch (GetRandomValue(1, 5)) {
					case 1:
						jl[i][j].id = 1;
						jl[i][j].color = GREEN;
						jl[i][j].texture = LoadTexture("../res/forest.png");
						break;
					case 2:
						jl[i][j].id = 2;
						jl[i][j].color = SKYBLUE;
						jl[i][j].texture = LoadTexture("../res/island.png");
						break;
					case 3:
						jl[i][j].id = 3;
						jl[i][j].color = RED;
						jl[i][j].texture = LoadTexture("../res/mountain.png");
						break;
					case 4:
						jl[i][j].id = 4;
						jl[i][j].color = RAYWHITE;
						jl[i][j].texture = LoadTexture("../res/plains.png");
						break;
					case 5:
						jl[i][j].id = 5;
						jl[i][j].color = PURPLE;
						jl[i][j].texture = LoadTexture("../res/swamp.png");
						break;
					}
				}
			}
		}
		void regenJl() {
			for (int i = 0; i < jlMax; i++) {
				for (int j = 0; j < jlMax; j++) {
					if (!jl[i][j].active) {
						jl[i][j].id = GetRandomValue(1, 5);
						jl[i][j].selected = false;
						jl[i][j].active = true;
						switch (GetRandomValue(1, 5)) {
						case 1:
							jl[i][j].id = 1;
							jl[i][j].color = GREEN;
							break;
						case 2:
							jl[i][j].id = 2;
							jl[i][j].color = SKYBLUE;
							break;
						case 3:
							jl[i][j].id = 3;
							jl[i][j].color = RED;
							break;
						case 4:
							jl[i][j].id = 4;
							jl[i][j].color = RAYWHITE;
							break;
						case 5:
							jl[i][j].id = 5;
							jl[i][j].color = PURPLE;
							break;

						}

					}
				}
			}
		}
		void drawJl() {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (jl[i][j].active == true) {
						//DrawRectangleRec(jl[i][j].rec, jl[i][j].color);
						DrawTexture(returnTex(jl[i][j].id), jl[i][j].rec.x, jl[i][j].rec.y, RAYWHITE);
						
					}
					if (jl[i][j].selected == true) {
						DrawRectangle(jl[i][j].rec.x, jl[i][j].rec.y, jl[i][j].rec.width, jl[i][j].rec.height, TBLACK);
					}
				}
			}
		}
		Texture2D returnTex(int id) {
			for (int i = 0; i < jlMax; i++) {
				for (int j = 0; j < jlMax; j++) {
					switch (id){
					case 1:
						return LoadTexture("../res/forest.png");
						break;
					case 2:
						return LoadTexture("../res/island.png");
						break;
					case 3:
						return LoadTexture("../res/mountain.png");
						break;
					case 4:
						return LoadTexture("../res/plains.png");
						break;
					case 5:
						return LoadTexture("../res/swamp.png");
						break;

					}
				}
			}
		}
	}
}