#include "Trap.h"

Trap::Trap(double x, double y, double _radius) {
	Vector pos(x, y);
	this->position = pos;
	this->radius = _radius;
	this->spriteSrc = "resources/sprites/pond.png";
	this->isActive = true;
	this->hp = 2000;
	this->currentHp = this->hp;
}

void Trap::Render() {
	Draw::FullImage(
		this->spriteSrc.c_str(),
		{
			(int)(this->position.GetX()),
			(int)(this->position.GetY()),
			(int)(this->radius * 2),
			(int)(this->radius * 2)
		}
	);
	Draw::PercentBar(
		(int)(this->position.GetX()),
		(int)(this->position.GetY() + 50),
		90, 2, 1,
		this->currentHp, this->hp,
		{ 255, 255, 255 },
		{ 50, 100, 255 },
		{ 0, 0, 0 }
	);
}

void Trap::EffectToAnt(Ant* ant) {
	ant->SetBuffSpeed(-1.9);
	ant->Effected();
}

Vector Trap::GetPosition() { return this->position; }

void Trap::DownHp(int hpDown) {
	this->currentHp -= hpDown;
	this->currentHp = this->currentHp > 0 ? this->currentHp : 0;
}

void Trap::Dead() {
	delete this;
}

bool Trap::IsDead() {
	return this->currentHp <= 0;
}
