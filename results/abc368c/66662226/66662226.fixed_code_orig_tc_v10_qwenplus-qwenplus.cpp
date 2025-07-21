#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to calculate the minimum number of attacks needed for one enemy
ll compute_attacks(ll h) {
    // Each cycle of 3 seconds can do 3+1+1 = 5 damage at most
    // We binary search on T to find minimal value such that we can kill the enemy
    
    ll low = 0, high = 3 * h; // upper bound estimation

    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = 0;

        // For each second up to mid, compute total damage
        for (ll t = 1; t <= mid; ++t) {
            if (t % 3 == 0) damage += 3;
            else damage += 1;
            // Optimization: early exit if already enough
            if (damage >= h) break;
        }

        if (damage >= h) high = mid;
        else low = mid + 1;
    }
    
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) cin >> H[i];

    ll ans = 0;
    vector<ll> attack_times;

    // Compute required attack times for each enemy
    for (ll h : H) {
        attack_times.push_back(compute_attacks(h));
    }

    // Greedy approach: process enemies in order, and accumulate total time
    for (ll t : attack_times) {
        ans += t;
    }

    cout << ans << endl;
}