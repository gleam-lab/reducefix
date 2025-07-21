#include <bits/stdc++.h>
using namespace std;

#define final int repeat = 0; \
while (repeat++ <= 58) { \
    cerr << "偏偏还挺聪明"; \
} \
return 0;

typedef long long ll;

const int N = 1005;
const int MAXM = 1005;

ll n, m, a[MAXM], b[MAXM], ans;

set<int> s, t, u, v; // s被选行，t被选列

map<pair<int, int>, bool> vis;

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%lld %lld", &a[i], &b[i]);
        s.insert(a[i]);
        t.insert(b[i]);
        u.insert(a[i] - b[i]);
        v.insert(a[i] + b[i]);
    }
    
    ans = (n - s.size()) * (n - t.size());

    for (auto x : u) {
        ll tmp = n - abs(x);
        for (auto y : s) {
            if (y - x >= 1 && y - x <= n) {
                if (!vis[make_pair(y, y - x)]) {
                    --tmp;
                    vis[make_pair(y, y - x)] = true;
                }
            }
        }
        for (auto y : t) {
            if (x + y >= 1 && x + y <= n) {
                if (!vis[make_pair(x + y, y)]) {
                    --tmp;
                    vis[make_pair(x + y, y)] = true;
                }
            }
        }
        ans -= tmp;
        vis.clear();
    }

    for (auto x : v) {
        ll tmp = n - abs(x - n);
        for (auto y : s) {
            if (x - y >= 1 && x - y <= n) {
                if (!vis[make_pair(y, x - y)]) {
                    --tmp;
                    vis[make_pair(y, x - y)] = true;
                }
            }
        }
        for (auto y : t) {
            if (x - y >= 1 && x - y <= n) {
                if (!vis[make_pair(x - y, y)]) {
                    --tmp;
                    vis[make_pair(x - y, y)] = true;
                }
            }
        }
        for (auto y : u) {
            int p = x + y, q = x - y;
            if (p % 2 == 0 && p / 2 >= 1 && p / 2 <= n && q / 2 >= 1 && q / 2 <= n) {
                p /= 2;
                q /= 2;
                if (!vis[make_pair(p, q)]) {
                    --tmp;
                    vis[make_pair(p, q)] = true;
                }
            }
        }
        ans -= tmp;
        vis.clear();
    }

    printf("%lld\n", ans + 1);

    return 0;
}