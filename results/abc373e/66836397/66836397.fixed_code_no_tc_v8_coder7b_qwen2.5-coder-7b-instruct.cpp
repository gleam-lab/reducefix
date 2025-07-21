#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll midpoint(ll a, ll b) {
    return (a + b) / 2;
}

bool can_win(vector<ll>& a, ll i, ll k, ll m, ll x) {
    ll na = a[i] + x;
    ll r = lower_bound(a.begin(), a.end(), na) - a.begin();
    ll upper_cnt = a.size() - r;
    ll rem = k - x;
    ll M = m - upper_cnt;
    if (M <= 0) return false;
    ll l = max(0LL, (ll)r - M);
    ll len = r - l;
    bool flag = a[l] <= a[i];
    if (flag) l--;
    ll cnt = (na + 1) * len - (a[r] - a[l] - (flag ? a[i] : 0));
    return rem >= cnt;
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        K -= a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> result(n);
    for (int i = 0; i < n; i++) {
        ll ok = K, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = midpoint(ok, ng);
            if (can_win(a, i, K, m, mid)) ok = mid;
            else ng = mid;
        }
        if (!can_win(a, i, K, m, ok)) result[i] = -1;
        else result[i] = ok;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " \n"[i + 1 == n];
    }

    return 0;
}