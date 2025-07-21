#include <bits/stdc++.h>

#define ll long long
#define INF 1e9+7

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll n, m;
    cin >> n >> m;

    set<ll> rows, cols, diag1, diag2;

    for(ll i = 0; i < m; ++i){
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    ll ans = (n - rows.size()) * (n - cols.size());
    
    for(auto& d1 : diag1){
        set<ll> s;
        for(auto& r : rows) if(r + d1 <= n) s.insert(r);
        for(auto& c : cols) if(c + d1 <= n) s.insert(c);
        ll len = d1 <= n ? d1 : n - (d1 - n) + 1;
        ans -= (len - s.size());
    }
    
    for(auto& d2 : diag2){
        set<ll> s;
        for(auto& r : rows) if(r - d2 >= 1) s.insert(r);
        for(auto& c : cols) if(c - d2 >= 1) s.insert(c);
        for(auto& d1 : diag1) if((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0){
            ll si = (d1 + d2) / 2, sj = (d1 - d2) / 2;
            if(si >= 1 && si <= n && sj >= 1 && sj <= n) s.insert(si);
        }
        ll len = d2 >= 1 ? d2 : n - (1 - d2) + 1;
        ans -= (len - s.size());
    }

    cout << ans << '\n';

    return 0;
}