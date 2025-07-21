#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculateTotalAttacks(ll T, const vector<ll>& H) {
    ll total = 0;
    for (ll h : H) {
        ll attacks = 0;
        // For each enemy, the number of attacks is such that sum of damages >= h
        // Damage pattern: 1, 1, 3, 1, 1, 3, ...
        // For T total attacks, the number of full cycles (3 attacks) is T / 3
        // Each cycle contributes 5 damage (1+1+3)
        // The remaining attacks contribute 1 or 1+1 depending on the remainder
        ll full_cycles = T / 3;
        ll remaining = T % 3;
        ll damage = full_cycles * 5;
        if (remaining >= 1) damage += 1;
        if (remaining >= 2) damage += 1;
        if (damage >= h) {
            total += (h + 2) / 3; // Minimum attacks needed when using optimal damage
        } else {
            ll needed = h - damage;
            attacks = full_cycles * 3 + remaining;
            attacks += needed;
            total += attacks;
        }
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll low = 0;
    ll high = 1e18;
    ll answer = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_attacks = 0;
        for (ll h : H) {
            ll full_cycles = mid / 3;
            ll remaining = mid % 3;
            ll damage = full_cycles * 5;
            if (remaining >= 1) damage += 1;
            if (remaining >= 2) damage += 1;
            if (damage < h) {
                ll needed = h - damage;
                total_attacks = mid + needed;
                break;
            }
        }
        if (total_attacks <= mid) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}