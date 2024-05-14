#include "MenuScreen.h"

Button* MenuScreen::playButton = new Button(
	"Play", 250, 250, 250, 75
);

Button* MenuScreen::gameRulesButton = new Button(
	"Game Rules", 250, 350, 250, 75
);

Button* MenuScreen::gameEntitiesButton = new Button(
	"Entities", 250, 450, 250, 75
);


void MenuScreen::Render() {
	Draw::FullImage(
		"resources/sprites/menu.jpg",
		{ Constants::WINDOW_WIDTH / 2, Constants::WINDOW_HEIGHT / 2, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT }
	);
	MenuScreen::playButton->Render();
	MenuScreen::gameRulesButton->Render();
	MenuScreen::gameEntitiesButton->Render();
}

void MenuScreen::HandleEvent(SDL_Event e) {
	switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (MenuScreen::playButton->IsPointInButton(e.motion.x, e.motion.y)) {
				GM::screenState = Constants::SS_LOADING;
				LoadingScreen::Load(Constants::SS_STAGE);
			}
			if (MenuScreen::gameRulesButton->IsPointInButton(e.motion.x, e.motion.y)) {
				GM::screenState = Constants::SS_GAME_RULES;
			}
			if (MenuScreen::gameEntitiesButton->IsPointInButton(e.motion.x, e.motion.y)) {
				GM::screenState = Constants::SS_GAME_ENTITIES;
			}
	}
}

void MenuScreen::Update() {
	if (MenuScreen::playButton->IsPointInButton(Constants::MOUSE_X, Constants::MOUSE_Y)) {
		MenuScreen::playButton->OnHover();
	}
	else {
		MenuScreen::playButton->OffHover();
	}

	if (MenuScreen::gameRulesButton->IsPointInButton(Constants::MOUSE_X, Constants::MOUSE_Y)) {
		MenuScreen::gameRulesButton->OnHover();
	}
	else {
		MenuScreen::gameRulesButton->OffHover();
	}

	if (MenuScreen::gameEntitiesButton->IsPointInButton(Constants::MOUSE_X, Constants::MOUSE_Y)) {
		MenuScreen::gameEntitiesButton->OnHover();
	}
	else {
		MenuScreen::gameEntitiesButton->OffHover();
	}
}
