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
    for (int i = 0; i < n; ++i) {
        ll hi = h[i];
        if (hi == 0) continue;
        ll cycles = hi / 5;
        ans += cycles * 3;
        hi -= cycles * 5;
        if (hi > 0) {
            if (hi <= 1) {
                ans += 1;
            } else if (hi <= 3) {
                ans += 2;
            } else {
                ans += 3;
            }
        }
    }
    cout << ans << endl;
    return 0;
}