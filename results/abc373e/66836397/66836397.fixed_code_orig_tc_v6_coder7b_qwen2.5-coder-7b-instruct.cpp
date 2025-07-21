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
    }
    sort(a.begin(), a.end());

    vector<ll> A = a;
    reverse(A.begin(), A.end());
    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + A[i];
    }

    auto f = [&](int i, ll x) {
        ll na = a[i] + x;
        ll r = lower_bound(A.begin(), A.end(), na) - A.begin();
        ll uppercnt = n - r;
        ll rem = K - x;
        ll M = m - uppercnt;
        if (M <= 0) return false;
        ll l = r - M;
        ll len = r - l;
        bool flag = A[l] <= a[i];
        if (flag) --l;
        ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
        return rem >= cnt;
    };

    vector<ll> result(n);
    for (int i = 0; i < n; ++i) {
        ll ok = K, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (f(i, mid)) ok = mid;
            else ng = mid;
        }
        if (!f(i, ok)) result[i] = -1;
        else result[i] = ok;
    }

    for (ll x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}