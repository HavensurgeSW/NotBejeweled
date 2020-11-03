#ifndef JEWEL_H
#define JEWEL_H

#include "raylib.h"

namespace M3
{
	const int GRID_SIZE = 54;
	struct Jewel
	{
		Vector2 pos_xy;		//where will draw in XY
		Vector2 pos_mat;	//where will be in the grid
		//X will be columns and Y will be row
		int kind;			//type of jewel
		int match;			//this way, if there's more than 2 matches, it will be destroyed
		Color color;
		Texture2D texture;
	};
	
	extern Jewel _jewels[8][8];
	void initJewel(Jewel jewels[8][8]);

}
#endif JEWEL_H