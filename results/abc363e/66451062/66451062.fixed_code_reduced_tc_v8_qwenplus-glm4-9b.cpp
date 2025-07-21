#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1001;
int H, W, Y;
int grid[MAXN][MAXN];
vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int visited[MAXN][MAXN];
int area;

bool canSink(int x, int y) {
    // Check if any of the adjacent cells are not visited and have an elevation less than or equal to the sea level
    for (auto dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] <= seaLevel) {
            return true;
        }
    }
    return false;
}

void solve() {
    priority_queue<pair<int, pair<int, int>>> pq; // Pair of elevation, then coordinates
    area = 0;
    seaLevel = 1;

    // Initialize the priority queue with the edges of the grid
    for (int i = 0; i < H; ++i) {
        pq.push({-grid[i][0], {i, 0}});
        pq.push({-grid[i][W-1], {i, W-1}});
        visited[i][0] = visited[i][W-1] = 1;
    }
    for (int j = 0; j < W; ++j) {
        pq.push({-grid[0][j], {0, j}});
        pq.push({-grid[H-1][j], {H-1, j}});
        visited[0][j] = visited[H-1][j] = 1;
    }

    while (!pq.empty() && seaLevel <= Y) {
        while (!pq.empty() && pq.top().first >= -seaLevel) {
            auto t = pq.top();
            pq.pop();
            int x = t.second.first;
            int y = t.second.second;
            if (!visited[x][y]) {
                visited[x][y] = 1;
                area++;
                if (canSink(x, y)) {
                    for (auto dir : directions) {
                        int nx = x + dir.first;
                        int ny = y + dir.second;
                        if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                            pq.push({-grid[nx][ny], {nx, ny}});
                        }
                    }
                }
            }
        }
        seaLevel++;
    }

    cout << area << endl;
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= Y; ++i) {
        solve();
    }

    return 0;
}