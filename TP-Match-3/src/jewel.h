#ifndef JEWEL_H
#define JEWEL_H
#include "raylib.h"

namespace M3{

	struct Jewel{	
		Rectangle rec;
		int id;
		Color color;
		Texture2D texture;
		bool selected;
	};
	const int jlMax = 6;
	extern Jewel jl[jlMax][jlMax];
	void initJl();
}
#endif JEWEL_H