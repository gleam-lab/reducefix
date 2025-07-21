#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll ans = 0;
    for (ll health : h) {
        ll q = health / 5;
        ll r = health % 5;
        ans += q * 3;
        if (r > 0) {
            if (r >= 3) ans += 3;
            else ans += r;
        }
    }

    cout << ans << "\n";
}