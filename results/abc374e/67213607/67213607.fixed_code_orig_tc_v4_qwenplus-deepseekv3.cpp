#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x;
ll a[105], p[105], b[105], q[105];

bool isPossible(ll mid) {
    ll total = 0;
    for (int i = 1; i <= n; ++i) {
        ll min_cost = LLONG_MAX;
        // Check all possible j for method a (from 0 to some upper limit)
        ll max_j = min(mid / a[i] + 2, b[i] + 1); // Upper limit for j to avoid unnecessary checks
        for (ll j = 0; j <= max_j; ++j) {
            if (mid < j * a[i]) continue;
            ll remaining = mid - j * a[i];
            ll k = remaining / b[i];
            if (remaining % b[i] != 0) k++;
            if (k < 0) k = 0;
            ll cost = j * p[i] + k * q[i];
            if (cost < min_cost) min_cost = cost;
        }
        // Similarly, check all possible k for method b (from 0 to some upper limit)
        ll max_k = min(mid / b[i] + 2, a[i] + 1);
        for (ll k = 0; k <= max_k; ++k) {
            if (mid < k * b[i]) continue;
            ll remaining = mid - k * b[i];
            ll j = remaining / a[i];
            if (remaining % a[i] != 0) j++;
            if (j < 0) j = 0;
            ll cost = k * q[i] + j * p[i];
            if (cost < min_cost) min_cost = cost;
        }
        total += min_cost;
        if (total > x) return false;
    }
    return total <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    ll l = 0, r = 1e18, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (isPossible(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}