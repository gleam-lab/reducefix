#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Edge {
    int h, x, y;
    bool operator<(const Edge& other) const {
        return h > other.h;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<Edge> pq;
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        pq.emplace(A[i][W-1], i, W-1);
    }
    for (int j = 1; j < W-1; ++j) {
        pq.emplace(A[0][j], 0, j);
        pq.emplace(A[H-1][j], H-1, j);
    }

    int ans = H * W;
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        --ans;

        for (int k = 0; k < 4; ++k) {
            int dx = x + d[k][0], dy = y + d[k][1];
            if (dx >= 0 && dx < H && dy >= 0 && dy < W && !vis[dx][dy]) {
                pq.emplace(A[dx][dy], dx, dy);
            }
        }

        if (ans == 0) break;
    }

    for (int i = 0; i < Y; ++i) {
        cout << ans << '\n';
    }

    return 0;
}