#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate number of attacks needed for a single enemy
ll compute_attacks(ll t, ll h) {
    ll low = 0;
    ll high = 2 * h; // Upper bound for binary search

    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = 0;

        // Calculate how many special attacks (×3) occur in 'mid' time steps
        ll special_attacks = mid / 3;
        ll normal_attacks = mid - special_attacks;

        damage += normal_attacks * 1;
        damage += special_attacks * 3;

        if (damage >= h) {
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

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll attacks_needed = compute_attacks(t, H[i]);
        t += attacks_needed;
    }

    cout << t << endl;

    return 0;
}