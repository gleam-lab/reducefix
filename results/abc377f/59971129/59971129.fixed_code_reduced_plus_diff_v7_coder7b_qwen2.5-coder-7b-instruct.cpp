#include <bits/stdc++.h>
using namespace std;

#define N 1005
#define mk make_pair

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    
    set<ll> s, t, u, v; // s for rows, t for columns, u for diagonal i-j, v for diagonal i+j
    
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        s.insert(a);
        t.insert(b);
        u.insert(a - b);
        v.insert(a + b);
    }
    
    ll ans = (n - s.size()) * (n - t.size());
    
    for (auto x : u) {
        ll tmp = n - abs(x);
        for (auto y : s) {
            if (y - x >= 1 && y - x <= n) {
                if (!v.count(y - x)) {
                    --tmp;
                    v.insert(y - x);
                }
            }
        }
        for (auto y : t) {
            if (x + y >= 1 && x + y <= n) {
                if (!v.count(x + y)) {
                    --tmp;
                    v.insert(x + y);
                }
            }
        }
        ans -= tmp;
        v.clear();
    }
    
    for (auto x : v) {
        ll tmp = n - abs(x - n);
        for (auto y : s) {
            if (x - y >= 1 && x - y <= n) {
                if (!u.count(x - y)) {
                    --tmp;
                    u.insert(x - y);
                }
            }
        }
        for (auto y : t) {
            if (x - y >= 1 && x - y <= n) {
                if (!u.count(x - y)) {
                    --tmp;
                    u.insert(x - y);
                }
            }
        }
        for (auto y : u) {
            int p = x + y, q = x - y;
            if (p % 2 == 0 && p / 2 >= 1 && p / 2 <= n && q / 2 >= 1 && q / 2 <= n) {
                p /= 2;
                q /= 2;
                if (!u.count(p + q)) {
                    --tmp;
                    u.insert(p + q);
                }
            }
        }
        ans -= tmp;
        u.clear();
    }
    
    cout << ans + 1 << endl;
    return 0;
}