#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to determine how many attacks are needed to defeat an enemy with health h,
// given that the current time is t (so attacks at times t+1, t+2, ... will be made)
ll num_attacks_needed(ll t, ll h) {
    // Binary search bounds: minimum 0 attacks, max we might need up to h attacks
    ll low = 0, high = 3 * h;
    
    while (low < high) {
        ll mid = (low + high) / 2;
        
        ll damage = 0;
        for (ll i = 1; i <= mid; ++i) {
            ll curr_time = t + i;
            if (curr_time % 3 == 0) {
                damage += 3;
            } else {
                damage++;
            }
        }
        
        if (damage >= h) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll attacks_needed = num_attacks_needed(t, H[i]);
        t += attacks_needed;
    }

    cout << t << endl;
}