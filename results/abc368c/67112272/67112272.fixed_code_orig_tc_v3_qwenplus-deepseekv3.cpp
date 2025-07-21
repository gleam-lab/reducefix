#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll total_attacks = 0;
    rep(i, n) {
        if (i > 0) h[i] -= total_attacks; // Adjust for previous attacks
        if (h[i] <= 0) continue; // Skip if already defeated
        
        // Calculate the number of full cycles (3 attacks: 1,1,3 damage = 5 total)
        ll full_cycles = h[i] / 5;
        ll remaining = h[i] % 5;
        
        total_attacks += full_cycles * 3;
        
        if (remaining > 0) {
            if (remaining <= 2) {
                total_attacks += remaining;
            } else {
                total_attacks += 3;
            }
        }
    }
    cout << total_attacks << endl;
}