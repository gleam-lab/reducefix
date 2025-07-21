#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;
vector<pair<ll, ll>> ps;

bool valid(ll x, ll y) {
    for(auto [px, py]: ps) {
        if(x == px || y == py || abs(x - px) == abs(y - py)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    ps.resize(m);
    for(auto &p: ps) cin >> p.first >> p.second;

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(valid(i, j)) ++ans;
        }
    }

    cout << ans << '\n';
    return 0;
}