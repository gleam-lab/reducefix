#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    ll ans = (ll)n * (n - rows.size());
    ans += (ll)n * (n - cols.size());

    for (auto d : diag1) {
        set<int> s;
        for (auto x : rows) {
            if (1 <= d - x && d - x <= n) {
                s.insert(x);
            }
        }
        for (auto y : cols) {
            if (1 <= d - y && d - y <= n) {
                s.insert(d - y);
            }
        }
        int len = d <= n + 1 ? d - 1 : n - (d - n);
        ans -= (ll)(len - s.size());
    }

    for (auto d : diag2) {
        set<int> s;
        for (auto x : rows) {
            if (1 <= x - d && x - d <= n) {
                s.insert(x);
            }
        }
        for (auto y : cols) {
            if (1 <= d + y && d + y <= n) {
                s.insert(d + y);
            }
        }
        for (auto e : diag1) {
            if ((e + d) % 2 == 0 && (e - d) % 2 == 0) {
                int si = (e + d) / 2, sj = (e - d) / 2;
                if (si >= 2 && si <= n && sj >= 1 && sj <= n) {
                    s.insert(si);
                }
            }
        }
        int len = d <= 0 ? n - (1 - d) : n - d;
        ans -= (ll)(len - s.size());
    }

    cout << ans << '\n';

    return 0;
}