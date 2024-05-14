#include "TrapBlackHole.h"

TrapBlackHole::TrapBlackHole(double x, double y, double radius) : Trap(x, y, radius) {
	this->spriteSrc = "resources/sprites/black-hole.png";
	this->hp /= 10;
	this->currentHp = this->hp;
}

void TrapBlackHole::EffectToAnt(Ant* ant) {
	ant->Killed();
}
