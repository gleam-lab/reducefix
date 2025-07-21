#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, m;
    cin >> n >> m;

    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll ans = (n - rows.size()) * (n - cols.size());

    for (auto& d : diag1) {
        ll cnt = n - abs(d);
        for (auto& r : rows) {
            if (r + d >= 1 && r + d <= n) {
                --cnt;
            }
        }
        for (auto& c : cols) {
            if (d - c >= 1 && d - c <= n) {
                --cnt;
            }
        }
        ans -= cnt;
    }

    for (auto& d : diag2) {
        ll cnt = n - abs(d);
        for (auto& r : rows) {
            if (r - d >= 1 && r - d <= n) {
                --cnt;
            }
        }
        for (auto& c : cols) {
            if (d + c >= 1 && d + c <= n) {
                --cnt;
            }
        }
        ans -= cnt;
    }

    cout << ans << endl;

    return 0;
}