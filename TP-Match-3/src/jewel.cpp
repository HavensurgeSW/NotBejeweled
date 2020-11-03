#include "jewel.h"

namespace M3{
	Jewel _jewels[8][8];
	void initJewel(Jewel jewels[8][8]){
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				//Kind and color
				jewels[i][j].kind = GetRandomValue(0,5);
				switch (jewels[i][j].kind)
				{
					case 0:{
						jewels[i][j].color = RED;
					}break;
					case 1:
					{
						jewels[i][j].color = BLUE;
					}break;
					case 2:
					{
						jewels[i][j].color = GREEN;
					}break;
					case 3:
					{
						jewels[i][j].color = YELLOW;
					}break;
					case 4:
					{
						jewels[i][j].color = VIOLET;
					}break;
					case 5:
					{
						jewels[i][j].color = PINK;
					}break;
				}
				//position in grid
				jewels[i][j].pos_mat.x = j;
				jewels[i][j].pos_mat.y = i;
				//position in screen
				jewels[i][j].pos_xy.x = j * GRID_SIZE*1.4f;
				jewels[i][j].pos_xy.y = i * GRID_SIZE*1.4f;
			}
	}

}