#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll T = 0;
    for (int i = 0; i < n; ++i) {
        ll remaining = h[i];
        if (i > 0) {
            remaining -= T / 3;
            if (remaining <= 0) continue;
        }
        // Now compute the required T increments to reduce remaining to <= 0
        // The attacks are: 1, 1, 3, 1, 1, 3, etc.
        // For each full cycle (3 attacks), total damage is 1 + 1 + 3 = 5.
        ll full_cycles = remaining / 5;
        T += full_cycles * 3;
        remaining -= full_cycles * 5;
        if (remaining > 0) {
            if (remaining <= 2) {
                T += remaining;
            } else {
                T += 3;
            }
        }
    }

    cout << T << endl;
    return 0;
}