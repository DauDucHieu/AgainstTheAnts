#pragma once

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

#include "SDLConstants.h"

class Draw {
public:
	static vector<SDL_Texture*> loadedTexture;
	static unordered_map<string, int> loadedSrc;
	static TTF_Font* mainFont;

	static vector<SDL_Texture*> loadedTextTexture;
	static vector<string> loadedText;
	static vector<int> loadedFontSize;

	static SDL_Texture* GetTexture(string src);
	static void Image(
		string src,
		SDL_Rect srcRect,
		SDL_Rect dsRect,
		double angle = 0,
		SDL_Point center = { 0, 0 }
	);

	static SDL_Texture* GetTextTexture(string  text, int fontSize);

	static void FullImage(
		string src,
		SDL_Rect dsRect,
		double angle = 0,
		SDL_Point center = { 0, 0 }
	);

	static void Rect(
		SDL_Rect rect, 
		SDL_Color c
	);

	static void Text(
		string text, 
		int x, int y, 
		int fontSize,
		SDL_Color c = { 0, 0, 0 }
	);

	static void PercentBar(
		int x, int y,
		int width, int height,
		int borderWidth,
		double currentValue, double maxValue,
		SDL_Color bgColor,
		SDL_Color activeColor,
		SDL_Color borderColor,
		bool isHorizontal = true
	);

};
