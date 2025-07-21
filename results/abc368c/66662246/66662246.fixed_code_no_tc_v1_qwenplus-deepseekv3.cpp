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
        ll cycles = h[i] / 5;
        ans += cycles * 3;
        h[i] -= cycles * 5;
        while (h[i] > 0) {
            ans++;
            if (ans % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i]--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}