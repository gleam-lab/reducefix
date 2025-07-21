#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<ll> h(n);
    rep(i, n) {
        cin >> h[i];
        ll full_cycles = h[i] / 5;
        ll remainder = h[i] % 5;
        
        ans += full_cycles * 3;
        
        if (remainder > 0) {
            if (remainder <= 3) {
                ans += remainder;
            } else {
                ans += 3;
            }
        }
    }
    
    cout << ans << endl;
}