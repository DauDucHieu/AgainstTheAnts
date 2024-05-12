#pragma once

#include <SDL.h>

class Vector {
private:
	double x, y;
public:
	Vector(double _x = 0, double _y = 0);
	double GetMagnitude();
	void Normalize();
	void ChangeLength(double newLength);
	double GetAngleWith(Vector& v);

	friend Vector& operator+(const Vector& v1, const Vector& v2);
	friend Vector& operator-(const Vector& v1, const Vector& v2);
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);

	double GetX();
	double GetY();
};

