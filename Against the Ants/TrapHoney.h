#pragma once

#include "Trap.h"

class TrapHoney : public Trap {
public:
	TrapHoney(double x, double y, double radius);
	void EffectToAnt(Ant* ant) override;
};

