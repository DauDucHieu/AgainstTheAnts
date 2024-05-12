#pragma once

#include <SDL.h>
#include "Constants.h"
#include "SDLConstants.h"

class GameManager {
public:

	static bool isQuit;

	static Constants::SCREEN_STATE screenState;

};

typedef GameManager GM;
