#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

int main() {
    int N;
    std::cin >> N;
    std::vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < N; ++i) {
        // Calculate how many total attacks needed for this enemy
        ll attacks_needed = (H[i] + 1) / 2;

        // Calculate how many of those should be triple attacks (every 3rd attack)
        // Triple attacks contribute more, so we want to schedule them optimally
        // Let x be the number of triple attacks, and y be the number of single attacks
        // We need: x + y >= attacks_needed and 3x + y >= H[i]
        // We minimize T such that it aligns with the rules

        ll low = 0, high = attacks_needed;
        ll best = attacks_needed;
        
        // Binary search on number of triple attacks
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll damage = 3 * mid + (attacks_needed - mid);
            if (damage >= H[i]) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ll triple_attacks = best;
        ll total_attacks = attacks_needed;

        // Now we need to determine when these attacks would occur
        // We simulate the timing of attacks on current enemy
        // Each attack happens at T+1, T+2, ...

        // We'll track when each triple attack (t ≡ 0 mod 3) can happen
        ll remaining_triple = triple_attacks;
        ll current_T = T;

        // The next triple attack can happen at:
        // find first T' >= current_T where T' % 3 == 0
        ll next_triple = ((current_T + 2) / 3) * 3;

        while (remaining_triple > 0 && next_triple <= current_T + total_attacks) {
            // We can do a triple attack at next_triple
            ++current_T;
            remaining_triple--;
            next_triple += 3;
        }

        // Remaining attacks are all single
        current_T += remaining_triple;

        T = current_T;
    }

    std::cout << T << std::endl;
    return 0;
}