#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> island(H, vector<bool>(W, true));
    auto possible_sink = [&](int r, int c) {
        if (r < 0 || r >= H || c < 0 || c >= W) return false;
        return !island[r][c] || (A[r][c] <= A[r][c - 1] && A[r][c - 1] <= A[r][c + 1] &&
                                 A[r][c] <= A[r - 1][c] && A[r - 1][c] <= A[r + 1][c] &&
                                 A[r][c - 1] <= A[r - 1][c - 1] && A[r + 1][c - 1] <= A[r - 1][c + 1] &&
                                 A[r][c + 1] <= A[r + 1][c - 1] && A[r + 1][c + 1] <= A[r - 1][c + 1]);
    };

    int ans = H * W;

    for (int i = 1; i <= Y; i++) {
        queue<pair<int, int>> q;
        for (int r = 0; r < H; r++) {
            for (int c = 0; c < W; c++) {
                if (A[r][c] < i && possible_sink(r, c)) {
                    island[r][c] = false;
                    q.push({r, c});
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                if (possible_sink(nr, nc)) {
                    island[nr][nc] = false;
                    q.push({nr, nc});
                }
            }
        }
        cout << ans - count(island.begin(), island.end(), false) << endl;
    }

    return 0;
}