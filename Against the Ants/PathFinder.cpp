#include "PathFinder.h"

vector<Cell*> PathFinder::Find(vector<vector<bool>> matrix, int is, int js, int ie, int je) {

	vector<vector<Cell*>> cells;
	int rows = matrix.size();
	int cols = matrix[0].size();

	for (int i = 0; i < rows; i++) {
		cells.push_back({});
	}

	for (int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			cells[i].push_back(new Cell(i, j));
		}
	}

	queue<Cell*> queue;

	Cell* start = cells[is][js];
	Cell* end = cells[ie][je];

	queue.push(start);
	start->isVisited = true;

	while (!queue.empty()) {
		Cell* current = queue.front();
		queue.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int x = current->i + i;
				int y = current->j + j;
				if (x < 0 || x >= rows || y < 0 || y >= cols) continue;
				Cell* next = cells[x][y];
				if (!next->isVisited) {
					next->isVisited = true;
					next->parent = current;
					queue.push(next);
				}
				if (next == end) break;
			}
		}
	}

	vector<Cell*> path;
	Cell* cell = end;
	while (cell->parent != start) {
		path.push_back(cell);
		cell = cell->parent;
	}

	reverse(path.begin(), path.end());
	return path;
}


