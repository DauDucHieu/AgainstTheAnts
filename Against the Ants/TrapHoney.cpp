#include "TrapHoney.h"

TrapHoney::TrapHoney(double x, double y, double radius) : Trap(x, y, radius) {
	this->spriteSrc = "resources/sprites/honey.png";
}

void TrapHoney::EffectToAnt(Ant* ant) {
	cout << "Honeyeeeeeeeeeeee\n";
	ant->SetBuffHp(20);
	ant->Effected();
}
