#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool can_defeat_all(int n, const vector<ll>& h, ll T) {
    vector<ll> attacks(T + 1); // Count how many attacks happen at each time

    // For each time step, count how many enemies have been hit
    // Only the first N times are used, since only frontmost enemy is attacked
    for (ll t = 1; t <= T && t <= n; ++t) {
        ll num_attacks = (T - t) / 3 + 1;
        attacks[t] = num_attacks;
    }

    vector<ll> damage(n);
    for (ll i = 0; i < n; ++i) {
        ll d3 = attacks[i + 1]; // number of attacks at position i+1 (1-based)
        ll d1 = ((T - (i + 1)) - 3 * d3 + 1) + 1; // remaining attacks not divisible by 3

        damage[i] = 3 * d3 + 1 * (d1 > 0 ? d1 : 0);

        if (damage[i] < h[i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    ll left = 0, right = 6e14; // Safe upper bound
    ll answer = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (can_defeat_all(n, h, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
}