#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cell {
    int x, y;
    int height;
    Cell(int x, int y, int height) : x(x), y(y), height(height) {}
};

bool operator>(const Cell& a, const Cell& b) {
    return a.height < b.height;
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> heights(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> heights[i][j];
        }
    }

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    int initialArea = 0;

    // Add all border cells to the priority queue
    for (int i = 0; i < H; ++i) {
        pq.push(Cell(i, 0, heights[i][0]));
        visited[i][0] = true;
        initialArea++;
    }
    for (int j = 0; j < W; ++j) {
        pq.push(Cell(0, j, heights[0][j]));
        visited[0][j] = true;
        initialArea++;
    }
    for (int i = 0; i < H; ++i) {
        pq.push(Cell(i, W - 1, heights[i][W - 1]));
        visited[i][W - 1] = true;
        initialArea++;
    }
    for (int j = 0; j < W; ++j) {
        pq.push(Cell(H - 1, j, heights[H - 1][j]));
        visited[H - 1][j] = true;
        initialArea++;
    }

    // Process sinking cells for Y years
    for (int year = 1; year <= Y; ++year) {
        int areaThisYear = 0;
        while (!pq.empty()) {
            Cell cell = pq.top();
            pq.pop();
            if (cell.height > year) {
                pq.push(cell); // The cell still hasn't sunk
                break;
            }
            // Mark the cell as sunk
            visited[cell.x][cell.y] = true;
            // Add all adjacent cells to the queue
            if (cell.x > 0 && !visited[cell.x - 1][cell.y]) {
                pq.push(Cell(cell.x - 1, cell.y, heights[cell.x - 1][cell.y]));
                visited[cell.x - 1][cell.y] = true;
            }
            if (cell.x < H - 1 && !visited[cell.x + 1][cell.y]) {
                pq.push(Cell(cell.x + 1, cell.y, heights[cell.x + 1][cell.y]));
                visited[cell.x + 1][cell.y] = true;
            }
            if (cell.y > 0 && !visited[cell.x][cell.y - 1]) {
                pq.push(Cell(cell.x, cell.y - 1, heights[cell.x][cell.y - 1]));
                visited[cell.x][cell.y - 1] = true;
            }
            if (cell.y < W - 1 && !visited[cell.x][cell.y + 1]) {
                pq.push(Cell(cell.x, cell.y + 1, heights[cell.x][cell.y + 1]));
                visited[cell.x][cell.y + 1] = true;
            }
        }
        // Calculate the area of the island that is still above the sea level for this year
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && heights[i][j] > year) {
                    areaThisYear++;
                }
            }
        }
        cout << areaThisYear << "\n";
    }

    return 0;
}