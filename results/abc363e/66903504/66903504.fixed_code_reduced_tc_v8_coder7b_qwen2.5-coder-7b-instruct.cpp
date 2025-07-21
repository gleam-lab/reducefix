#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

void bfs(int x, int y, int h) {
    pq.push({grid[x][y], {x, y}});
    visited[x][y] = true;
    while (!pq.empty()) {
        auto [height, pos] = pq.top(); pq.pop();
        int cx = pos.first, cy = pos.second;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) == 1) {
                    int nx = cx + dx, ny = cy + dy;
                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !visited[nx][ny] && grid[nx][ny] <= height && grid[nx][ny] <= h) {
                        pq.push({grid[nx][ny], {nx, ny}});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    grid.resize(H, vector<int>(W));
    visited.resize(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int y = 0; y <= Y; ++y) {
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && grid[i][j] <= y) {
                    bfs(i, j, y);
                }
            }
        }
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (visited[i][j]) {
                    count++;
                    visited[i][j] = false;
                }
            }
        }
        cout << H * W - count << endl;
    }

    return 0;
}