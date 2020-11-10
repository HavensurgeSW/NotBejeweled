#include "HUD.h"

namespace M3 {
	namespace HUD {
		void drawScore() {
			DrawText(FormatText("Score:"), GetScreenWidth()/2+200, 100 ,30 * 1.6f, RED);
			//DrawText(TextFormat("%i", player.score), GetScreenWidth() / 2 + 250, 100, 20*1.6f, LIGHTGRAY);
		}
	}
}