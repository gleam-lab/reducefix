#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    for (ll hi : h) {
        ll cycles = hi / 5;
        ll remainder = hi % 5;
        ll attacks = 0;

        if (remainder == 0) {
            attacks = cycles * 3;
        } else if (remainder <= 2) {
            attacks = cycles * 3 + remainder;
        } else {
            attacks = cycles * 3 + 3;
        }

        ans += attacks;
    }

    cout << ans << endl;
    return 0;
}