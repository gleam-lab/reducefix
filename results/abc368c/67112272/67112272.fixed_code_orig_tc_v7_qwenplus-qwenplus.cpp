#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

// Function to compute the required number of attacks for one enemy
ll compute_attacks(ll health) {
    // Binary search to find minimum T such that all attacks sum to at least health
    ll low = 0, high = 3 * health; // upper bound is generous
    while (low < high) {
        ll mid = (low + high) / 2;
        // In T seconds, how many attacks on this enemy?
        // Every 3 seconds: attack with power 3
        // Other seconds: attack with power 1
        ll num_triples = mid / 3;          // number of triple attacks
        ll num_singles = mid % 3 + num_triples * 2; // extra singles in incomplete round
        ll total_damage = num_triples * 3 + num_singles * 1;
        if (total_damage >= health)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    for (ll health : h) {
        ans += compute_attacks(health);
    }

    cout << ans << endl;
}