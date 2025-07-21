#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to determine number of attacks needed for one enemy
ll compute_attacks(int h) {
    // Each attack is either 1 or 3 damage depending on T % 3 == 0
    // We simulate until h <= 0
    
    ll t = 0;
    
    while (h > 0) {
        t++;
        if (t % 3 == 0) {
            h -= 3;
        } else {
            h -= 1;
        }
    }
    
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> H(n);
    rep(i, n) cin >> H[i];
    
    ll ans = 0;
    
    // Greedy approach:
    // For each enemy, we simulate attacks in order
    // But since this may be too slow for large N and large H[i],
    // we use a mathematical approach to calculate the number of steps needed per enemy.
    
    // Observation: For every 3 consecutive attacks:
    // - First two attacks do 1 point of damage
    // - Third attack does 3 points of damage
    // => Total of 5 damage over 3 turns

    // Let's precompute how many full cycles of 3 attacks we can perform
    // Then handle remaining health with brute-force

    rep(i, n) {
        ll h = H[i];

        // Full cycles of 3 attacks (each cycle deals 5 damage)
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h -= full_cycles * 5;

        // Remaining attacks
        while (h > 0) {
            ans++;
            if (ans % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }

    cout << ans << endl;
}