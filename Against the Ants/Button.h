#pragma once

#include <SDL.h>
#include <string>
#include "Draw.h"
#include <iostream>
using namespace std;

class Button {
private:
	int x, y;
	int w, h;
	string text;
	int textSize = 30;
	int borderWidth = 2;
	SDL_Color borderColor = { 70, 255, 100 };
	SDL_Color borderColorOnHover = { 255, 75, 50 };
	SDL_Color bgColor = { 255, 255, 255 };
	SDL_Color renderBorderColor = borderColor;
	double hoverScale = 1.1;
	bool isHover = false;
public:
	Button(string _text, int _x, int _y, int _w, int _h);
	void Render();
	bool IsPointInButton(int cx, int cy);
	void OnHover();
	void OffHover();
};

