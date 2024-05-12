#include "GameEntitiesScreen.h"

Button* GameEntitiesScreen::backButton = new Button(
	"Back",
	130, 550, 120, 50
);

void GameEntitiesScreen::Render() {
	Draw::FullImage(
		"resources/sprites/gameentities.png",
		{
			Constants::WINDOW_WIDTH / 2,
			Constants::WINDOW_HEIGHT / 2,
			Constants::WINDOW_WIDTH,
			Constants::WINDOW_HEIGHT
		}
	);
	GameEntitiesScreen::backButton->Render();
}

void GameEntitiesScreen::HandleEvent(SDL_Event e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (GameEntitiesScreen::backButton->IsPointInButton(e.motion.x, e.motion.y)) {
			GM::screenState = Constants::SS_MENU;
		}
	}
}

void GameEntitiesScreen::Update() {
	if (GameEntitiesScreen::backButton->IsPointInButton(Constants::MOUSE_X, Constants::MOUSE_Y)) {
		GameEntitiesScreen::backButton->OnHover();
	}
	else {
		GameEntitiesScreen::backButton->OffHover();
	}
}
