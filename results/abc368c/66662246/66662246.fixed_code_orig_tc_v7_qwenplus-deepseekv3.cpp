#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    ll ans = 0;
    rep(i, n) {
        ll t = ans;
        ll hi = h[i];
        // The attacks on this enemy are from t+1 to t + a, where a is the number of attacks needed.
        // Each attack at t+1, t+2, ..., t+a.
        // The damage is 1 if (t + k) % 3 != 0, else 3.
        // We need to find the smallest a such that sum_{k=1 to a} damage_k >= hi.
        // The damage for the k-th attack (relative to t) is (t + k) % 3 == 0 ? 3 : 1.
        // Which is equivalent to (k) % 3 == (3 - t % 3) % 3 ? 3 : 1.
        // So the sequence of damages is periodic with period 3.
        // We can compute the sum over full cycles and then the remainder.
        ll full_cycles = hi / (5); // Because each full cycle of 3 attacks contributes 5 damage (1 + 1 + 3).
        ll sum_full = full_cycles * 5;
        ll remaining = hi - sum_full;
        ll a = full_cycles * 3;
        t += a;
        while (remaining > 0) {
            t++;
            if (t % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
            a++;
        }
        ans = t;
    }
    cout << ans << endl;
    return 0;
}