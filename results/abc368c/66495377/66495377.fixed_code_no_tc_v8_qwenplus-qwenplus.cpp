#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to compute the number of attacks needed for a single enemy
ll compute_attacks(ll t, ll h) {
    ll low = 0;
    ll high = 2 * h; // Upper bound for binary search (safe over-approximation)

    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = 0;

        // Compute total damage after 'mid' seconds
        for (ll i = 1; i <= mid; ++i) {
            if ((t + i) % 3 == 0) {
                damage += 3;
            } else {
                damage += 1;
            }
        }

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

    ll T = 0;
    for (int i = 0; i < n; ++i) {
        ll attacks_needed = compute_attacks(T, H[i]);
        T += attacks_needed;
    }

    cout << T << endl;
    return 0;
}