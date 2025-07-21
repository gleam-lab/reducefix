#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX_H = 1000, MAX_W = 1000, MAX_Y = 100000;

int H, W, Y;
int A[MAX_H][MAX_W];

vector<vector<ll>> seaLevel(MAX_H * MAX_W + 1);
vector<vector<bool>> visited(MAX_H, vector<bool>(MAX_W, false));

void bfs(int h, int w) {
    queue<P> q;
    q.push({h, w});
    visited[h][w] = true;
    ll sea = A[h][w];
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        for (auto [dy, dx] : dir) {
            int ny = y + dy, nx = x + dx;
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
                sea = min(sea, A[y][x]);
                continue;
            }
            if (visited[ny][nx]) continue;
            if (A[ny][nx] <= sea) {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
    for (auto [dy, dx] : dir) {
        int ny = h + dy, nx = w + dx;
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
        seaLevel[A[ny][nx]].push_back(sea);
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    ll total = H * W;
    for (int year = 1; year <= Y; ++year) {
        ll area = total;
        for (auto &lev : seaLevel[year]) {
            area -= lev;
        }
        cout << area << endl;
        seaLevel[year + 1].clear();
    }

    return 0;
}