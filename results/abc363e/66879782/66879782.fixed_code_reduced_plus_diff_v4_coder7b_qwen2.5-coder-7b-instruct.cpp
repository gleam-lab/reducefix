#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int h, w, y;
int height[MAXN][MAXN];
bool visited[MAXN][MAXN];

struct Cell {
    int x, y, h;
    bool operator<(const Cell& other) const {
        return h > other.h;
    }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int sx, int sy, int targetHeight) {
    priority_queue<Cell> pq;
    pq.push({sx, sy, height[sx][sy]});
    visited[sx][sy] = true;

    while (!pq.empty()) {
        auto [cx, cy, ch] = pq.top(); pq.pop();

        if (ch <= targetHeight) continue;

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (visited[nx][ny] || height[nx][ny] <= targetHeight) continue;
            visited[nx][ny] = true;
            pq.push({nx, ny, height[nx][ny]});
        }
    }
}

int countRemainingArea(int targetHeight) {
    fill_n(reinterpret_cast<bool*>(visited), h * w, false);
    bfs(0, 0, targetHeight);

    int remainingArea = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && height[i][j] > targetHeight) {
                ++remainingArea;
            }
        }
    }
    return remainingArea;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    vector<int> results;
    for (int i = 0; i < y; ++i) {
        results.push_back(countRemainingArea(i));
    }

    for (int res : results) {
        cout << h * w - res << '\n';
    }

    return 0;
}