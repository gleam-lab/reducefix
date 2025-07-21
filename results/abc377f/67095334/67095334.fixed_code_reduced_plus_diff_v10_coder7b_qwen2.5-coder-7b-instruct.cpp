#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

int qpowm(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1)(r *= a) %= m;
        (a *= a) %= m, b >>= 1;
    }
    return r;
}

int qpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}

void solve() {
    int n, q;
    cin >> n >> q;
    set<int>h, v, d1, d2; // d1 stores i+j=d for diagonal lines, d2 stores i-j=d for anti-diagonal lines

    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        h.insert(x);
        v.insert(y);
        d1.insert(x + y);
        d2.insert(x - y);
    }

    int ans = (n - (int)h.size()) * (n - (int)v.size());

    for (auto d : d1) {
        // i+j=d diagonal line
        set<int>s; // record already considered row indices
        for (auto x : h) { // find all horizontal lines intersecting this diagonal
            if (1 <= d - x && d - x <= n) {
                s.insert(x);
            }
        }

        for (auto y : v) { // find all vertical lines intersecting this diagonal
            if (1 <= d - y && d - y <= n) {
                s.insert(d - y);
            }
        }

        int len = 0;
        if (d <= n + 1) { // in upper-left part, column index ranges from 1 to d-1
            len = d - 1;
        } else { // in lower-right part, column index ranges from d-n to n
            len = n - (d - n) + 1;
        }
        ans -= (len - s.size()); // subtract the number of points already considered on this diagonal
    }

    for (auto d : d2) {
        // i-j=d anti-diagonal line
        set<int>s; // record already considered row indices
        for (auto x : h) { // find all horizontal lines intersecting this anti-diagonal
            if (1 <= x - d && x - d <= n) {
                s.insert(x);
            }
        }

        for (auto y : v) { // find all vertical lines intersecting this anti-diagonal
            if (1 <= d + y && d + y <= n) {
                s.insert(d + y);
            }
        }

        for (auto e : d1) {
            // i+j=e, i-j=d
            if ((e + d) % 2 == 0 && (e - d) % 2 == 0) {
                int si = (e + d) / 2, sj = (e - d) / 2;
                if (si >= 2 && si <= n && sj >= 1 && sj <= n) {
                    s.insert(si);
                }
            }
        }

        int len = 0;
        if (d <= 0) { // in upper-right part, column index ranges from 1-d to n
            len = n - (1 - d) + 1;
        } else { // in lower-left part, column index ranges from 1-n-d to n
            len = n - d;
        }
        ans -= (len - s.size()); // subtract the number of points already considered on this anti-diagonal
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