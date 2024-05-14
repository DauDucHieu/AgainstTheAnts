#pragma once

#include <vector>
#include <queue>
using namespace std;

class PathFinder {
public:
	static struct Cell {
		int i, j;
		bool isVisited;
		Cell* parent;
		Cell(int _i, int _j) : i(_i), j(_j), isVisited(false), parent(nullptr) {}
	};
	static vector<Cell*> Find(vector<vector<bool>> matrix, int is, int js, int ie, int je);
};

typedef PathFinder::Cell Cell;

