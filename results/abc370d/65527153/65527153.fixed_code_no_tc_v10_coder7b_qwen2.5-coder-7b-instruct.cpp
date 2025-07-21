#ifndef LOCAL
#pragma optimize(2)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define zjj master
const int N = 200020, INF = 0x3f3f3f3f;
int n, m;

void solve()
{
    int q;
    cin >> n >> m >> q;
    vector<vector<bool>> grid(n, vector<bool>(m, true));

    while (q--) {
        int r, c; cin >> r >> c;
        --r, --c; // Adjusting indices to zero-based

        if (!grid[r][c]) continue; // Skip if already destroyed

        grid[r][c] = false; // Destroy current cell

        // Check and destroy walls above
        for (int i = r - 1; i >= 0; --i) {
            if (grid[i][c]) {
                grid[i][c] = false;
                break;
            }
        }

        // Check and destroy walls below
        for (int i = r + 1; i < n; ++i) {
            if (grid[i][c]) {
                grid[i][c] = false;
                break;
            }
        }

        // Check and destroy walls left
        for (int j = c - 1; j >= 0; --j) {
            if (grid[r][j]) {
                grid[r][j] = false;
                break;
            }
        }

        // Check and destroy walls right
        for (int j = c + 1; j < m; ++j) {
            if (grid[r][j]) {
                grid[r][j] = false;
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += grid[i][j];
        }
    }

    cout << ans << "\n";
}

signed main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}