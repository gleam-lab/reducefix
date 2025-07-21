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
        if (h <= 0) continue;
        // The attacks for this enemy start at T+1 to T+k.
        // We need to find k such that sum of damages >= h.
        // The damage pattern is 1,1,3,1,1,3,...
        // Damage per 3 attacks is 5 (1+1+3).
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        T += full_cycles * 3;
        remaining += full_cycles * 0; // Adjust if needed, but full_cycles*3 steps already considered.

        if (remaining > 0) {
            if (remaining <= 1) {
                T += 1;
            } else if (remaining <= 2) {
                T += 2;
            } else {
                T += 3;
            }
        }
    }

    cout << T << endl;
    return 0;
}