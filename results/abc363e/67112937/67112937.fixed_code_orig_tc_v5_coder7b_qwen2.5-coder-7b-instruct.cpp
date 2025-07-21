#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int h, w, y;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

struct Node {
    int x, y, h;
    bool operator<(const Node& other) const {
        return h > other.h;
    }
};

void bfs(int level) {
    priority_queue<Node> pq;
    for (int i = 0; i < h; ++i) {
        if (grid[i][0] <= level) pq.emplace(i, 0, grid[i][0]);
        if (grid[i][w-1] <= level) pq.emplace(i, w-1, grid[i][w-1]);
    }
    for (int j = 1; j < w-1; ++j) {
        if (grid[0][j] <= level) pq.emplace(0, j, grid[0][j]);
        if (grid[h-1][j] <= level) pq.emplace(h-1, j, grid[h-1][j]);
    }

    while (!pq.empty()) {
        auto [x, y, h] = pq.top();
        pq.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= level) {
                pq.emplace(nx, ny, grid[nx][ny]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<int> areas(y);
    areas[0] = h * w;
    for (int i = 1; i < y; ++i) {
        memset(visited, false, sizeof(visited));
        bfs(i);
        int count = 0;
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                if (!visited[j][k]) ++count;
            }
        }
        areas[i] = count;
    }

    for (int i = 0; i < y; ++i) cout << areas[i] << '\n';

    return 0;
}