#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        // Calculate the number of full 3-attack cycles (each deals 5 damage)
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        
        // Each full cycle takes 3 attacks (time increments)
        t += 3 * full_cycles;
        h -= 5 * full_cycles;
        
        if (remaining > 0) {
            // Additional attacks needed for the remaining health
            // The first attack is at t+1, then t+2, etc.
            if (remaining <= (t % 3 == 0 ? 3 : 1)) {
                t += 1;
            } else if (remaining <= (t % 3 == 0 ? 3 : 1) + ( (t+1) % 3 == 0 ? 3 : 1 )) {
                t += 2;
            } else {
                t += 3;
            }
        }
    }

    cout << t << endl;
    return 0;
}