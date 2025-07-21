#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) ac[i + 1] = ac[i] + a[i];

    auto f = [&](int i, ll x) {
        ll na = a[i] + x;
        ll r = lower_bound(a.begin(), a.end(), na) - a.begin();
        ll uppercnt = n - r;
        ll rem = k - accumulate(ac.begin(), ac.end(), 0ll) + x;
        ll M = m - uppercnt;
        if (M <= 0) return false;
        ll l = r - M;
        ll len = r - l;
        bool flag = a[l] <= a[i];
        if (flag) l--;
        ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
        return rem >= cnt;
    };

    for (ll i = 0; i < n; ++i) {
        ll ok = k - accumulate(ac.begin(), ac.end(), 0ll);
        ll ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (f(i, mid)) ok = mid;
            else ng = mid;
        }
        if (!f(i, ok)) cout << -1 << " ";
        else cout << ok << " ";
    }
    cout << endl;

    return 0;
}