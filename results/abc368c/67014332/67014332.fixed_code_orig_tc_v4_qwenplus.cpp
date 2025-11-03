#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll tri = 1;
    
    for(int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        
        // Process in chunks of 3 attacks (where every 3rd attack does 3 damage)
        // In 3 consecutive attacks: total damage = 1 + 1 + 3 = 5
        ll full_cycles = h / 5;
        ans += full_cycles * 3;  // 3 time units per cycle
        h -= full_cycles * 5;
        
        // Handle remaining health with individual attacks
        while(h > 0) {
            ans++;
            if (tri == 3) {
                h -= 3;
                tri = 1;
            } else {
                h -= 1;
                tri++;
            }
        }
    }
    
    cout << ans;
    return 0;
}