#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll t, ll h) {
    if (h == 0) return 0;
    
    // We want to compute how many attacks are needed starting from time T
    // Each attack at time T+1, T+2, ...
    // Damage: 3 if time % 3 == 0, else 1
    
    // Instead of simulating, we can group attacks in blocks.
    // Consider cycles of 3 consecutive attacks:
    //   Position in cycle: 
    //     If current T mod 3 = 0: next attacks at +1(+1), +2(+1), +3(+3) → total 5 over 3 attacks
    //     If T mod 3 = 1: next: +1(+3), +2(+1), +3(+1) → total 5
    //     If T mod 3 = 2: next: +1(+1), +2(+3), +3(+1) → total 5
    // So every 3 attacks do 5 damage, regardless of alignment.

    ll base_cycles = h / 5;
    ll remainder = h % 5;
    
    ll attacks = 3 * base_cycles;
    ll current_time = t + attacks;
    
    // Simulate the remaining damage (at most 4)
    while (remainder > 0) {
        current_time++;
        attacks++;
        if (current_time % 3 == 0) {
            remainder -= 3;
        } else {
            remainder--;
        }
    }
    
    return attacks;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    ll total_t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        ll needed = num_attack(total_t, h);
        total_t += needed;
    }
    
    cout << total_t << endl;
}