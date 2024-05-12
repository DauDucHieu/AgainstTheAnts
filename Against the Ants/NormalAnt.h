#pragma once

#include "Ant.h"
#include "Random.h"

class NormalAnt : public Ant {
protected:
	Vector moveVector;
	
	double delayMin;
	double delayMax;

	double moveRandomDelay;
	double moveRandomTimer;

	void UpdateMoveVector();
	void RandomMoveVector();

public:
	NormalAnt(double x, double y);
	void Move() override;
	void Update() override;
	void SetBuffSpeed(double buff) override;
};

