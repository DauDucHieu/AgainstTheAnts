#pragma once

#include "Cell.h"
#include <vector>
#include <queue>
using namespace std;

class PathFinder {
public:
	static vector<Cell*> Find(vector<vector<bool>> matrix, int is, int js, int ie, int je);
};


