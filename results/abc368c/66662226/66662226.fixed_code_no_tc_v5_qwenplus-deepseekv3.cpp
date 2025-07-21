#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    
    ll low = 0, high = 1e18;
    ll ans = high;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        vector<ll> damage(n);
        
        for (int i = 0; i < n; ++i) {
            ll t = mid - (n - 1 - i);
            if (t < 0) t = 0;
            ll cnt3 = t / 3;
            ll cnt1 = t - cnt3;
            damage[i] = cnt1 + cnt3 * 3;
        }
        
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (damage[i] < H[i]) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}