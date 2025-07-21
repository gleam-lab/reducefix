#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Cell {
    int h, x, y;
    bool operator<(const Cell& other) const {
        return h > other.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<Cell> pq;
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        pq.emplace(A[i][W-1], i, W-1);
        vis[i][0] = vis[i][W-1] = true;
    }
    for (int j = 1; j < W-1; ++j) {
        pq.emplace(A[0][j], 0, j);
        pq.emplace(A[H-1][j], H-1, j);
        vis[0][j] = vis[H-1][j] = true;
    }

    int ans = H * W;
    while (!pq.empty()) {
        auto [h, x, y] = pq.top(); pq.pop();
        if (h > Y) break;
        --ans;
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            pq.emplace(A[nx][ny], nx, ny);
        }
    }
    cout << ans << '\n';

    return 0;
}