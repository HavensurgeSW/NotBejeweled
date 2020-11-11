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
			bool canBeSelected;
		};
		extern Texture2D forest;
		extern Texture2D island;
		extern Texture2D mountain;
		extern Texture2D plains;
		extern Texture2D swamp;

		const int jlMax = 6;
		extern Jewel jl[jlMax][jlMax];
		void initJl();
		void regenJl();
		void drawJl();
		Texture2D returnTex(int id);
		void selectable();

	}
}
#endif JEWEL_H