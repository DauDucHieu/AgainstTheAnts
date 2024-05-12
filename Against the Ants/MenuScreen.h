#pragma once

#include <SDL.h>
#include "GameManager.h"
#include "Constants.h"
#include "Draw.h"
#include "Button.h"
#include "LoadingScreen.h"

class MenuScreen {
public:
	static void Render();
	static void HandleEvent(SDL_Event e);
	static void Update();

	static Button* playButton;
	static Button* gameRulesButton;
	static Button* gameEntitiesButton;
};
