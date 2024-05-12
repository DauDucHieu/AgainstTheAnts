#pragma once


#include <vector>
#include <stack>
using namespace std;


struct Cell {
	int i, j;
	Cell(int _i, int _j) : i(_i), j(_j) {}
};


class PathFinder {
public:
	static vector<Cell> Find(vector<vector<bool>> matrix, Cell start, Cell end);
};

