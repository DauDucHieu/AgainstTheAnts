#pragma once

#include "Constants.h"
#include "Vector.h"
#include "Draw.h"
#include "Ant.h"
#include <string>
using namespace std;

class Trap {
protected:
	Vector position;
	double radius;
	string spriteSrc;
	bool isActive;

	int hp;
	int currentHp;

public:
	Trap(double x, double y, double _radius);
	void Render();
	virtual void EffectToAnt(Ant* ant);
	Vector GetPosition();

	void DownHp(int hpDown);

	void Dead();

	bool IsDead();
};

