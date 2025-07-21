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

    ll total_attacks = 0;
    for (int i = 0; i < n; ++i) {
        ll hi = h[i];
        // Calculate the number of full cycles (each cycle is 3 attacks dealing 5 damage)
        ll full_cycles = hi / 5;
        ll remaining_health = hi % 5;

        ll attacks_for_hi = 3 * full_cycles;
        if (remaining_health > 0) {
            if (remaining_health <= (3 - (total_attacks % 3)) % 3 + 1) {
                attacks_for_hi += 1;
            } else {
                attacks_for_hi += 2;
            }
        }
        total_attacks += attacks_for_hi;
    }

    cout << total_attacks << endl;
    return 0;
}