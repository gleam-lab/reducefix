#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;

int main() {
    cin >> n >> m;
    set<pair<ll, ll>> st;
    for (int i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        st.insert({x, y});
    }
    
    ll ans = n * n - m;
    for (auto [x, y] : st) {
        for (ll dx = -n; dx <= n; ++dx) {
            for (ll dy = -n; dy <= n; ++dy) {
                if (abs(dx) == abs(dy)) continue;
                if (st.count({x + dx, y + dy})) {
                    --ans;
                    break;
                }
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}