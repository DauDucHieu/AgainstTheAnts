#pragma once

#include "Trap.h"

class TrapBlackHole : public Trap {
public:
	TrapBlackHole(double x, double y, double radius);
	void EffectToAnt(Ant* ant) override;
};

