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
    int cnt = n * m;

    while (q--)
    {
        int r, c; cin >> r >> c;
        --r, --c; // Convert to 0-based index

        if (grid[r][c])
        {
            grid[r][c] = false;
            --cnt;
            continue;
        }

        // Destroy walls in the same row to the left
        for (int j = c - 1; j >= 0 && !grid[r][j]; --j)
        {
            ++cnt;
            grid[r][j] = true;
        }

        // Destroy walls in the same row to the right
        for (int j = c + 1; j < m && !grid[r][j]; ++j)
        {
            ++cnt;
            grid[r][j] = true;
        }

        // Destroy walls in the same column above
        for (int i = r - 1; i >= 0 && !grid[i][c]; --i)
        {
            ++cnt;
            grid[i][c] = true;
        }

        // Destroy walls in the same column below
        for (int i = r + 1; i < n && !grid[i][c]; ++i)
        {
            ++cnt;
            grid[i][c] = true;
        }
    }

    cout << cnt << "\n";
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