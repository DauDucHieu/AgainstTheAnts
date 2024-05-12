#include "TrapBlackHole.h"

TrapBlackHole::TrapBlackHole(double x, double y, double radius) : Trap(x, y, radius) {
	this->spriteSrc = "resources/sprites/black-hole.png";
}

void TrapBlackHole::EffectToAnt(Ant* ant) {
	ant->Killed();
}
