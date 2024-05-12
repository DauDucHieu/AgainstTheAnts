#include "Ant.h"

Ant::~Ant() {}

Ant::Ant(double x, double y) {
	Vector v(x, y);
	this->position = v;
	this->speed = 3;
	this->spriteSrc = "resources/sprites/black.png";
	this->spriteCount = 7;
	this->spriteIndex = 0;
	this->spriteWidth = 140;
	this->spriteHeight = 192;
	this->spriteX = 0;
	this->spriteY = 0;
	this->animTimer = 0;
	this->animDelay = 0.02;
	this->width = 50;
	this->height = 75;
	this->angle = 0;
	this->isActive = true;

	this->hp = 1000;
	this->currentHp = this->hp;

	this->buffSpeed = 0;
	this->buffHp = 0;

	this->isEffected = false;
}

void Ant::Render() {
	Draw::Image(
		this->spriteSrc,
		{
			this->spriteX,
			this->spriteY,
			this->spriteWidth,
			this->spriteHeight
		},
		{
			(int)this->position.GetX(),
			(int)this->position.GetY(),
			this->width,
			this->height
		},
		this->angle,
		{ this->width / 2, this->height / 2 }
	);
	Draw::PercentBar(
		this->position.GetX(), this->position.GetY() - 30,
		60, 1, 1,
		this->currentHp, this->hp,
		{ 255, 255, 255 },
		{ 255, 0, 0 },
		{ 0, 0, 0 }
	);
}

void Ant::Move() {
	Vector moveVector(
		Constants::MOUSE_X - this->position.GetX(),
		Constants::MOUSE_Y - this->position.GetY()
	);

	static double minLength = 1;
	if (moveVector.GetMagnitude() < minLength) return;

	moveVector.ChangeLength(this->speed + this->buffSpeed);
	this->position += moveVector;
	this->MoveAnimation();
	this->LookAt(moveVector);
}

void Ant::MoveAnimation() {
	this->animTimer += Constants::DELTA_TIME;
	if (this->animTimer < this->animDelay) return;
	this->animTimer = 0;
	this->spriteIndex++;
	if (this->spriteIndex >= this->spriteCount) {
		this->spriteIndex = 0;
	}
	this->spriteY = this->spriteHeight * this->spriteIndex;
}

void Ant::LookAt(Vector lookVector) {
	static Vector spriteDirection(0, -1);
	this->angle = lookVector.GetAngleWith(spriteDirection);
	if (lookVector.GetX() < 0) {
		this->angle = -this->angle;
	}
}

void Ant::Update() {
	
}


Vector Ant::GetPosition() { return this->position; }

void Ant::SetBuffSpeed(double buff) {
	this->buffSpeed = buff;
}

void Ant::SetBuffHp(int buff) {
	this->buffHp = buff;
}

void Ant::Effected() {
	this->isEffected = true;
}

void Ant::UnEffected() {
	this->isEffected = false;
}

bool Ant::IsEffected() { return this->isEffected; }

void Ant::DownHp(int hpDown) {
	this->currentHp -= hpDown;
	this->currentHp = this->currentHp > 0 ? this->currentHp : 0;
}

void Ant::Dead() {
	delete this;
}

bool Ant::IsDead() {
	return this->currentHp <= 0;
}

void Ant::Killed() {
	this->currentHp = 0;
}
