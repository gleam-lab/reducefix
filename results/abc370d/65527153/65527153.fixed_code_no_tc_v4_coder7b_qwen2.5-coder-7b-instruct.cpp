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

    while (q--)
    {
        int r, c; cin >> r >> c;
        if (grid[r-1][c-1]) {
            grid[r-1][c-1] = false;
            continue;
        }

        // Look up
        for (int i = r - 2; i >= 0 && !grid[i][c-1]; --i) 
            grid[i][c-1] = false;

        // Look down
        for (int i = r; i < n && !grid[i][c-1]; ++i) 
            grid[i][c-1] = false;

        // Look left
        for (int j = c - 2; j >= 0 && !grid[r-1][j]; --j) 
            grid[r-1][j] = false;

        // Look right
        for (int j = c; j < m && !grid[r-1][j]; ++j) 
            grid[r-1][j] = false;
    }

    ll ans = 0;
    for (auto &row : grid) {
        for (bool cell : row) {
            if (cell) ans++;
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