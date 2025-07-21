#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll ans = 0;
    rep(i, n) {
        ll cycles = h[i] / 5;
        ll remaining = h[i] % 5;
        ans += cycles * 3;
        
        if (remaining > 0) {
            if (remaining <= 2) {
                ans += remaining;
            } else {
                ans += 3;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}