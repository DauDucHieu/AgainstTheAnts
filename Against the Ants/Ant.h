#pragma once

#include "SDLConstants.h"
#include "Constants.h"
#include "Vector.h"
#include "Draw.h"

#include <string>
using namespace std;

class Ant {
protected:
	Vector position;
	double speed;

	string spriteSrc;
	int spriteCount;
	int spriteIndex;
	int spriteWidth;
	int spriteHeight;
	int spriteX;
	int spriteY;
	double animTimer;
	double animDelay;

	int width;
	int height;
	double angle;
	bool isActive;

	int hp;
	int currentHp;

	double buffSpeed;
	int buffHp;

	bool isEffected;

	bool IsOutOfMap() {
		if (this->position.GetX() < 10) return true;
		if (this->position.GetX() > Constants::WINDOW_WIDTH) return true;
		if (this->position.GetY() < 10) return true;
		if (this->position.GetY() > Constants::WINDOW_HEIGHT) return true;
		return false;
	}

public:
	virtual ~Ant();
	Ant(double x = 0, double y = 0);
	virtual void Render();
	virtual void Update();
	virtual void Move();
	virtual void MoveAnimation();
	virtual void LookAt(Vector lookVector);
	virtual void UpdatePath(vector<vector<bool>> map, Vector pizzaPosition);

	Vector GetPosition();

	virtual void SetBuffSpeed(double buff);
	virtual void SetBuffHp(int buff);
	
	void Effected();
	void UnEffected();
	bool IsEffected();

	void DownHp(int hpDown);

	void Dead();

	bool IsDead();

	void Killed();
};

