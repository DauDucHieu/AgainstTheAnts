#pragma once

#include "Constants.h"
#include "Draw.h"
#include "Button.h"
#include "GameManager.h"

class GameEntitiesScreen {
private:
	static Button* backButton;
public:
	static void Render();
	static void HandleEvent(SDL_Event e);
	static void Update();
};

