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
        ll hi = h[i];
        ll full_cycles = hi / 5;
        ans += full_cycles * 3;
        hi -= full_cycles * 5;
        while (hi > 0) {
            ans++;
            if (ans % 3 == 0) {
                hi -= 3;
            } else {
                hi -= 1;
            }
        }
    }
    cout << ans << endl;
}