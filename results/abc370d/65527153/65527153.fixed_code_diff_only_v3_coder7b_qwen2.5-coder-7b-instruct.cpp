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
    vector<set<int>> st1(n + 1), st2(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            st1[i].emplace(j);
            st2[j].emplace(i);
        }
    }

    auto erase = [&](int r, int c) -> void {
        st1[r].erase(c);
        st2[c].erase(r);
    };

    while (q--) {
        int r, c; cin >> r >> c;
        if (st1[r].count(c)) {
            erase(r, c);
            continue;
        }

        // Correctly handle the case where no wall is found in any direction
        bool found = false;
        // Check upwards
        for (int i = r - 1; i >= 1; --i) {
            if (!st1[i].empty()) {
                erase(i, c);
                found = true;
                break;
            }
        }
        if (!found) {
            // Check downwards
            for (int i = r + 1; i <= n; ++i) {
                if (!st1[i].empty()) {
                    erase(i, c);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            // Check leftwards
            for (int j = c - 1; j >= 1; --j) {
                if (!st2[j].empty()) {
                    erase(r, j);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            // Check rightwards
            for (int j = c + 1; j <= m; ++j) {
                if (!st2[j].empty()) {
                    erase(r, j);
                    found = true;
                    break;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += st1[i].size();
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