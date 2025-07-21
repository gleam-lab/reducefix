#include <iostream>
#include <vector>

using ll = long long;

int main() {
    int N;
    std::cin >> N;
    std::vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    ll T = 0; // Total time

    for (ll h : H) {
        // We simulate the attack until current enemy's health <= 0
        // Each attack happens at time T + 1, T + 2, ...
        ll attacks = 0;
        ll low = 0, high = 2 * h; // generous upper bound

        // Binary search to find minimum number of attacks needed
        while (low < high) {
            ll mid = (low + high) / 2;
            ll damage = 0;
            for (ll i = 0; i < mid; ++i) {
                ll curr_time = T + i + 1; // simulate future time
                if (curr_time % 3 == 0)
                    damage += 3;
                else
                    damage += 1;
            }
            if (damage >= h)
                high = mid;
            else
                low = mid + 1;
        }

        // Apply the found number of attacks
        for (ll i = 0; i < low; ++i) {
            T++;
            if (T % 3 == 0)
                h -= 3;
            else
                h -= 1;
        }
    }

    std::cout << T << std::endl;
}