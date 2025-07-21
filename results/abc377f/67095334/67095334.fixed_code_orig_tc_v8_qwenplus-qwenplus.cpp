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

    // Step 1: Start with total number of cells not in any occupied row or column
    ll ans = (n - rows.size()) * (n - cols.size());

    // Step 2: Subtract points on forbidden diagonals (i+j = d)
    for (ll d : diag1) {
        ll low = max(1LL, d - n);
        ll high = min(n, d - 1);
        ll cnt = high - low + 1;

        set<ll> blocked;
        for (ll r : rows) {
            ll c = d - r;
            if (1 <= c && c <= n) blocked.insert(r);
        }
        for (ll c : cols) {
            ll r = d - c;
            if (1 <= r && r <= n) blocked.insert(r);
        }

        ans -= (cnt - blocked.size());
    }

    // Step 3: Subtract points on forbidden anti-diagonals (i-j = d)
    for (ll d : diag2) {
        ll low = max(1LL, 1 + d);
        ll high = min(n, n + d);
        ll cnt = high - low + 1;

        set<ll> blocked;
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= n) blocked.insert(r);
        }
        for (ll c : cols) {
            ll r = d + c;
            if (1 <= r && r <= n) blocked.insert(r);
        }

        ans -= (cnt - blocked.size());
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}