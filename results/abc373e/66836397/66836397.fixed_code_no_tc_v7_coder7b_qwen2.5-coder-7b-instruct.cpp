#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        K -= a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + a[i];
    }

    auto check = [&](ll i, ll x) {
        ll na = a[i] + x;
        ll r = lower_bound(a.begin(), a.end(), na) - a.begin();
        ll uppercnt = n - r;
        ll rem = K - x;
        ll M = m - uppercnt;
        if (M <= 0) return false;
        ll l = max(0LL, r - M);
        ll len = r - l;
        bool flag = a[l] <= a[i];
        if (flag) l--;
        ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
        return rem >= cnt;
    };

    for (ll i = 0; i < n; ++i) {
        if (a[i] >= K / (m - 1)) {
            cout << 0 << " ";
        } else {
            ll lo = 0, hi = K;
            while (lo < hi) {
                ll mid = lo + (hi - lo) / 2;
                if (check(i, mid)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            cout << lo << " ";
        }
    }
    cout << endl;

    return 0;
}