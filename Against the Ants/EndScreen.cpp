#include "EndScreen.h"

Button* EndScreen::playAgain = new Button(
	"Back to Menu",
	Constants::WINDOW_WIDTH / 2, 350, 300, 80
);

string EndScreen::text = "";

void EndScreen::Render() {

	Draw::FullImage(
		"resources/sprites/endgame.png",
		{
			Constants::WINDOW_WIDTH / 2,
			Constants::WINDOW_HEIGHT / 2,
			Constants::WINDOW_WIDTH,
			Constants::WINDOW_HEIGHT
		}
	);

	Draw::Text(
		EndScreen::text,
		Constants::WINDOW_WIDTH / 2,
		Constants::WINDOW_HEIGHT / 2 - 150,
		50
	);

	EndScreen::playAgain->Render();
}

void EndScreen::HandleEvent(SDL_Event e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (EndScreen::playAgain->IsPointInButton(e.motion.x, e.motion.y)) {
			GM::screenState = Constants::SS_MENU;
		}
	}
}

void EndScreen::Update() {
	if (EndScreen::playAgain->IsPointInButton(Constants::MOUSE_X, Constants::MOUSE_Y)) {
		EndScreen::playAgain->OnHover();
	}
	else {
		EndScreen::playAgain->OffHover();
	}
}