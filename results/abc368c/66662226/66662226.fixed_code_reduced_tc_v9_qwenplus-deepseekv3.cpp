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
    for (ll h : H) {
        // Calculate full cycles (each cycle is 3 steps dealing 5 damage)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        ll remaining = h % 5;
        if (remaining == 0) continue;
        // Simulate remaining steps
        ll t_mod = T % 3;
        if (remaining <= 1 + t_mod) {
            T += remaining;
        } else {
            if (t_mod == 2) {
                T += 1 + (remaining - 1 + 2) / 3;
            } else {
                T += (remaining - t_mod - 1 + 2) / 3 * 3 + t_mod + 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}