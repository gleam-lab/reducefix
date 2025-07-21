#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n, m; cin >> n >> m;
    set<ll> rows, cols, diags1, diags2;

    for(ll i = 0; i < m; ++i) {
        ll r, c; cin >> r >> c;
        rows.insert(r), cols.insert(c), diags1.insert(r + c), diags2.insert(r - c);
    }

    ll ans = (n - rows.size()) * (n - cols.size());

    for(auto d1 : diags1) {
        ll count = 0;
        for(auto row : rows) if(row > abs(d1)) --count;
        for(auto col : cols) if(abs(d1) - col >= 1 && abs(d1) - col <= n) --count;
        ans -= count;
    }

    for(auto d2 : diags2) {
        ll count = 0;
        for(auto row : rows) if(row > abs(d2)) --count;
        for(auto col : cols) if(col - abs(d2) >= 1 && col - abs(d2) <= n) --count;
        ans -= count;
    }

    cout << ans << '\n';

    return 0;
}