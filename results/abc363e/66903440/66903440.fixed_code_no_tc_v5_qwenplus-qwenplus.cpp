#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define pb push_back

using ll = long long;
using pii = pair<int, int>;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Total number of cells
    int total = H * W;

    // Initialize: true means still above water
    vector<vector<bool>> alive(H, vector<bool>(W, true));

    // Queue for each height level
    vector<queue<pii>> q(Y + 2); // up to Y+1 inclusive

    // Mark boundary cells as submerged and add to queue
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            alive[i][j] = false;
            if (A[i][j] <= Y) {
                q[A[i][j]].push({i, j});
            }
        }
    }

    // Process each year
    int remaining = total;
    for (int y = 1; y <= Y; ++y) {
        queue<pii> process;
        
        // Add all cells with height exactly y that are not yet processed
        while (!q[y].empty()) {
            auto [i, j] = q[y].front();
            q[y].pop();
            if (alive[i][j]) {
                alive[i][j] = false;
                process.push({i, j});
                --remaining;
            }
        }

        // BFS to flood connected regions with height <= current sea level
        while (!process.empty()) {
            auto [i, j] = process.front();
            process.pop();

            rep(k, 4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && alive[ni][nj] && A[ni][nj] <= y) {
                    alive[ni][nj] = false;
                    process.push({ni, nj});
                    --remaining;
                }
            }
        }

        cout << remaining << "\n";
    }

    return 0;
}