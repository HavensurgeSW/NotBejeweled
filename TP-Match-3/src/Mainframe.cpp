#include "Mainframe.h"


namespace M3 {
	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;
		_pause = false;
		_mainBool = true;
		screenID screenId;
	
	}
	Mainframe::~Mainframe() {
		CloseAudioDevice();
		CloseWindow();
	}

	void Mainframe::init() {
		screenId = screenID::menu;
		InitWindow(_winWidth, _winHeight, "HSS - Match 3");
		SetTargetFPS(60);
		SetExitKey(KEY_VOLUME_UP);
		InitAudioDevice();
	}
	void Mainframe::setScene(int scene) {
		switch (scene) {
		case 0:
			screenId = screenID::menu;
			break;
		case 1:
			screenId = screenID::game;
			break;
		}
	}
	void Mainframe::mainLoop() {

		while (!WindowShouldClose() && _mainBool) {
			switch (screenId) {
			case screenID::menu:
				menuScreen();
			case screenID::game:
				gameScreen();
			}
		}
	}
	void Mainframe::menuScreen() {

		Rectangle playButton;
		playButton.x = 20.0f;
		playButton.y = GetScreenHeight() / 2.0f;
		playButton.height = 30.0f;
		playButton.width = 65.0f;

		Rectangle tutorialButton;
		tutorialButton.x = 20.0f;
		tutorialButton.y = (GetScreenHeight() / 2.0f) + 50.0f;
		tutorialButton.height = 30.0f;
		tutorialButton.width = 129.0f;

		Rectangle creditsButton;
		creditsButton.x = 20.0f;
		creditsButton.y = (GetScreenHeight() / 2) + 100.0f;
		creditsButton.height = 30.0f;
		creditsButton.width = 113.0f;
		Rectangle closeButton;
		closeButton.x = 20.0f;
		closeButton.y = (GetScreenHeight() / 2) + 150.0f;
		closeButton.height = 30.0f;
		closeButton.width = 81.25f;



		while (!WindowShouldClose() && screenId == screenID::menu&&_mainBool) {
		
			BeginDrawing();
			ClearBackground(BLACK);
			

			DrawText(FormatText("Match 3"), 20, 10, 120, BLACK);

			if (CheckCollisionPointRec(GetMousePosition(), playButton))
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, RED);
			else
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), tutorialButton))
				DrawText(FormatText("Tutorial"), 20, (GetScreenHeight() / 2)+50, 30, RED);
			else
				DrawText(FormatText("Tutorial"), 20, (GetScreenHeight() / 2)+50, 30, WHITE);


			if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, RED);
			else
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), closeButton))
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, RED);
			else
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, WHITE);


			DrawText(FormatText("v 0.5"), GetScreenWidth() - 50, 1, 20, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), creditsButton)) {
				DrawText(FormatText("Engine: Raylib 3.0"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 20, 30, WHITE);
				DrawText(FormatText("Created by:"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 100, 30, WHITE);
				DrawText(FormatText("Matias P. Karplus"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 130, 30, WHITE);
			}

			if (CheckCollisionPointRec(GetMousePosition(), tutorialButton)) {

			}


			EndDrawing();
			if (CheckCollisionPointRec(GetMousePosition(), closeButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
				exit(0);
			}
			if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
				setScene(1);
			}
		}
		
	}
	void Mainframe::gameScreen() {

		while (!WindowShouldClose() && screenId == screenID::game&&_mainBool) {
			if (!_pause) {
				input();
				update();
#if DEBUG
		
#endif
				collisions();
				draw();
			}

		}
	}


	void Mainframe::input() {

	}
	void Mainframe::update() {

		
	}
	void Mainframe::collisions() {
		
	}
	void Mainframe::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		
#if DEBUG
		
#endif

		EndDrawing();
	}

}