#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll ans = 0;
    ll tri = 0; // T modulo 3 (0 means next attack is a multiple of 3)
    
    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        // Calculate full cycles of 3 attacks (damage 5)
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h %= 5;
        
        // Process remaining health
        while (h > 0) {
            ans++;
            if (tri == 2) { // T is a multiple of 3 next attack
                h -= 3;
                tri = 0;
            } else {
                h -= 1;
                tri++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}