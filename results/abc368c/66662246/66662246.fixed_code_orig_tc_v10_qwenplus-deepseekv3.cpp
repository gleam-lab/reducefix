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
        if (h[i] <= 0) continue;
        ll full_cycles = h[i] / 5;
        ans += full_cycles * 3;
        h[i] -= full_cycles * 5;
        while (h[i] > 0) {
            ans++;
            if (ans % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i] -= 1;
            }
        }
    }
    cout << ans << endl;
}