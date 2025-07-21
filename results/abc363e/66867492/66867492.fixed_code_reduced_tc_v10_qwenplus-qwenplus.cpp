#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.precision(12);
    }
} init;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Mark visited cells
    vector<vector<bool>> used(H, vector<bool>(W, false));

    // Priority queue to process cells in increasing order of elevation
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], i * W + j});
                used[i][j] = true;
            }
        }
    }

    int ans = H * W;

    // Direction vectors for BFS
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    // We will simulate year-by-year
    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty() && pq.top().first <= y) {
            int val = pq.top().first;
            int pos = pq.top().second;
            pq.pop();

            if (val > y)
                continue;

            int i = pos / W;
            int j = pos % W;

            ans--;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({A[ni][nj], ni * W + nj});
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}