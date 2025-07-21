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
    ll tri = 0; // This will track the position in the attack sequence (0,1,2)
    
    for (ll i = 0; i < n; i++) {
        ll h = H[i];
        // Calculate full cycles of 3 attacks (damage 5 per cycle)
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h %= 5;
        tri += full_cycles * 3;
        tri %= 3;
        
        while (h > 0) {
            ans++;
            if (tri == 2) {
                h -= 3;
            } else {
                h -= 1;
            }
            tri = (tri + 1) % 3;
        }
    }
    
    cout << ans << endl;
    return 0;
}