#include <bits/stdc++.h>
using namespace std;
using atcoder::min_priority_queue;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    int total = H * W;
    vector<vector<bool>> sea(H, vector<bool>(W, false));
    min_priority_queue<T> pq;

    // Initialize border cells
    rep(i, H) {
        if (!sea[i][0]) {
            sea[i][0] = true;
            pq.emplace(A[i][0], i, 0);
        }
        if (!sea[i][W-1]) {
            sea[i][W-1] = true;
            pq.emplace(A[i][W-1], i, W-1);
        }
    }
    rep(j, W) {
        if (!sea[0][j]) {
            sea[0][j] = true;
            pq.emplace(A[0][j], 0, j);
        }
        if (!sea[H-1][j]) {
            sea[H-1][j] = true;
            pq.emplace(A[H-1][j], H-1, j);
        }
    }

    vector<int> result(Y + 2);
    result[0] = total;

    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (!sea[nx][ny]) {
                sea[nx][ny] = true;
                if (height <= Y) result[height]--;
                pq.emplace(max(height, A[nx][ny]), nx, ny);
            }
        }
    }

    // Fill in missing values
    for (int y = 1; y <= Y; ++y) {
        if (result[y] == 0) {
            result[y] = result[y - 1];
        } else {
            result[y] = result[y - 1] - result[y];
        }
    }

    // Output
    for (int y = 1; y <= Y; ++y) {
        cout << result[y] << "\n";
    }
}