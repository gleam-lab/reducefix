#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> ac(n + 1);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + a[i];
    }

    vector<ll> ans(n, -1);

    for (ll i = 0; i < n; ++i) {
        ll na = a[i];
        ll r = lower_bound(a.begin(), a.end(), na + 1) - a.begin();
        ll uppercnt = n - r;

        if (uppercnt >= m) continue;

        ll rem = k - ac[n];

        ll l = r - m;
        if (l < 0) l = 0;

        ll cnt = na * (r - l) - (ac[r] - ac[l]);

        if (rem >= cnt) {
            ans[i] = 0;
        } else {
            ll x = (cnt - rem + na - 1) / na;
            ans[i] = max(x, 0LL);
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i + 1 == n];
    }

    return 0;
}