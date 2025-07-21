#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()
const int N = 200020;
int n, m;

void solve()
{
    int q;
    cin >> n >> m >> q;
    vector<set<int>> row(n + 1), col(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    auto erase = [&](int r, int c) {
        row[r].erase(c);
        col[c].erase(r);
    };

    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (row[r].count(c)) {
            // Cell has a wall, just remove it
            erase(r, c);
            continue;
        }

        // Look right in the same row
        auto it = row[r].lower_bound(c);
        if (it != row[r].end()) {
            erase(r, *it);
        }

        // Look left in the same row
        it = row[r].lower_bound(c);
        if (it != row[r].begin()) {
            --it;
            if (*it < c) {
                erase(r, *it);
            }
        }

        // Look down in the same column
        auto jt = col[c].lower_bound(r);
        if (jt != col[c].end()) {
            erase(*jt, c);
        }

        // Look up in the same column
        jt = col[c].lower_bound(r);
        if (jt != col[c].begin()) {
            --jt;
            if (*jt < r) {
                erase(*jt, c);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += row[i].size();
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}