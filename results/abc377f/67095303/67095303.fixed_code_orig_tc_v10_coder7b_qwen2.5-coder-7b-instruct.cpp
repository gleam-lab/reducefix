#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

int qpowm(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1) (r *= a) %= m;
        (a *= a) %= m, b >>= 1;
    }
    return r;
}

int qpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    set<int> h, v, d1, d2; // d1 for positive slope diagonals, d2 for negative slope diagonals
    
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        h.insert(x);
        v.insert(y);
        d1.insert(x + y);
        d2.insert(x - y);
    }

    int ans = (n - h.size()) * (n - v.size());

    for (auto d : d1) {
        // i + j = d
        set<int> s; // record already counted rows
        for (auto x : h) { // find horizontal lines intersecting this diagonal
            if (1 <= d - x && d - x <= n) {
                s.insert(x);
            }
        }

        for (auto y : v) { // find vertical lines intersecting this diagonal
            if (1 <= d - y && d - y <= n) {
                s.insert(d - y);
            }
        }

        int len = 0;
        if (d <= n + 1) { // top-left part, columns 1 to d-1
            len = d - 1;
        } else { // bottom-right part, columns d-n to n
            len = n - (d - n) + 1;
        }
        ans -= (len - s.size()); // subtract already counted points
    }

    for (auto d : d2) {
        // i - j = d
        set<int> s; // record already counted rows
        for (auto x : h) { // find horizontal lines intersecting this diagonal
            if (1 <= x - d && x - d <= n) {
                s.insert(x);
            }
        }

        for (auto y : v) { // find vertical lines intersecting this diagonal
            if (1 <= d + y && d + y <= n) {
                s.insert(d + y);
            }
        }

        for (auto e : d1) {
            // i + j == e, i - j == d
            if ((e + d) % 2 == 0 && (e - d) % 2 == 0) {
                int si = (e + d) / 2, sj = (e - d) / 2;
                if (si >= 2 && si <= n && sj >= 1 && sj <= n) {
                    s.insert(si);
                }
            }
        }

        int len = 0;
        if (d <= 0) { // top-right part, columns 1 to -d
            len = n - (1 - d) + 1;
        } else { // bottom-left part, columns 1 to n-d
            len = n - d;
        }
        ans -= (len - s.size()); // subtract already counted points
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