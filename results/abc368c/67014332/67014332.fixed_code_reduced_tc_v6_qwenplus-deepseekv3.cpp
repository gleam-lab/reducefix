#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; i++) {
        cin >> H[i];
    }
    
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll h = H[i];
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        
        ans += full_cycles * 3;
        
        if (remaining > 0) {
            if (remaining <= 2) {
                ans += remaining;
            } else {
                ans += 1;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}