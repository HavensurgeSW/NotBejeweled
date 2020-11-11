#include "jewel.h"

namespace M3{
	namespace JWL {

		Texture2D forest;
		Texture2D island;
		Texture2D mountain;
		Texture2D plains;
		Texture2D swamp;

	
		Jewel jl[jlMax][jlMax];
		void initJl() {
			forest = LoadTexture("../res/forest.png");
			island = LoadTexture("../res/island.png");
			mountain = LoadTexture("../res/mountain.png");
			plains = LoadTexture("../res/plains.png");
			swamp = LoadTexture("../res/swamp.png");

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
						jl[i][j].texture = forest;
						break;
					case 2:
						jl[i][j].id = 2;
						jl[i][j].color = SKYBLUE;
						jl[i][j].texture = island;
						break;
					case 3:
						jl[i][j].id = 3;
						jl[i][j].color = RED;
						jl[i][j].texture = mountain;
						break;
					case 4:
						jl[i][j].id = 4;
						jl[i][j].color = RAYWHITE;
						jl[i][j].texture = plains;
						break;
					case 5:
						jl[i][j].id = 5;
						jl[i][j].color = PURPLE;
						jl[i][j].texture = swamp;
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
						return forest;
						break;
					case 2:
						return island;
						break;
					case 3:
						return mountain;
						break;
					case 4:
						return plains;
						break;
					case 5:
						return swamp;
						break;

					}
				}
			}
		}

		void selectable(){
			for (int i = 0; i < jlMax; i++) {
				for (int j = 0; j < jlMax; j++) {
					if (jl[i - 1][j].selected||
						jl[i][j - 1].selected||
						jl[i-1][j-1].selected||
						jl[i+1][j].selected ||
						jl[i][j+1].selected ||
						jl[i+1][j+1].selected ||
						jl[i-1][j+1].selected ||
						jl[i+1][j-1].selected){

						jl[i][j].canBeSelected = true;
					}

				}
			}
		}
	}
}