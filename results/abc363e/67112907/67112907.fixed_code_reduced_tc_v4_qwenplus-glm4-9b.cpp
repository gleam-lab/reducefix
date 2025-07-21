#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int H, W, Y;
vector<vector<int>> heights;
vector<vector<bool>> visited;
vector<tuple<int, int, int>> pq; // (height, x, y)

// Add all adjacent cells with lower or equal height to the priority queue
void addNeighbors(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && heights[nx][ny] <= heights[x][y]) {
            visited[nx][ny] = true;
            pq.push_back({heights[nx][ny], nx, ny});
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    heights.resize(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> heights[i][j];
        }
    }
    visited.resize(H, vector<bool>(W, false));
    pq.push_back({heights[0][0], 0, 0});
    visited[0][0] = true;
    addNeighbors(0, 0);
    int remainingArea = H * W;

    for (int year = 0; year < Y; year++) {
        while (!pq.empty()) {
            auto [_, x, y] = pq.top();
            pq.pop();
            remainingArea--;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && heights[nx][ny] <= heights[x][y] + year + 1) {
                    visited[nx][ny] = true;
                    pq.push_back({heights[nx][ny], nx, ny});
                    addNeighbors(nx, ny);
                }
            }
        }
        cout << remainingArea << endl;
    }

    return 0;
}