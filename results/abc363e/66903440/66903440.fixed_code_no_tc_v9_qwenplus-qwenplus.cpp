#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using pii = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int INF = 1e9 + 5;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // visited[i][j] = true if cell (i,j) is submerged
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Queue for events at each sea level
    vector<queue<pii>> q(Y + 2);

    // Initialize border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                q[A[i][j]].push({i, j});
            }
        }
    }

    int remaining = H * W;
    vector<int> ans(Y + 1);

    for (int year = 1; year <= Y; ++year) {
        queue<pii> process;
        while (!q[year].empty()) {
            process.push(q[year].front());
            q[year].pop();
        }

        while (process.size()) {
            auto [x, y] = process.front();
            process.pop();
            --remaining;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (A[nx][ny] <= year) {
                        q[year].push({nx, ny});
                    } else {
                        q[A[nx][ny]].push({nx, ny});
                    }
                }
            }
        }

        ans[year] = remaining;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}