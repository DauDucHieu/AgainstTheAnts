#pragma once

#include "NormalAnt.h"
#include "PathFinder.h"

class SmartAnt : public NormalAnt {
protected:
	vector<Vector> path;
	void SmartMove();
	void RandomMove();
	void MoveTo(Vector target);
public:
	SmartAnt(double x, double y);
	void Move() override;
	void UpdatePath(vector<vector<bool>> map, Vector pizzaPosition) override;
};

