#include "HUD.h"

namespace M3 {
	namespace HUD {
		void drawScore() {
			DrawText(FormatText("Score:"), GetScreenWidth()/2+170, 100 ,30 * 1.6f, RED);
			DrawText(TextFormat("%i", PLAYER::player.score), GetScreenWidth() / 2 + 355, 100, 30*1.6f, LIGHTGRAY);

			DrawText(FormatText("Target Score: 900"), GetScreenWidth() / 2 + 170, 150, 30 * 1.6f, WHITE);
			
		}
	}
}