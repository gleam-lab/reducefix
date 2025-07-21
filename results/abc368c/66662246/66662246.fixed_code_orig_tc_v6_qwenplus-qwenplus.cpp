#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    for (ll h : H) {
        // We want to find how many strong (3-damage) and weak (1-damage) attacks we need
        // Strong attack every 3 seconds, weak otherwise

        // Let x be number of strong attacks
        // Then total damage from x strong attacks = 3 * x
        // Remaining damage needed = max(0, h - 3 * x)
        // Total attacks needed = x + remaining_damage
        // Time taken = max(3 * x + remaining_damage, previous_time + total_attacks)

        // Try to maximize strong attacks without overshooting
        ll low = 0, high = h / 3 + 2;
        ll best_x = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll remaining = h - 3 * mid;
            if (remaining <= 0) {
                best_x = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ll remaining = h - 3 * best_x;
        ll total_attacks = best_x + max(0LL, remaining);
        T += total_attacks;
    }

    cout << T << "\n";
}