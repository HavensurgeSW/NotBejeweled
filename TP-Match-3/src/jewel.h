#ifndef JEWEL_H
#define JEWEL_H
#include "raylib.h"

namespace M3{
	namespace JWL{

		//COLORS//
#define TBLACK      CLITERAL(Color){ 0, 0, 0, 120 }

		struct Jewel {
			Rectangle rec;
			int id;
			Color color;
			Texture2D texture;
			bool selected;
			bool active;
		};
		const int jlMax = 6;
		extern Jewel jl[jlMax][jlMax];
		void initJl();
		void regenJl();
		void drawJl();

		Texture2D returnTex(int id);
	}
}
#endif JEWEL_H