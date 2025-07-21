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

    vector<ll> A = a;
    sort(A.begin(), A.end());

    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + A[i];
    }

    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        ll na = a[i];
        ll r = upper_bound(A.begin(), A.end(), na) - A.begin();
        ll uppercnt = n - r;
        ll rem = K - na;
        ll M = m - uppercnt;
        if (M <= 0) {
            ans[i] = 0;
            continue;
        }
        ll l = r - M;
        ll len = r - l;
        bool flag = A[l] <= a[i];
        if (flag) l--;
        ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
        if (rem >= cnt) {
            ans[i] = 0;
        } else {
            ans[i] = (na + 1) * (uppercnt + 1) - ac[n] - rem;
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}