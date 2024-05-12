#include "SDLConstants.h"

SDL_Window* SDLConstants::window = SDL_CreateWindow(
	Constants::WINDOW_TITLE.c_str(),
	SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED,
	Constants::WINDOW_WIDTH,
	Constants::WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
);

SDL_Renderer* SDLConstants::renderer = SDL_CreateRenderer(
	SDLConstants::window, -1, 0
);
