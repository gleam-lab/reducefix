#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<ll> H(N);
    rep(i, N) cin >> H[i];

    ll T = 0;

    rep(i, N) {
        ll h = H[i];
        if (h <= 0) continue;

        // Full cycles of 3 attacks: each cycle gives 5 damage
        ll full_cycles = h / 5;
        ll rem_health = h % 5;

        if (full_cycles > 0) {
            T += full_cycles * 3;
        }

        // Remaining health after full cycles
        if (rem_health > 0) {
            // Now simulate up to 3 more attacks
            // Each attack is applied at T+1, T+2, T+3 etc.
            // Depending on whether T+attack_num is divisible by 3

            // Let's check how many actual attacks are needed
            // Start from current T+1 and apply attacks until health becomes 0 or less
            ll attack_count = 0;
            while (rem_health > 0) {
                T++;
                attack_count++;
                if (T % 3 == 0) rem_health -= 3;
                else rem_health -= 1;
            }
        }
    }

    cout << T << endl;
}