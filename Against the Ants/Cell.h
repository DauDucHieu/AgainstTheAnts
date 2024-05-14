#pragma once
class Cell {
public:
	int i, j;
	bool isVisited;
	Cell* parent;
	Cell(int _i, int _j) : i(_i), j(_j), isVisited(false), parent(nullptr) {}
};
