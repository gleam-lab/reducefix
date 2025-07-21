#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    // Process each enemy from the front
    for (ll i = 0; i < n; ++i) {
        if (h[i] == 0) continue; // Skip if health is already 0
        
        // Calculate the number of full 3 attacks needed
        ll full3Attacks = h[i] / 3;
        ans += full3Attacks;
        
        // Calculate remaining health after full 3 attacks
        ll remainingHealth = h[i] % 3;
        
        // For remaining health, we can only use 1 attack per T increment
        // We minimize the T by maximizing the number of 1 attacks
        // Since we have already added full3Attacks to ans, we increment it only for 1 attacks
        ans += remainingHealth;
    }
    
    cout << ans;
}