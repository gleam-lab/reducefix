#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to determine minimum T needed to kill one enemy with health h,
// given that current time is t (used to determine when the next 3-damage attack falls)
ll min_time_to_kill(ll h, ll t) {
    // We want to determine how many attacks are needed to reduce health h to 0 or less
    // Each attack does 1 damage unless T is a multiple of 3, which does 3 damage

    ll low = 0, high = 2 * h; // upper bound on number of attacks needed
    while (low < high) {
        ll mid = (low + high) / 2;
        ll three_damage_attacks = 0;
        for (ll i = 0; i < mid; ++i) {
            if ((t + i + 1) % 3 == 0) {
                three_damage_attacks++;
            }
        }
        ll total_damage = three_damage_attacks * 3 + (mid - three_damage_attacks) * 1;
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

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll current_time = 0;
    for (int i = 0; i < n; ++i) {
        ll attacks_needed = min_time_to_kill(H[i], current_time);
        current_time += attacks_needed;
    }

    cout << current_time << endl;

    return 0;
}