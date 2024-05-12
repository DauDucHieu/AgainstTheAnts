#pragma once

#include "Trap.h"

class TrapPond : public Trap {
public:
	TrapPond(double x, double y, double radius);
	void EffectToAnt(Ant* ant) override;

};

