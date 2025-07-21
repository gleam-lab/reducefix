#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Add all border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    vector<int> ans(Y);

    for (int y =1; y <= Y; ++y) {
        while (!pq.empty() && get<0>(pq.top()) <= y) {
            auto [h, i, j] = pq.top();
            pq.pop();
            remaining--;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.emplace(A[ni][nj], ni, nj);
                }
            }
        }
        ans[y-1] = remaining;
    }

    for (int y = 0; y < Y; ++y) {
        cout << ans[y] << '\n';
    }

    return 0;
}