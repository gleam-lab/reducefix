#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned int;
using i32 = int;
using u64 = unsigned long long;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Point {
    int h, x, y;
    bool operator>(const Point &other) const {
        return h < other.h; // Min-heap based on height
    }
};

int main() {
    i32 H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<i32>> A(H, vector<i32>(W));
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    for (i32 i = 0; i < H; i++) {
        for (i32 j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Priority queue to manage the points that can sink
    priority_queue<Point> pq;
    for (i32 i = 0; i < W; i++) pq.push({A[0][i], 0, i});
    for (i32 i = 1; i < H; i++) pq.push({A[i][0], i, 0});
    for (i32 i = 0; i < H; i++) pq.push({A[i][W - 1], i, W - 1});
    for (i32 i = 1; i < W; i++) pq.push({A[H - 1][i], H - 1, i});

    i32 ans = H * W;
    while (Y--) {
        i32 sink = 0;
        while (!pq.empty()) {
            Point p = pq.top();
            pq.pop();
            if (p.h > Y) break;
            if (vis[p.x][p.y]) continue;
            vis[p.x][p.y] = true;
            ans--;

            for (const auto &dir : d) {
                i32 nx = p.x + dir[0], ny = p.y + dir[1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || vis[nx][ny]) continue;
                if (A[nx][ny] <= Y) {
                    pq.push({A[nx][ny], nx, ny});
                    vis[nx][ny] = true;
                    sink++;
                }
            }
        }
        cout << ans + sink << '\n';
    }

    return 0;
}