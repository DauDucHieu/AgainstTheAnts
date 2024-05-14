#include "Constants.h"
#include "SDLConstants.h"
#include "GameManager.h"
#include "SDL_ttf.h"
#include "Draw.h"

#include "MenuScreen.h"
#include "StageScreen.h"
#include "LoadingScreen.h"
#include "GameRulesScreen.h"
#include "GameEntitiesScreen.h"
#include "EndScreen.h"

#include "PathFinder.h"

#include <SDL_mixer.h>

void InitSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void Loop() {
	Mix_Music* bgm = Mix_LoadMUS("resources/sounds/bgm.mp3");
	Mix_PlayMusic(bgm, -1);
	SDL_Event e;
	while (!GM::isQuit) {
		SDL_PollEvent(&e);

		switch (e.type) {
			case SDL_QUIT:
				GM::isQuit = true;
				return;
			case SDL_MOUSEMOTION:
				Constants::MOUSE_X = e.motion.x;
				Constants::MOUSE_Y = e.motion.y;
				break;
		}

		switch (GM::screenState) {
			case Constants::SS_MENU:
				MenuScreen::Render();
				MenuScreen::HandleEvent(e);
				MenuScreen::Update();
				break;
			case Constants::SS_STAGE:
				if (!StageScreen::isReset) StageScreen::Reset();
				StageScreen::Render();
				StageScreen::Update();
				StageScreen::HandleEvent(e);
				break;
			case Constants::SS_END:
				EndScreen::Render();
				EndScreen::HandleEvent(e);
				EndScreen::Update();
				break;
			case Constants::SS_LOADING:
				LoadingScreen::Render();
				LoadingScreen::Update();
				break;
			case Constants::SS_GAME_RULES:
				GameRulesScreen::Render();
				GameRulesScreen::HandleEvent(e);
				GameRulesScreen::Update();
				break;
			case Constants::SS_GAME_ENTITIES:
				GameEntitiesScreen::Render();
				GameEntitiesScreen::HandleEvent(e);
				GameEntitiesScreen::Update();
				break;
		}

		SDL_RenderPresent(SDLConstants::renderer);

		SDL_Delay(Constants::DELTA_TIME * 1000);
	}
}

void DestroySDL() {
	SDL_DestroyWindow(SDLConstants::window);
	SDL_DestroyRenderer(SDLConstants::renderer);
	SDL_Quit();
}

int main(int argc, char* argv[]) {

	srand(time(0));
	InitSDL();
	Loop();
	DestroySDL();

	return 0;
}

