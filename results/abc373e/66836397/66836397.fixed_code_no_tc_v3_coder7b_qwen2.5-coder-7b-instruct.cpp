#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    ll sum_a = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }

    vector<ll> A = a;
    sort(A.begin(), A.end());

    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + A[i];
    }

    auto check = [&](ll i, ll x) {
        ll na = a[i] + x;
        ll r = upper_bound(A.begin(), A.end(), na) - A.begin();
        ll uppercnt = n - r;
        ll rem = K - sum_a - x;
        ll M = m - uppercnt;
        if (M <= 0) return false;
        ll l = max(0LL, r - M);
        ll len = r - l;
        ll cnt = (na + 1) * len - (ac[r] - ac[l]);
        if (rem >= cnt) return false;
        return true;
    };

    for (ll i = 0; i < n; ++i) {
        ll lo = 0, hi = K - sum_a;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (check(i, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (!check(i, lo)) cout << -1 << " ";
        else cout << lo << " ";
    }
    cout << endl;
    return 0;
}