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
    vector<vector<bool>> grid(n + 1, vector<bool>(m + 1, true));
    
    auto destroyWall = [&](int r, int c) -> void {
        if (grid[r][c]) {
            grid[r][c] = false;
            return;
        }
        // Destroy walls in the same row and column
        for (int i = 1; i <= n; ++i) {
            if (grid[i][c]) {
                grid[i][c] = false;
                break;
            }
        }
        for (int j = 1; j <= m; ++j) {
            if (grid[r][j]) {
                grid[r][j] = false;
                break;
            }
        }
    };

    while (q--) {
        int r, c; cin >> r >> c;
        destroyWall(r, c);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
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