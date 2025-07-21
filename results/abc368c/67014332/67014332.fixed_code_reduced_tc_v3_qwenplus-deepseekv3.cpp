#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll ans = 0;
    for (ll h : H) {
        ll full_cycles = h / 5;
        h %= 5;
        ans += full_cycles * 3;
        
        if (h > 0) {
            if (h <= 1) {
                ans += 1;
            } else if (h <= 2) {
                ans += 2;
            } else {
                ans += 3;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}