#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll midpoint(ll a, ll b) {
    return (a + b) / 2;
}

bool can_win(vector<ll>& a, ll i, ll k, ll m) {
    ll na = a[i];
    ll r = upper_bound(begin(a), end(a), na) - begin(a);
    ll upper_cnt = a.size() - r;
    ll rem = k - accumulate(begin(a), end(a), 0ll) + na;
    ll M = m - upper_cnt;
    if (M <= 0) return false;
    ll l = max(0ll, r - M);
    ll len = r - l;
    bool flag = a[l] <= na;
    if (flag) --l;
    ll cnt = (na + 1) * len - (accumulate(begin(a) + l + 1, begin(a) + r, 0ll) - (flag ? na : 0));
    return rem >= cnt;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(begin(a), end(a));
    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + a[i];
    }
    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        ll lo = 0, hi = k - sum;
        while (lo < hi) {
            ll mid = midpoint(lo, hi);
            if (can_win(a, i, mid, m)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        ans[i] = lo;
        if (!can_win(a, i, lo, m)) ans[i] = -1;
    }
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}