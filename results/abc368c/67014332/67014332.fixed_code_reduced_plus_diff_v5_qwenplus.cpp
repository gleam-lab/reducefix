#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    ll ans = 0;
    ll tri = 1;
    
    for (int i = 0; i < n; i++) {
        ll health = h[i];
        
        // Process in chunks of 3 attacks (where every 3rd attack does 3 damage)
        // In each chunk of 3 attacks: total damage = 1 + 1 + 3 = 5
        ll full_cycles = health / 5;
        ans += full_cycles * 3;
        health %= 5;
        
        // Handle remaining health with individual attacks
        while (health > 0) {
            if (tri == 3) {
                // This attack will do 3 damage
                health -= 3;
                tri = 1;
            } else {
                // This attack will do 1 damage
                health -= 1;
                tri++;
            }
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}