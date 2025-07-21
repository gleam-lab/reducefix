#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; i++) {
        cin >> H[i];
    }

    ll T = 0;
    for (ll i = 0; i < n; i++) {
        ll h = H[i];
        // Calculate full cycles (3 attacks per cycle, 5 damage per cycle)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h -= full_cycles * 5;

        // Handle remaining health
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}