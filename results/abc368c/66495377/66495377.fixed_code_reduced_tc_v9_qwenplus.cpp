#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the number of attacks needed for an enemy with health h, starting at time t
ll num_attack(ll t, ll h) {
    if (h == 0) return 0;

    // We want to find the minimum number of attacks k such that total damage >= h
    // Damage depends on how many of the next k attacks occur at T % 3 == 0

    // Instead of simulating, we can binary search on k
    ll low = 1, high = h; // at least h attacks (if all do 1 damage), at most h (but likely less)
    while (low < high) {
        ll mid = (low + high) / 2;
        // Count how many multiples of 3 in the range [t+1, t+mid]
        ll start = t + 1;
        ll end = t + mid;
        ll triple_attacks = end / 3 - (start - 1) / 3;
        ll single_attacks = mid - triple_attacks;
        ll total_damage = triple_attacks * 3 + single_attacks * 1;

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
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        ll attacks_needed = num_attack(t, h);
        t += attacks_needed;
    }

    cout << t << endl;
}