#include "GameRulesScreen.h"

Button* GameRulesScreen::backButton = new Button(
	"Back",
	146, 278, 100, 50
);

void GameRulesScreen::Render() {
	Draw::FullImage(
		"resources/sprites/gamerules.png",
		{
			Constants::WINDOW_WIDTH / 2,
			Constants::WINDOW_HEIGHT / 2,
			Constants::WINDOW_WIDTH,
			Constants::WINDOW_HEIGHT
		}
	);
	GameRulesScreen::backButton->Render();
}

void GameRulesScreen::HandleEvent(SDL_Event e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (GameRulesScreen::backButton->IsPointInButton(e.motion.x, e.motion.y)) {
			GM::screenState = Constants::SS_MENU;
		}
	}
}

void GameRulesScreen::Update() {
	if (GameRulesScreen::backButton->IsPointInButton(Constants::MOUSE_X, Constants::MOUSE_Y)) {
		GameRulesScreen::backButton->OnHover();
	}
	else {
		GameRulesScreen::backButton->OffHover();
	}
}