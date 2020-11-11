#include "Mainframe.h"

namespace M3 {
	Mainframe::Mainframe() {
		_winWidth = 1280;
		_winHeight = 720;
		_pause = false;
		_mainBool = true;
		_framecounter = 0;
		_secondcounter = 0;
		screenID screenId;
	}
	Mainframe::~Mainframe() {
		CloseAudioDevice();
		CloseWindow();
	}

	void Mainframe::init() {
		screenId = screenID::menu;
		InitWindow(_winWidth, _winHeight, "HSS - Bejeweln't");
		SetTargetFPS(30);
		SetExitKey(KEY_VOLUME_UP);
		InitAudioDevice();
		menuTheme = LoadMusicStream("../res/SpaceDrums.mp3");
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

		while (!WindowShouldClose()) {
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

		PlayMusicStream(menuTheme);
		SetMusicVolume(menuTheme, 0.2f);
		menubg = LoadTexture("../res/menuBG.png");

		while (!WindowShouldClose() && screenId == screenID::menu&&_mainBool) {

			UpdateMusicStream(menuTheme);

			BeginDrawing();
			ClearBackground(BLACK);
			
			DrawTexture(menubg,0,0,RAYWHITE);
			DrawText(FormatText("Bejeweln't"), 20, 10, 120, WHITE);

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


			DrawText(FormatText("v 0.8"), GetScreenWidth() - 50, 1, 20, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), creditsButton)) {
				DrawText(FormatText("Engine: Raylib 3.0"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 20, 30, WHITE);
				DrawText(FormatText("Created by:"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 100, 30, WHITE);
				DrawText(FormatText("Matias P. Karplus"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 130, 30, WHITE);
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

		gamebg = LoadTexture("../res/gamebg.png");
		gameTheme = LoadMusicStream("../res/SpaceSong.mp3");
		Rectangle pauseButton;
		pauseButton.x = GetScreenWidth()/2+ 170;
		pauseButton.y = (GetScreenHeight() / 2) + 150.0f*1.6f;
		pauseButton.height = 30.0f*1.6f;
		pauseButton.width = 81.25f*1.6f;

		JWL::initJl();
		ACTIONS::initBoard();
		ACTIONS::nullJLArray();
		PLAYER::initPlayer();
		ACTIONS::initSounds();
		PlayMusicStream(gameTheme);
		SetMusicVolume(gameTheme,0.1f);

		_pause = false;
		while (!WindowShouldClose()&& screenId == screenID::game|| screenId == screenID::pause) {
			cout << _pause << endl;
			if (screenId == screenID::game && !WindowShouldClose()) {
				input();
				update();
				collisions();
				draw();
			}
			if (screenId == screenID::pause&&!WindowShouldClose()){
				pauseScreen();
			}

		}
	}

	void Mainframe::pauseScreen(){
		Rectangle resumeButton;
		resumeButton.x = GetScreenWidth() - 150;
		resumeButton.y = (GetScreenHeight() / 2) + 150.0f*1.6f;
		resumeButton.height = 30.0f*1.6f;
		resumeButton.width = 81.25f*1.6f;
		Rectangle menuButton;
		menuButton.x = GetScreenWidth() - 150;
		menuButton.y = (GetScreenHeight() / 2) + 210.0f*1.6f;
		menuButton.height = 30.0f*1.6f;
		menuButton.width = 81.25f*1.6f;

		
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText(FormatText("Bejeweln't"), 20, 10, 120, WHITE);
			DrawText(FormatText("Current Score: "), 20, 150, 30*1.6f, RED);
			DrawText(TextFormat("%i", PLAYER::player.score), 416, 150, 30 * 1.6f, WHITE);

			EndDrawing();

			if (CheckCollisionPointRec(GetMousePosition(), resumeButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
				setScene(1);
			}
			if (CheckCollisionPointRec(GetMousePosition(), menuButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
				setScene(0);
			}


			if (_framecounter < 6) {
				_framecounter++;
			}

			if (_framecounter>5) {
				unpause();
			}

			checkMenu();
	}


	void Mainframe::input() {

	}
	void Mainframe::update() {
		UpdateMusicStream(gameTheme);
		JWL::selectable();
		ACTIONS::jewelSelect();
		ACTIONS::jewelDeselect();
		ACTIONS::checkArray();
		if (PLAYER::player.score>=900)
			setScene(0);
		if (_framecounter<6){
			_framecounter++;
		}

		if (_framecounter>5){
			pause();
		}
	}
	void Mainframe::collisions() {
	}
	void Mainframe::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(gamebg,0,0,WHITE);
		JWL::drawJl();
		HUD::drawScore();
		HUD::drawPauseButton();
		EndDrawing();
	}
	void Mainframe::pause(){
		if (IsKeyReleased(KEY_ESCAPE)) {
			screenId = screenID::pause;
			_framecounter = 0;
			
		}
	}

	void Mainframe::unpause() {

		if (IsKeyPressed(KEY_ESCAPE)) {
			screenId = screenID::game;
			_framecounter = 0;
		}
	}
	
	void Mainframe::checkMenu() {
		if (IsKeyDown(KEY_M)) {
			setScene(0);
		}
	}
}