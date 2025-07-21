#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates minimum number of attacks needed to reduce health h to 0 or less
// given that the first attack occurs at time t+1
ll compute_attacks(ll t, ll h) {
    // Binary search for minimal required attacks
    ll low = 0, high = 2e18;
    
    while (low < high) {
        ll mid = (low + high) / 2;
        // Calculate how many triple attacks we can have in 'mid' steps
        // starting from time t+1
        ll triple_attacks = 0;
        ll start = t + 1;
        
        // First find the first time that is a multiple of 3
        if (start % 3 != 0) {
            ll add = (3 - start % 3);
            if (add <= mid) {
                triple_attacks++;
                start += add;
            }
        }
        
        // From here on, every 3rd step is a triple attack
        if (start + 3 <= t + mid) {
            ll remaining = (t + mid - start) / 3;
            triple_attacks += remaining;
        }
        
        ll total_damage = triple_attacks * 3 + (mid - triple_attacks);
        
        if (total_damage >= h) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (ll i = 0; i < n; ++i) {
        ll attacks = compute_attacks(T, H[i]);
        T += attacks;
    }
    
    cout << T << endl;
    
    return 0;
}