#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to compute the minimum T needed to defeat one enemy
ll computeT(int h) {
    // We want to find the minimum number of attacks needed to reduce health to 0 or less.
    // Let's denote:
    // - x: number of times we use a triple attack (at T divisible by 3)
    // - y: number of single attacks at other times
    // Each triple attack costs 3 time units and reduces health by 3
    // Each single attack costs 1 time unit and reduces health by 1
    // So total damage is 3*x + y >= h
    // Total time is 3*x + y
    // Our goal is to minimize 3*x + y subject to 3*x + y >= h

    // For each possible x (number of triple attacks), calculate minimal y needed
    // Since we can do at most one triple attack every 3 turns, the number of triple attacks <= ceil(h / 3)
    // But we try only a few candidates around optimal value

    ll low_x = max(0LL, (ll)(h / 3) - 2);
    ll best = LLONG_MAX;
    
    for (ll x = low_x; x <= (h + 2) / 3 && x <= h; ++x) {
        if (x < 0) continue;
        ll remaining = max(0LL, h - 3 * x);
        ll y = remaining;
        ll total_time = 3 * x + y;
        best = min(best, total_time);
    }
    
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> H(n);
    rep(i, n) cin >> H[i];

    ll total_time = 0;

    // We simulate the process from left to right
    // When attacking, sometimes we have to delay triple attacks to maximize their number
    // This problem can be transformed into determining how many triple attacks we can perform,
    // and when they should happen to maximize efficiency

    // Let's consider the following: each enemy needs some number of triple attacks and single attacks
    // We need to schedule these attacks in a way that triple attacks happen at multiples of 3
    // So we simulate the timeline and track when triple attacks can happen

    // Instead of simulating step-by-step (which would be too slow),
    // we can compute how many triple attacks are possible up to each position

    // We binary search on the final answer T
    // For a given T, we can compute how many triple attacks are possible before each enemy
    // and check if it's enough to kill all enemies

    ll low = 0, high = 3 * 1000000000LL;
    while (low < high) {
        ll mid = (low + high) / 2;

        // For time T=mid, compute how much damage we can deal to each enemy
        // The first enemy gets the first attacks, then second, etc.
        bool ok = true;
        vector<ll> h_copy = H;
        ll t = 0;

        // For each enemy
        for (int i = 0; i < n && ok; ++i) {
            ll triple_attacks_possible = (mid - t + 2) / 3; // How many triple attacks can happen starting at time t
            ll attack_count = min(triple_attacks_possible, (ll)(mid - t));
            
            // Compute total damage to this enemy: attack_count triple attacks + (attack_count - triple_attacks_possible) single attacks
            // Wait, better approach: simulate attacks until enemy dies or we run out of time
            ll l = 0, r = mid - t;
            while (l < r) {
                ll m = (l + r) / 2;
                ll triple = m / 3 + (t % 3 == 0 ? (m % 3 > 0) : (m % 3 > 2 - t % 3));
                ll damage = triple * 3 + (m - triple);
                if (damage >= h_copy[i])
                    r = m;
                else
                    l = m + 1;
            }

            if (l == mid - t)
                ok = false; // Not enough time to kill this enemy
            else
                t += l + 1;
        }

        if (ok)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << endl;
}