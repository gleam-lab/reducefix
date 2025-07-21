#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cell {
    int h, x, y;
    bool operator<(const Cell& other) const {
        return h > other.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
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
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    priority_queue<Cell> pq;

    // Initialize the priority queue with all cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            pq.push({A[i][j], i, j});
            visited[i][j] = true;
        }
    }

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h > year) break;
            pq.pop();

            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= year) {
                    pq.push({A[nx][ny], nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    ++remaining_area;
                }
            }
        }

        cout << remaining_area << '\n';
    }

    return 0;
}