#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll low = 0, high = 1e18;
    ll ans = 0;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        vector<ll> damage(n);
        ll total = 0;
        bool possible = true;
        
        for (int i = n - 1; i >= 0; --i) {
            damage[i] = h[i] - total;
            if (damage[i] > 0) {
                ll needed = (damage[i] + 2) / 3; // ceil(damage[i] / 3)
                total += needed;
                if (total > mid) {
                    possible = false;
                    break;
                }
            }
        }
        
        if (possible) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}