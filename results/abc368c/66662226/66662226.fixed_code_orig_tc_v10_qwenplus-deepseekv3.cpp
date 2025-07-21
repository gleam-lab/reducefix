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
        if (i < n - 1) {
            ll t3 = h[i] / 3;
            if (t3 > 0) {
                ll used = t3 * 3;
                h[i] -= used;
                h[i + 1] -= t3;
                ans += t3 * 2;
            }
        }
        while (h[i] > 0) {
            ans++;
            if (ans % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i] -= 1;
            }
            if (i < n - 1 && h[i + 1] > 0 && ans % 3 == 0) {
                h[i + 1] -= 1;
            }
        }
    }
    cout << ans << endl;
}