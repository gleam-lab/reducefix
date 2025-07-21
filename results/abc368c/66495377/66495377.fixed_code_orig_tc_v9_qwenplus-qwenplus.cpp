#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum number of attacks needed to reduce health h to 0 or less,
// assuming attacks at times that are not multiples of 3 deal 1 damage, and those that are do 3 damage.
ll required_attacks(ll h) {
    // We need to find the minimal T such that:
    // a = number of 3-damage attacks (at times divisible by 3)
    // b = number of 1-damage attacks (other times)
    // total damage: 3a + b >= h
    // total attacks: a + b = T
    // And a <= floor(T / 3)

    // Binary search for minimal T
    ll low = 0, high = 3 * h; // upper bound on T

    while (low < high) {
        ll mid = (low + high) / 2;
        ll three_damage_attacks = mid / 3;
        ll one_damage_attacks = mid - three_damage_attacks;
        ll total_damage = 3 * three_damage_attacks + one_damage_attacks;

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

    int N;
    cin >> N;

    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll current_time = 0;

    for (int i = 0; i < N; ++i) {
        ll h = H[i];
        if (h == 0) continue; // Skip already dead enemies

        ll attacks_needed = required_attacks(h);

        // Update global time counter
        current_time += attacks_needed;
    }

    cout << current_time << endl;

    return 0;
}