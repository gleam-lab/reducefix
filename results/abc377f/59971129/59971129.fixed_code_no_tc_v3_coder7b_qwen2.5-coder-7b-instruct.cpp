#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);

    set<ll> rows, cols, diag1, diag2;

    for (ll i = 1; i <= m; ++i) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll ans = (n - rows.size()) * (n - cols.size());

    for (auto d1 : diag1) {
        ll count = 0;
        for (auto r : rows) {
            if (abs(r - d1) >= 1 && abs(r - d1) <= n) {
                count++;
            }
        }
        ans -= count;
    }

    for (auto d2 : diag2) {
        ll count = 0;
        for (auto c : cols) {
            if (abs(c - d2) >= 1 && abs(c - d2) <= n) {
                count++;
            }
        }
        ans -= count;
    }

    printf("%lld\n", ans);

    return 0;
}