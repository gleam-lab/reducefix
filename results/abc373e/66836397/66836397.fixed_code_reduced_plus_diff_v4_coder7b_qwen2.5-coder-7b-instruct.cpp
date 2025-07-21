#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        K -= a[i];
    }
    
    sort(a.begin(), a.end());

    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        ac[i + 1] = ac[i] + a[i];
    }

    auto f = [&](ll i, ll x) {
        ll na = a[i] + x;
        ll r = lower_bound(ac.begin(), ac.end(), na) - ac.begin();
        ll uppercnt = n - r;
        ll rem = K - x;
        ll M = m - uppercnt;
        if (M <= 0) return false;
        ll l = r - M;
        ll len = r - l;
        bool flag = a[l] <= a[i];
        if (flag) l--;
        ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
        return rem >= cnt;
    };

    vector<ll> ans(n);
    for (ll i = 0; i < n; i++) {
        ll ok = K, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = ok + (ng - ok) / 2;
            if (f(i, mid)) ok = mid;
            else ng = mid;
        }
        if (!f(i, ok)) ans[i] = -1;
        else ans[i] = ok;
    }

    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}