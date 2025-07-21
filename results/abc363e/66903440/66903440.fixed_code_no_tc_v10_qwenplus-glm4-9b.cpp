#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const intMAXN = 1000, MAXY = 100000, MAXH = MAXN, MAXW = MAXN;

int H, W, Y;
int field[MAXN][MAXN];
bool flooded[MAXH][MAXW];
queue<pair<int, int>> Q;
vector<vector<pair<int, int>>> adj(MAXY + 1);

void enqueue(int y, int x, int y') {
    if (field[y][x] < y') {
        flooded[y][x] = true;
        adj[y'].push_back({y, x});
    }
}

void enqueue_and_explore(int y, int x, int y') {
    enqueue(y, x, y');
    for (int d = 0; d < 4; ++d) {
        int ny = y + dx[d], nx = x + dy[d];
        if (ny >= 0 && ny < H && nx >= 0 && nx < W && !flooded[ny][nx]) {
            enqueue(ny, nx, y');
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> field[i][j];
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && !flooded[i][j]) {
                flooded[i][j] = true;
                enqueue(i, j, field[i][j]);
            }
        }
    }

    for (int y = 1; y <= Y; ++y) {
        int area = H * W;
        while (!adj[y].empty()) {
            auto [i, j] = adj[y].front();
            adj[y].pop();
            area--;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    if (!flooded[ni][nj]) {
                        flooded[ni][nj] = true;
                        adj[field[ni][nj]].push_back({ni, nj});
                    }
                }
            }
        }
        cout << area << endl;
    }

    return 0;
}