#include "LoadingScreen.h"

double LoadingScreen::timeCounter = 0;
double LoadingScreen::timeLoading = 5;
Constants::SCREEN_STATE LoadingScreen::nextScreen = Constants::SS_NONE;
bool LoadingScreen::isLoading = false;
double LoadingScreen::percent = 0;

void LoadingScreen::Render() {
	SDL_Texture* texture = Draw::GetTexture("resources/sprites/menu.jpg");
	SDL_SetTextureAlphaMod(texture, 100);
	Draw::FullImage("resources/sprites/menu.jpg", { Constants::WINDOW_WIDTH / 2, Constants::WINDOW_HEIGHT / 2, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT });
	SDL_SetTextureAlphaMod(texture, 155);
	//Draw::Rect({ 0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT }, { 255, 255, 255, 100 });

	Draw::PercentBar(
		Constants::WINDOW_WIDTH / 2, Constants::WINDOW_HEIGHT / 2, 200, 20,
		4, LoadingScreen::percent, 100,
		{ 255, 255, 255, 255 }, { 255, 0, 0, 255 }, { 0, 0, 0, 255 }
	);
}

void LoadingScreen::Update() {
	static int frameCount = timeLoading / Constants::DELTA_TIME;
	static double percentPerFrame = 100.0 / frameCount;
	percent += percentPerFrame;
	percent = (percent < 100) ? percent : 100;

	if (!LoadingScreen::isLoading) return;
	LoadingScreen::timeCounter += Constants::DELTA_TIME;
	// add 3 delta time to delay loading to full percent bar
	if (LoadingScreen::timeCounter >= LoadingScreen::timeLoading + 3 * Constants::DELTA_TIME) {
		GM::screenState = nextScreen;
		LoadingScreen::isLoading = false;
		LoadingScreen::timeCounter = 0;
		LoadingScreen::percent = 0;
	}
}

void LoadingScreen::Load(Constants::SCREEN_STATE _nextScreen, double _timeLoading) {
	LoadingScreen::isLoading = true;
	LoadingScreen::nextScreen = _nextScreen;
	LoadingScreen::timeLoading = _timeLoading;
}

