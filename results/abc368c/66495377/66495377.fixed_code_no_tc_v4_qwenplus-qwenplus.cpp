#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to determine the number of attacks needed for an enemy with health h
// considering that every 3rd attack does 3 damage, others do 1 damage.
ll compute_attacks(ll h) {
    // We want to find the minimum T such that:
    // total_damage >= h
    // where every 3rd attack deals 3 damage, and other attacks deal 1 damage.

    // Let’s binary search for the required number of attacks T
    ll low = 0;
    ll high = 2 * h; // upper bound (safe estimate)

    while (low < high) {
        ll mid = (low + high) / 2;
        ll num_triple = mid / 3; // number of triple attacks
        ll num_single = mid - num_triple; // number of single attacks
        ll total_damage = num_single * 1 + num_triple * 3;

        if (total_damage >= h)
            high = mid;
        else
            low = mid + 1;
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

    ll total_time = 0;

    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        ll attacks_needed = compute_attacks(h);
        total_time += attacks_needed;
    }

    cout << total_time << endl;

    return 0;
}