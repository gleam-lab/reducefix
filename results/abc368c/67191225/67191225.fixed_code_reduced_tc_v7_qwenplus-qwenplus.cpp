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
        // Number of attacks needed to reduce this enemy to 0 or less
        ll h = H[i];
        
        // We want to find how many total attacks (T) are needed considering:
        // - Every 3rd attack deals 3 damage (at time t where t % 3 == 0)
        // - Other attacks deal 1 damage

        // Let's simulate in blocks of 3 turns:
        // In every block of 3 turns, we get 2 attacks of 1 damage and 1 attack of 3 damage => total 5 damage
        // So: full_blocks = h / 5
        // remaining_damage = h % 5
        
        ll full_blocks = h / 5;
        ll rem = h % 5;

        T += full_blocks * 3;

        if (rem > 0) {
            // Need extra attacks depending on current T modulo 3
            ll t_mod = T % 3;
            if (t_mod == 0) {
                // Next attack is strong (×3)
                T += 1;
            } else if (t_mod == 1 || t_mod == 2) {
                // One or two weak attacks then a strong one
                T += (rem + 1) / 2;
            }
        }
    }

    std::cout << T << std::endl;
    return 0;
}