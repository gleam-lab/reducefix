#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll remaining = h[i];
        // Calculate the number of full cycles (3 attacks) that deal 5 damage
        ll full_cycles = remaining / 5;
        t += 3 * full_cycles;
        remaining -= 5 * full_cycles;
        
        // Handle remaining health
        while (remaining > 0) {
            t++;
            if (t % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    
    cout << t << endl;
    return 0;
}