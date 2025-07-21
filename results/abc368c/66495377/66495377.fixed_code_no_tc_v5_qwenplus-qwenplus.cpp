#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the number of attacks needed for one enemy, given current time t
ll calculateAttacks(ll t, ll h) {
    ll low = 0;
    ll high = 2 * h; // Upper bound: at most 2 attacks per health point

    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = 0;

        // Count how many triple attacks (3 damage) occur in mid attacks
        ll triple_attacks = mid / 3;
        damage += triple_attacks * 3;
        damage += (mid - triple_attacks); // Remaining are single attacks

        if (damage >= h)
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
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll attacks_needed = calculateAttacks(t, H[i]);
        t += attacks_needed;
    }

    cout << t << endl;
    return 0;
}