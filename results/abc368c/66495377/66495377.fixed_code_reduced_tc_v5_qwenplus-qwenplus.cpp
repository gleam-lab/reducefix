#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to compute the minimum T needed to reduce H_i to 0 or less
ll compute_attacks(ll h) {
    ll low = 0, high = 2e18; // Generous upper bound
    while (low < high) {
        ll mid = (low + high) / 2;
        // Calculate how much damage is done in mid attacks
        ll three_damage_times = mid / 3;
        ll total_damage = three_damage_times * 3 + (mid - three_damage_times) * 1;
        if (total_damage >= h)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) cin >> H[i];

    ll total_time = 0;

    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        ll attack_time = compute_attacks(h);
        total_time += attack_time;
    }

    cout << total_time << endl;
    return 0;
}