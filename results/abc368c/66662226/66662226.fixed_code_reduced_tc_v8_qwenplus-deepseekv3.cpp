#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        if (h == 0) continue;
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        ll t_increase = 0;
        if (remaining == 0) {
            t_increase = full_cycles * 3;
        } else {
            t_increase = full_cycles * 3;
            if (remaining <= 2) {
                t_increase += remaining;
            } else {
                t_increase += 3;
            }
        }
        ans += t_increase;
    }
    cout << ans << endl;
    return 0;
}