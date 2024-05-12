#pragma once

#include "Constants.h"
#include "Draw.h"
#include "Button.h"
#include "GameManager.h"
#include <string>
using namespace std;

class EndScreen {
private:
	static Button* playAgain;
public:
	static string text;
	static void Render();
	static void HandleEvent(SDL_Event e);
	static void Update();
};

