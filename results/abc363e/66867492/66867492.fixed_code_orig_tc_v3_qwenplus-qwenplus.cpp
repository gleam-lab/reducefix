#include <bits/stdc++.h>
using namespace std;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.precision(12);
    }
} init;

using i64 = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using Pi = pair<int, int>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    for (auto &row : A) {
        for (auto &x : row) {
            cin >> x;
        }
    }

    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1};

    // Store cells on the boundary of the sea
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize with all border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    int total = H * W;
    vi ans(Y + 2);

    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty() && pq.top()[0] <= y) {
            auto top = pq.top();
            pq.pop();
            int h = top[0], r = top[1], c = top[2];
            if (!visited[r][c]) {
                --total;
                visited[r][c] = true;
            }
            for (int d = 0; d < 4; ++d) {
                int nr = r + dy[d], nc = c + dx[d];
                if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
                    pq.push({A[nr][nc], nr, nc});
                }
            }
        }
        ans[y] = total;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << '\n';
    }
}