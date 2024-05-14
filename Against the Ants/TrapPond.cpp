#include "TrapPond.h"

TrapPond::TrapPond(double x, double y, double radius) : Trap::Trap(x, y, radius) {

}

void TrapPond::EffectToAnt(Ant* ant) {
	ant->SetBuffSpeed(-3);
	ant->Effected();
}

