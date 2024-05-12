#include "Draw.h"

vector<SDL_Texture*> Draw::loadedTexture;
unordered_map<string, int> Draw::loadedSrc;
TTF_Font* Draw::mainFont = nullptr;

vector<SDL_Texture*> Draw::loadedTextTexture;
vector<string> Draw::loadedText;
vector<int> Draw::loadedFontSize;

SDL_Texture* Draw::GetTextTexture(string text, int fontSize) {
	for (int i = 0; i < Draw::loadedText.size(); i++) {
		if (text == Draw::loadedText[i] && fontSize == Draw::loadedFontSize[i]) {
			return Draw::loadedTextTexture[i];
		}
	}

	TTF_Font* font = TTF_OpenFont("resources/fonts/makingmove.ttf", fontSize);
	SDL_Surface * surface = TTF_RenderUTF8_Solid(font, text.c_str(), {0, 0, 0});
	SDL_Texture* texture = SDL_CreateTextureFromSurface(SDLConstants::renderer, surface);
	SDL_FreeSurface(surface);

	Draw::loadedFontSize.push_back(fontSize);
	Draw::loadedText.push_back(text);
	Draw::loadedTextTexture.push_back(texture);
	return texture;
}

SDL_Texture* Draw::GetTexture(string src) {

	// ignore Draw::loadedTexture[0]
	if (Draw::loadedTexture.size() <= 0) {
		loadedTexture.push_back(nullptr);
	}

	if (Draw::loadedSrc[src] != 0) {
		return Draw::loadedTexture[loadedSrc[src]];
	}

	cout << "Load image at src: " << src << endl;

	SDL_Surface* surface = IMG_Load(src.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(SDLConstants::renderer, surface);
	SDL_FreeSurface(surface);
	Draw::loadedSrc[src] = Draw::loadedTexture.size();
	Draw::loadedTexture.push_back(texture);

	return texture;
}

void Draw::Image(
	string src,
	SDL_Rect srcRect,
	SDL_Rect dsRect,
	double angle,
	SDL_Point center
) {

	dsRect.x = dsRect.x - dsRect.w / 2;
	dsRect.y = dsRect.y - dsRect.h / 2;

	SDL_RenderCopyEx(
		SDLConstants::renderer,
		Draw::GetTexture(src),
		&srcRect,
		&dsRect,
		angle,
		&center,
		SDL_FLIP_NONE
	);
}

void Draw::FullImage(
	string src,
	SDL_Rect dsRect,
	double angle,
	SDL_Point center
) {
	int w, h;
	SDL_Texture* texture = Draw::GetTexture(src);
	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
	SDL_Rect srcRect = { 0, 0, w, h };

	dsRect.x = dsRect.x - dsRect.w / 2;
	dsRect.y = dsRect.y - dsRect.h / 2;

	SDL_RenderCopyEx(
		SDLConstants::renderer,
		texture,
		&srcRect,
		&dsRect,
		angle,
		&center,
		SDL_FLIP_NONE
	);
}

void Draw::Rect(
	SDL_Rect rect,
	SDL_Color c
) {
	//SDL_SetRenderDrawBlendMode(SDLConstants::renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(SDLConstants::renderer, c.r, c.g, c.b, c.a);
	SDL_RenderFillRect(SDLConstants::renderer, &rect);
}

void Draw::Text(
	string text,
	int x, int y,
	int fontSize,
	SDL_Color c
) {
	SDL_Texture* texture = Draw::GetTextTexture(text, fontSize);
	int w, h;
	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
	SDL_Rect dsRect = { x - w/2, y - h/2, w, h };
	SDL_RenderCopy(SDLConstants::renderer, texture, nullptr, &dsRect);
}


void Draw::PercentBar(
	int x, int y,
	int width, int height,
	int borderWidth,
	double currentValue, double maxValue,
	SDL_Color bgColor,
	SDL_Color activeColor,
	SDL_Color borderColor,
	bool isHorizontal
) {
	Rect(
		{
			x - width / 2 - borderWidth,
			y - height / 2 - borderWidth,
			width + 2 * borderWidth,
			height + 2 * borderWidth
		},
		borderColor
	);

	Rect(
		{
			x - width / 2,
			y - height / 2,
			width,
			height
		},
		bgColor
	);

	if (isHorizontal) {
		int percentBarWidth = width * currentValue / maxValue;
		Rect(
			{
				x - width / 2,
				y - height / 2,
				percentBarWidth, height
			},
			activeColor
		);
	}
	else {
		int percentBarHeight = height * currentValue / maxValue;
		Rect(
			{
				x - width / 2,
				y + height / 2 - percentBarHeight,
				width, percentBarHeight
			},
			activeColor
		);
	}
}

