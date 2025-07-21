#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>

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
    
    set<int> horizontal, vertical, diag1, diag2;
    
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        horizontal.insert(x);
        vertical.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    int ans = (n - (int)horizontal.size()) * (n - (int)vertical.size());
    
    for (auto d : diag1) {
        set<int> s;
        for (auto x : horizontal) {
            if (1 <= d - x && d - x <= n) {
                s.insert(x);
            }
        }
        
        for (auto y : vertical) {
            if (1 <= d - y && d - y <= n) {
                s.insert(d - y);
            }
        }
        
        int len = 0;
        if (d <= n + 1) {
            len = d - 1;
        } else {
            len = n - (d - n) + 1;
        }
        ans -= (len - s.size());
    }

    for (auto d : diag2) {
        set<int> s;
        for (auto x : horizontal) {
            if (1 <= x - d && x - d <= n) {
                s.insert(x);
            }
        }
        
        for (auto y : vertical) {
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
        
        int len = 0;
        if (d <= 0) {
            len = n - (1 - d) + 1;
        } else {
            len = n - d;
        }
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