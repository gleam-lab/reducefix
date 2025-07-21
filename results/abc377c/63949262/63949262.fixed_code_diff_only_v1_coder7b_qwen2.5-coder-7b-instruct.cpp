#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll n, m; cin >> n >> m;
    unordered_set<ll> s;
    
    for(ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        ll idx = (x-1)*n + y;
        s.insert(idx);
        
        if(x+2 <= n && y+1 <= n) s.insert(((x+2)-1)*n + (y+1));
        if(x+1 <= n && y+2 <= n) s.insert(((x+1)-1)*n + (y+2));
        if(x-1 >= 1   && y+2 <= n) s.insert(((x-1)-1)*n + (y+2));
        if(x-2 >= 1   && y+1 <= n) s.insert(((x-2)-1)*n + (y+1));
        if(x-2 >= 1   && y-1 >= 1) s.insert(((x-2)-1)*n + (y-1));
        if(x-1 >= 1   && y-2 >= 1) s.insert(((x-1)-1)*n + (y-2));
        if(x+1 <= n   && y-2 >= 1) s.insert(((x+1)-1)*n + (y-2));
        if(x+2 <= n   && y-1 >= 1) s.insert(((x+2)-1)*n + (y-1));
    }
    
    cout << n*n - s.size();
    return 0;
}