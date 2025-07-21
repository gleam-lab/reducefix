#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;
    // We will simulate the process efficiently without actually looping per attack

    // Each enemy must be attacked until its health is <= 0
    // For each enemy, determine how many attacks it needs:
    // - At time t ≡ 0 mod 3: damage is 3
    // - At other times: damage is 1
    // We want to find the minimal sequence of attacks to reduce H[i] to <= 0

    // The idea is to calculate how many triple-attacks (t % 3 == 0) and single attacks are needed
    // Let x be number of triple attacks (damage 3*x)
    // Let y be number of single attacks (damage 1*y)
    // Total damage = 3*x + y >= H[i]
    // And total attacks used = 3*x + y (since triple attacks only happen at multiples of 3)
    // But we must interleave these so that triple attacks occur at correct times

    // Observation:
    // Every 3 attacks, one can be a triple attack (at T+3), and two are single attacks.
    // So in every group of 3 attacks, we can do 1 triple attack (3 damage) and 2 single attacks (1 damage each)

    // So for health h, we need to determine how many such full groups of attacks are needed,
    // and then handle remaining attacks.

    // Binary search on T: what's the minimum T where all enemies can be defeated?

    auto is_enough = [&](ll t) {
        ll total_attacks = 0;
        rep(i, n) {
            ll h = H[i];
            // In t seconds, how much damage can we do?
            // There are floor(t / 3) triple attacks available
            // And (t - floor(t / 3)) single attacks
            ll tri = t / 3;
            ll sin = t - tri;

            // Let’s say we use x triple attacks and y single attacks on this enemy
            // x <= tri, y <= sin
            // x * 3 + y >= H[i]

            // We maximize x first (use as many triple attacks as possible)
            ll max_damage = min(tri, h / 3) * 3;
            h -= max_damage;
            tri -= min(tri, h / 3);
            if (h > 0) {
                ll rem = min(sin, h);
                h -= rem;
                sin -= rem;
            }
            if (h > 0) return false;
        }
        return true;
    };

    // Binary search T from lower bound to upper bound
    ll low = 0, high = 2e18;
    while (low < high) {
        ll mid = (low + high) / 2;
        if (is_enough(mid)) high = mid;
        else low = mid + 1;
    }

    cout << low << endl;
}