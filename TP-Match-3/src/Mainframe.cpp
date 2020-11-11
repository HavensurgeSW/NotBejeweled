#include "Mainframe.h"

namespace M3 {
	Mainframe::Mainframe() {
		_winWidth = 1280;
		_winHeight = 720;
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

		

#if DEBUG
	
#endif
		
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
		playButton.height = 30.0f*1.6f;
		playButton.width = 65.0f*1.6f;

		Rectangle tutorialButton;
		tutorialButton.x = 20.0f;
		tutorialButton.y = (GetScreenHeight() / 2.0f) + 50.0f*1.6f;
		tutorialButton.height = 30.0f*1.6f;
		tutorialButton.width = 129.0f*1.6f;

		Rectangle creditsButton;
		creditsButton.x = 20.0f;
		creditsButton.y = (GetScreenHeight() / 2) + 100.0f*1.6f;
		creditsButton.height = 30.0f*1.6f;
		creditsButton.width = 113.0f*1.6f;
		Rectangle closeButton;
		closeButton.x = 20.0f;
		closeButton.y = (GetScreenHeight() / 2) + 150.0f*1.6f;
		closeButton.height = 30.0f*1.6f;
		closeButton.width = 81.25f*1.6f;

		while (!WindowShouldClose() && screenId == screenID::menu&&_mainBool) {
			BeginDrawing();
			ClearBackground(BLACK);
			

			DrawText(FormatText("Match 3"), 20, 10, 120, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), playButton))
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2 , 30*1.6f, RED);
			else
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2 , 30*1.6f, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), tutorialButton))
				DrawText(FormatText("Tutorial"), 20, (GetScreenHeight() / 2)+50 * 1.6f, 30 * 1.6f, RED);
			else
				DrawText(FormatText("Tutorial"), 20, (GetScreenHeight() / 2)+50 * 1.6f, 30 * 1.6f, WHITE);


			if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100 * 1.6f, 30 * 1.6f, RED);
			else
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100 * 1.6f, 30 * 1.6f, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), closeButton))
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150 * 1.6f, 30 * 1.6f, RED);
			else
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150 * 1.6f, 30 * 1.6f, WHITE);


			DrawText(FormatText("v 0.1"), GetScreenWidth() - 50, 1, 20, WHITE);
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
	void Mainframe::gameScreen(){

		JWL::initJl();
		ACTIONS::initBoard();
		ACTIONS::nullJLArray();
		PLAYER::initPlayer();

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
		JWL::selectable();
		ACTIONS::jewelSelect();
		ACTIONS::jewelDeselect();
		ACTIONS::checkArray();
		if (PLAYER::player.score>=900){
			setScene(0);
		}
	}
	void Mainframe::collisions() {
		
	}
	void Mainframe::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		JWL::drawJl();
		HUD::drawScore();
		
		EndDrawing();
	}

}