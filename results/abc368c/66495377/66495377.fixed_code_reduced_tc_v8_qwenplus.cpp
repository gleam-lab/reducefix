#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll t, ll h) {
    if (h == 0) return 0;
    
    // We want to find the minimum number of attacks needed starting from time T
    // Each attack at time T+1, T+2, ... 
    // Damage: 3 if (T+k) % 3 == 0, else 1
    
    // Let’s model this: over a block of 3 consecutive attacks:
    // - Two attacks do 1 damage each
    // - One attack does 3 damage
    // So total damage per 3 attacks = 5
    
    ll attacks = 0;
    ll remaining = h;
    
    // Full cycles of 3 attacks give 5 damage
    ll full_cycles = remaining / 5;
    attacks += full_cycles * 3;
    remaining -= full_cycles * 5;
    
    // Simulate the remaining part
    while (remaining > 0) {
        attacks++;
        if ((t + attacks) % 3 == 0) {
            remaining -= 3;
        } else {
            remaining -= 1;
        }
    }
    
    return attacks;
}

int main() {
    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        ll needed = num_attack(t, h);
        t += needed;
    }

    cout << t << endl;
}