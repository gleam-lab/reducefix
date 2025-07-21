#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll compute_damage(ll t) {
    ll full_cycles = t / 3;
    ll remainder = t % 3;
    ll damage = full_cycles * 5;
    if (remainder == 1) {
        damage += 1;
    } else if (remainder == 2) {
        damage += 2;
    }
    return damage;
}

ll find_min_attacks(ll h) {
    ll low = 0, high = 2 * h; // Upper bound is high enough
    while (low < high) {
        ll mid = (low + high) / 2;
        if (compute_damage(mid) >= h) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll total_attacks = 0;
    for (int i = 0; i < n; ++i) {
        ll required_attacks = find_min_attacks(h[i]);
        // The actual T when this enemy is defeated is total_attacks + required_attacks
        // But since we attack sequentially, we need to find the earliest T where for each enemy,
        // the damage up to T is >= h[i], considering the attacks are done in order.
        // So the total T is the maximum of the cumulative T required for each enemy.
        // However, the damage to enemy i depends on the attacks done before it, which is total_attacks.
        // So the T for enemy i is find_min_attacks(h[i]) + total_attacks?
        // No, because the damage pattern is based on the global T, not per enemy.
        // So we need to find T such that for each enemy i, the damage it receives by time T is >= h[i].
        // The damage to enemy i is the sum of attacks where T is in [prev_T + 1, prev_T + required_attacks_i].
        // This is complex, so perhaps a better approach is to simulate the process but efficiently.
        // Alternatively, recognize that the total damage to enemy i is compute_damage(total_attacks + required_attacks_i) - compute_damage(total_attacks) >= h[i].
        // So we need to find required_attacks_i such that this condition holds.
        // This is equivalent to compute_damage(total_attacks + required_attacks_i) >= compute_damage(total_attacks) + h[i].
        // So we can binary search for required_attacks_i in this context.
        ll low = 0, high = 2 * h[i];
        ll target = compute_damage(total_attacks) + h[i];
        while (low < high) {
            ll mid = (low + high) / 2;
            if (compute_damage(total_attacks + mid) >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        required_attacks = low;
        total_attacks += required_attacks;
    }

    cout << total_attacks << endl;
    return 0;
}