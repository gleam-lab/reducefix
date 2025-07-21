#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

typedef long long ll;
const int MAX_H = 1000, MAX_W = 1000, MAX_Y = 100000;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    auto bfs = [&](int level) {
        while (!q.empty()) q.pop();
        int remaining_area = H * W;
        for (int i = 0; i < H; ++i) {
            if (A[i][0] > level) q.emplace(i, 0), visited[i][0] = true;
            if (A[i][W-1] > level) q.emplace(i, W-1), visited[i][W-1] = true;
        }
        for (int j = 0; j < W; ++j) {
            if (A[0][j] > level) q.emplace(0, j), visited[0][j] = true;
            if (A[H-1][j] > level) q.emplace(H-1, j), visited[H-1][j] = true;
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            --remaining_area;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] <= level && !visited[nx][ny]) {
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
        return remaining_area;
    };

    for (int level = 1; level <= Y; ++level) {
        cout << bfs(level) << endl;
    }

    return 0;
}