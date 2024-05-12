#include "PathFinder.h"

vector<Cell> PathFinder::Find(vector<vector<bool>> matrix, Cell start, Cell end) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    
    vector<Cell> path;
    vector<vector<bool>> visited(nRows, vector<bool>(nCols, false));
    vector<vector<Cell>> parent(nRows, vector<Cell>(nCols, Cell(-1, -1)));
    stack<Cell> stack;

    stack.push(start);

    while (!stack.empty()) {
        Cell current = stack.top();
        stack.pop();

        visited[current.i][current.j] = true;

        if (current.i == end.i && current.j == end.j) {
            while (!(current.i == start.i && current.j == start.j)) {
                path.push_back(current);
                current = parent[current.i][current.j];
            }
            path.push_back(start);
            reverse(path.begin(), path.end()); // Đảo ngược path để có đường đi từ start đến end
            return path;
        }

        // Duyệt qua các ô kề của ô hiện tại
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                // Loại bỏ trường hợp đi ngang hoặc đi dọc
                if (dx != 0 && dy != 0) continue;

                int ni = current.i + dx;
                int nj = current.j + dy;

                // Kiểm tra ô kề có hợp lệ không
                if (ni >= 0 && ni < nRows && nj >= 0 && nj < nCols && !visited[ni][nj] && matrix[ni][nj]) {
                    stack.push(Cell(ni, nj));
                    parent[ni][nj] = current; // Cập nhật ô cha của ô kề
                }
            }
        }
    }

    // Trường hợp không tìm thấy đường đi từ start đến end
    return path;
}
