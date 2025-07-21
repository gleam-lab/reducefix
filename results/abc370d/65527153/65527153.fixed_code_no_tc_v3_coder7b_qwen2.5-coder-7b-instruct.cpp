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
    
    auto destroyWalls = [&](int r, int c) -> void {
        if (grid[r][c]) {
            grid[r][c] = false;
            return;
        }
        
        // Destroy walls above
        for (int i = r - 1; i >= 0 && !grid[i][c]; --i) {
            grid[i][c] = false;
        }
        // Destroy walls below
        for (int i = r + 1; i < n && !grid[i][c]; ++i) {
            grid[i][c] = false;
        }
        // Destroy walls to the left
        for (int j = c - 1; j >= 0 && !grid[r][j]; --j) {
            grid[r][j] = false;
        }
        // Destroy walls to the right
        for (int j = c + 1; j < m && !grid[r][j]; ++j) {
            grid[r][j] = false;
        }
    };

    while (q--) {
        int r, c; cin >> r >> c;
        destroyWalls(r - 1, c - 1); // Adjusting for zero-based indexing
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) ans++;
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