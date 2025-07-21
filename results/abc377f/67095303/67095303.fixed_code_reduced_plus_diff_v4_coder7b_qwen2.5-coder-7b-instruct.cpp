#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define inf 1e9 + 7

using namespace std;

int qpowm(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1)
            (r *= a) %= m;
        (a *= a) %= m, b >>= 1;
    }
    return r;
}

int qpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)
            r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    set<int> h, v, d1, d2; // d1 stores i+j=d, d2 stores i-j=d
    
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        h.insert(x);
        v.insert(y);
        d1.insert(x + y);
        d2.insert(x - y);
    }

    int ans = (n - h.size()) * (n - v.size());

    for (auto d : d1) {
        set<int> s; // Record already counted row indices
        for (auto x : h) {
            if (1 <= d - x && d - x <= n) {
                s.insert(d - x);
            }
        }

        for (auto y : v) {
            if (1 <= d - y && d - y <= n) {
                s.insert(d - y);
            }
        }

        int len = (d <= n + 1) ? d - 1 : n - (d - n);
        ans -= (len - s.size());
    }

    for (auto d : d2) {
        set<int> s; // Record already counted row indices
        for (auto x : h) {
            if (1 <= x - d && x - d <= n) {
                s.insert(x - d);
            }
        }

        for (auto y : v) {
            if (1 <= d + y && d + y <= n) {
                s.insert(d + y);
            }
        }

        for (auto e : d1) {
            if ((e + d) % 2 == 0 && (e - d) % 2 == 0) {
                int si = (e + d) / 2, sj = (e - d) / 2;
                if (si >= 2 && si <= n && sj >= 1 && sj <= n) {
                    s.insert(si);
                }
            }
        }

        int len = (d <= 0) ? n - (1 - d) : n - d;
        ans -= (len - s.size());
    }

    cout << ans << endl;
}

signed main() {
    int _ = 1;
    while (_) {
        solve();
    }
    return 0;
}