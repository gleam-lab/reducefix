#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Cell {
    int height, x, y;
    bool operator<(const Cell& other) const {
        return height > other.height; // Min-heap based on height
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Cell> pq;

    // Initialize the priority queue with all boundary cells
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) pq.emplace(A[i][0], i, 0), visited[i][0] = true;
        if (!visited[i][W - 1]) pq.emplace(A[i][W - 1], i, W - 1), visited[i][W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        if (!visited[0][j]) pq.emplace(A[0][j], 0, j), visited[0][j] = true;
        if (!visited[H - 1][j]) pq.emplace(A[H - 1][j], H - 1, j), visited[H - 1][j] = true;
    }

    int totalArea = H * W;
    while (Y--) {
        int seaLevel = pq.top().height;
        while (!pq.empty() && pq.top().height <= seaLevel) {
            auto [height, x, y] = pq.top();
            pq.pop();
            --totalArea;
            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= seaLevel) {
                    pq.emplace(A[nx][ny], nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
        cout << totalArea << '\n';
    }

    return 0;
}