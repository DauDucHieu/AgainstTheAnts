#include "PathFinder.h"

vector<Cell*> PathFinder::Find(vector<vector<bool>> matrix, int pis, int pjs, int pie, int pje) {
	int is = pis / 100;
	int js = pjs / 100;
	int ie = pie / 100;
	int je = pje / 100;

	int rows = matrix.size();

	if (!rows) return {};
	int cols = matrix[0].size();
	if (!cols) return {};

	if (!matrix[ie][je]) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int x = ie + i;
				int y = je + i;
				if (x < 0 || x >= rows || y < 0 || y >= cols) continue;
				if (matrix[x][y]) {
					ie = x;
					je = y;
				}
			}
		}
	}

	if (ie >= rows) ie = rows - 1;
	if (je >= cols) js = cols - 1;

	vector<vector<Cell*>> cells(rows, vector<Cell*>(cols, nullptr));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cells[i][j] = new Cell(i, j);
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
				if (!next->isVisited && matrix[x][y]) {
					next->isVisited = true;
					next->parent = current;
					queue.push(next);
				}
				if (next == end) break;
			}
		}
	}

	if (!end->isVisited) return {};

	vector<Cell*> path;
	Cell* cell = end;
	while (cell && cell->parent != start) {
		path.push_back(cell);
		cell = cell->parent;
	}

	reverse(path.begin(), path.end());
	return path;
}


