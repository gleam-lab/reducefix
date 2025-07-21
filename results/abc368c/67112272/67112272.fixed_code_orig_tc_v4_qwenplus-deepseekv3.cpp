#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    rep(i, n) {
        if (i < n - 1) {
            ll cycles = h[i] / 5;
            ans += cycles * 3;
            h[i] %= 5;
            h[i + 1] = max(0LL, h[i + 1] - cycles * 2);
        }
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