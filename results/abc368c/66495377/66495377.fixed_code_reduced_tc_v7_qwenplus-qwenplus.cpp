#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the number of attacks needed for a single enemy
ll calculate_attacks(ll h) {
    // We want to find the minimum number of attacks 't' such that:
    // - The number of triple-damage attacks (at multiples of 3) is floor(t / 3)
    // - Total damage = t + floor(t / 3) * 2 >= h
    // Binary search on 't'
    ll low = 0, high = 2e18;
    while (low < high) {
        ll mid = (low + high) / 2;
        ll triple = mid / 3;
        ll total_damage = mid + triple * 2; // Each triple attack adds extra 2 damage
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

    ll total_time = 0;
    for (ll h : H) {
        ll attacks_needed = calculate_attacks(h);
        total_time += attacks_needed;
    }

    cout << total_time << "\n";
    return 0;
}