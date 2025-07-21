#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cell {
    int x, y, height;
};

bool operator<(const Cell& a, const Cell& b) {
    return a.height < b.height;
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<Cell, vector<Cell>, less<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the queue with cells on the border of the island
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) pq.push({i, 0, A[i][0]});
        if (!visited[i][W - 1]) pq.push({i, W - 1, A[i][W - 1]});
    }
    for (int j = 0; j < W; ++j) {
        if (!visited[0][j]) pq.push({0, j, A[0][j]});
        if (!visited[H - 1][j]) pq.push({H - 1, j, A[H - 1][j]});
    }

    while (!pq.empty()) {
        Cell top = pq.top();
        pq.pop();

        // If the cell is already visited or if its height is less than or equal to the current sea level, skip it
        if (visited[top.x][top.y] || top.height <= Y) continue;

        visited[top.x][top.y] = true;

        // Propagate the flooding to adjacent cells
        if (top.x > 0 && !visited[top.x - 1][top.y]) {
            pq.push({top.x - 1, top.y, A[top.x - 1][top.y]});
        }
        if (top.x < H - 1 && !visited[top.x + 1][top.y]) {
            pq.push({top.x + 1, top.y, A[top.x + 1][top.y]});
        }
        if (top.y > 0 && !visited[top.x][top.y - 1]) {
            pq.push({top.x, top.y - 1, A[top.x][top.y - 1]});
        }
        if (top.y < W - 1 && !visited[top.x][top.y + 1]) {
            pq.push({top.x, top.y + 1, A[top.x][top.y + 1]});
        }
    }

    // Output the area of the island above the sea level
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                remaining_area++;
            }
        }
    }
    cout << remaining_area << endl;

    return 0;
}