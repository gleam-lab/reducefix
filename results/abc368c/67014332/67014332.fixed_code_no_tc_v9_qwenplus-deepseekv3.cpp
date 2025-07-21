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

    ll ans = 0;
    ll tri_phase = 0; // T mod 3, but tracks the phase for the current attack

    for (ll i = 0; i < n; i++) {
        ll h = H[i];
        // The number of full cycles (3 attacks: 1, 1, 3)
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h %= 5;

        // Now handle the remaining health with the current attack sequence
        while (h > 0) {
            ans++;
            if ((ans) % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}