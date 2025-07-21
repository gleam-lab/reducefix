#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    set<ll> rows, cols, diag1, diag2;

    for (ll i = 1; i <= m; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll ans = n * n;

    // Subtract the number of occupied positions in each category
    ans -= rows.size();
    ans -= cols.size();
    ans -= diag1.size();
    ans -= diag2.size();

    // Add back the intersections since they were subtracted twice
    for (auto r : rows) {
        if (diag1.count(r + r)) --ans;
        if (diag2.count(r - r)) --ans;
    }
    for (auto c : cols) {
        if (diag1.count(c - c)) --ans;
        if (diag2.count(c + c)) --ans;
    }

    cout << ans << endl;
    return 0;
}