#pragma once

#include "Constants.h"
#include "SDLConstants.h"
#include "GameManager.h"

#include "Draw.h"

class LoadingScreen {
private:
	static double timeCounter;
	static double timeLoading;
	static Constants::SCREEN_STATE nextScreen;
	static bool isLoading;
	static double percent;
public:
	static void Render();
	static void Update();
	static void Load(Constants::SCREEN_STATE, double _timeLoading = 1);
};

