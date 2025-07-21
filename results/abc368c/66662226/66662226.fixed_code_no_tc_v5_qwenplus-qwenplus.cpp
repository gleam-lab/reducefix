#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // We simulate the process with a priority queue
    // Each time we attack, we only attack the first enemy with health > 0
    // Once an enemy's health drops to 0 or less, we move past it

    // Instead of simulating each T step-by-step (which is O(T), up to ~1e14 steps),
    // we calculate how many full cycles of attacks are needed on current front enemy.

    int idx = 0;
    while (idx < n) {
        // Skip enemies already defeated
        if (H[idx] <= 0) {
            idx++;
            continue;
        }

        // For current enemy H[idx], determine how many attacks are needed
        // Each 3 attacks reduce health by 5 (if using optimal attacks: one at t%3==0 and two at t%3!=0)

        // Let's find how many full 3-attack cycles we can do
        ll full_cycles = H[idx] / 5;
        if (full_cycles > 0) {
            T += full_cycles * 3;
            H[idx] -= full_cycles * 5;
        }

        // Finish remaining health (<= 4) with individual attacks
        while (H[idx] > 0) {
            T++;
            if (T % 3 == 0) {
                H[idx] -= 3;
            } else {
                H[idx]--;
            }
        }

        // Move to next enemy
        idx++;
    }

    cout << T << endl;
}