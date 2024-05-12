#include "Button.h"

Button::Button(string _text, int _x, int _y, int _w, int _h)
	: text(_text), x(_x), y(_y), w(_w), h(_h) {}

void Button::Render() {
	Draw::Rect(
		{ 
			x - w/2 - borderWidth, 
			y - h/2 - borderWidth, 
			w + borderWidth * 2, 
			h + borderWidth * 2
		}, 
		renderBorderColor
	);
	Draw::Rect({ x - w / 2, y - h / 2, w, h }, bgColor);
	Draw::Text(text, x, y, textSize);
}

bool Button::IsPointInButton(int cx, int cy) {
	if (cx < x - w / 2) return false;
	if (cx > x + w / 2) return false;
	if (cy < y - h / 2) return false;
	if (cy > y + h / 2) return false;
	return true;
}

void Button::OnHover() {
	if (!isHover) {
		isHover = true;
		w *= hoverScale;
		h *= hoverScale;
		textSize *= hoverScale;
		renderBorderColor = borderColorOnHover;
	}
}

void Button::OffHover() {
	if (isHover) {
		isHover = false;
		w /= hoverScale;
		h /= hoverScale;
		textSize /= hoverScale;
		renderBorderColor = borderColor;
	}
}
