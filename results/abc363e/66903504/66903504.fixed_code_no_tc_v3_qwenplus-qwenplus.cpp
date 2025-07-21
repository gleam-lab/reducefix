#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using pii = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define pb push_back

template<typename T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Total area of the island
    int remaining = H * W;
    vector<vector<bool>> alive(H, vector<bool>(W, true));

    // Prepare events: sea level -> list of cells at that elevation
    vector<vector<pii>> level_cells(Y + 2);
    rep(i, H) rep(j, W) {
        int h = A[i][j];
        if (h <= Y) {
            level_cells[h].pb({i, j});
        }
    }

    // Union-Find to track connected land regions
    vector<int> parent(H * W), size(H * W, 1);
    iota(all(parent), 0);

    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    auto unite = [&](int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (size[px] < size[py]) swap(px, py);
        parent[py] = px;
        size[px] += size[py];
    };

    // Grid to store current active land cell index or -1
    vector<vector<int>> grid(H, vector<int>(W));
    rep(i, H) rep(j, W) grid[i][j] = i * W + j;

    // Process from highest to lowest sea level
    vector<vector<bool>> sea(H, vector<bool>(W));
    vector<int> ans(Y + 1);

    for (int y = Y; y >= 1; --y) {
        // Sink cells at this level
        for (auto [i, j] : level_cells[y]) {
            sea[i][j] = true;
            // Try to connect with adjacent land cells
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sea[ni][nj]) {
                    unite(grid[i][j], grid[ni][nj]);
                }
            }
        }

        // Find root of any surviving land
        int root = -1;
        rep(i, H) rep(j, W) {
            if (!sea[i][j]) {
                root = find(grid[i][j]);
                break;
            }
        }

        // If no land exists
        if (root == -1) {
            ans[y] = 0;
            continue;
        }

        // Count size of the connected component
        ans[y] = size[root];
    }

    // Output answers for each year
    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << '\n';
    }
}