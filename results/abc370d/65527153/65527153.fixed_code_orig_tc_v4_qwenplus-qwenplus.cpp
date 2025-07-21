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
const int N = 400010;

int n, m;

struct DS {
    set<int> row[N], col[N];
};

void solve()
{
    int q;
    cin >> n >> m >> q;
    DS ds;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ds.row[i].insert(j);
            ds.col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        auto& row = ds.row[r];
        auto& col = ds.col[c];

        if (row.count(c)) {
            // Cell has wall - destroy it
            row.erase(c);
            col.erase(r);
        } else {
            // Look in four directions and destroy the first walls encountered
            // Up/Down
            auto it = col.lower_bound(r);
            if (it != col.end()) { // Down
                int y = *it;
                row = ds.row[y];
                row.erase(c);
                ds.col[c].erase(y);
            }
            if (it != col.begin()) { // Up
                --it;
                int y = *it;
                ds.row[y].erase(c);
                ds.col[c].erase(y);
            }

            // Left/Right
            auto& cells = ds.row[r];
            it = cells.lower_bound(c);
            if (it != cells.end()) { // Right
                int x = *it;
                ds.row[r].erase(x);
                ds.col[x].erase(r);
            }
            if (it != cells.begin()) { // Left
                --it;
                int x = *it;
                ds.row[r].erase(x);
                ds.col[x].erase(r);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans += ds.row[i].size();
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