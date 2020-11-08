#include "jewel.h"

namespace M3{

	Jewel jl[jlMax][jlMax];
	void initJl() {
		for (int i = 0; i < jlMax; i++){
			for (int j = 0; j < jlMax; j++){
				jl[i][j].rec.height = 90;
				jl[i][j].rec.width = 90;
				jl[i][j].id = GetRandomValue(1, 5);
				jl[i][j].selected = false;
				switch (GetRandomValue(1,5)){
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