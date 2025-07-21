#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll ans = 0;
    ll carry = 0;
    
    for (int i = 0; i < n; ++i) {
        h[i] -= carry;
        if (h[i] <= 0) {
            carry = -h[i];
            continue;
        }
        
        ll full_cycles = h[i] / 5;
        ll remaining = h[i] % 5;
        
        ll attacks = full_cycles * 3;
        if (remaining > 0) {
            if (remaining <= 3) {
                attacks += remaining;
            } else {
                attacks += 3;
            }
        }
        
        ans += attacks;
        carry = 0;
    }
    
    cout << ans << endl;
}