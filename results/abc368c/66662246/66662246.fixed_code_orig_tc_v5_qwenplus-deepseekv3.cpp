#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n) {
        ll h = a[i];
        ll x = h / 5;
        ll rem = h % 5;
        ans += x * 3;
        if (rem > 0) {
            if (rem <= 3) {
                ans += (rem == 3 ? 2 : rem);
            } else {
                ans += 3;
            }
        }
    }
    cout << ans << endl;
}