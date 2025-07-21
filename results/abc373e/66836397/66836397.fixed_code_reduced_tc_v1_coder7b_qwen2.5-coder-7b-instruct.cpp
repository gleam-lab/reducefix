#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll midpoint(ll a, ll b) {
    return (a + b) / 2;
}

bool can_win(vector<ll>& a, ll k, ll m, ll i, ll x) {
    a[i] += x;
    sort(a.begin(), a.end());
    ll upper_cnt = 0;
    for (ll j = a.size() - 1; j >= 0 && a[j] > a[i]; --j) {
        ++upper_cnt;
    }
    ll rem = k - accumulate(a.begin(), a.end(), 0LL) + x;
    ll M = m - upper_cnt;
    if (M <= 0) return false;
    ll l = a.size() - upper_cnt - M;
    ll len = upper_cnt - l;
    bool flag = a[l] <= a[i];
    if (flag) --l;
    ll cnt = (a[i] + 1) * len - (accumulate(a.begin() + l + 1, a.end(), 0LL) - (flag ? a[i] : 0));
    return rem >= cnt;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> ans(n, -1);
    for (ll i = 0; i < n; ++i) {
        ll rem = k - accumulate(a.begin(), a.end(), 0LL);
        if (rem == 0) {
            ans[i] = 0;
            continue;
        }
        ll left = 0, right = rem;
        while (left < right) {
            ll mid = midpoint(left, right);
            if (can_win(a, k, m, i, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans[i] = left;
    }
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}