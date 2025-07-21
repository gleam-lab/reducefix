#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    int m;
    cin >> n >> m;

    set<ll> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    ll safe_rows = n - rows.size();
    ll safe_cols = n - cols.size();
    ll total_safe = safe_rows * safe_cols;

    // Now subtract squares threatened by diag1 lines
    for (ll d : diag1) {
        ll low = max(1LL, d - n);
        ll high = min(n, d - 1);
        ll len = max(0LL, high - low + 1);

        set<ll> covered;
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= n) covered.insert(r);
        }
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= n) covered.insert(r);
        }

        total_safe -= (len - covered.size());
    }

    // Now subtract squares threatened by diag2 lines
    for (ll d : diag2) {
        ll low = max(1LL, 1 + d);
        ll high = min(n, n + d);
        ll len = max(0LL, high - low + 1);

        set<ll> covered;
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= n) covered.insert(r);
        }
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= n) covered.insert(r);
        }

        total_safe -= (len - covered.size());
    }

    cout << total_safe << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}