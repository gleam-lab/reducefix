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
    ll tri = 0; // T mod 3, starts at 0 (T=0 initially)
    
    for (ll i = 0; i < n; ++i) {
        ll h = H[i];
        // Number of full cycles (5 health per 3 attacks)
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h %= 5;
        
        // Handle remaining health
        while (h > 0) {
            ans++;
            if (tri == 2) { // Next attack is T mod 3 == 0 (since tri is 0-based)
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