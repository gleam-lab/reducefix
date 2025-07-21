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
    ll ans = 0;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        vector<ll> temp = H;
        bool possible = true;
        
        ll t = mid;
        for (int i = 0; i < n; ++i) {
            ll attacks_needed;
            if (temp[i] * 2 <= t) {
                attacks_needed = (temp[i] + 1) / 2;
            } else {
                attacks_needed = (3 * temp[i] - t + 2) / 3;
            }
            if (attacks_needed < 0) attacks_needed = 0;
            temp[i] -= attacks_needed;
            t -= attacks_needed;
            if (t < 0) break;
        }
        
        for (int i = 0; i < n; ++i) {
            if (temp[i] > 0) {
                possible = false;
                break;
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