#include "Vector.h"

Vector::Vector(double _x, double _y) : x(_x), y(_y) {}

double Vector::GetMagnitude() {
	return SDL_sqrt(x * x + y * y);
}

void Vector::Normalize() {
	double magnitude = GetMagnitude();
	if (magnitude <= 0) return;
	x /= magnitude;
	y /= magnitude;
}

void Vector::ChangeLength(double newLength) {
	Normalize();
	x *= newLength;
	y *= newLength;
}

double Vector::GetAngleWith(Vector& v) {
	double productDot = x * v.x + y * v.y;
	double cos = productDot / (GetMagnitude() * v.GetMagnitude());
	double angle = SDL_acos(cos) * 180 / 3.1415926;
	return angle;
}

Vector& operator+(const Vector& v1, const Vector& v2) {
	Vector v3(v1.x + v2.x, v1.y + v2.y);
	return v3;
}

Vector& operator-(const Vector& v1, const Vector& v2) {
	Vector v3(v1.x - v2.x, v1.y - v2.y);
	return v3;
}

Vector& Vector::operator+=(const Vector& v) {
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vector& Vector::operator-=(const Vector& v) {
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}


double Vector::GetX() { return this->x; }
double Vector::GetY() { return this->y; }
