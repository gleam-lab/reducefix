#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (ll(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    vector<ll> dp1(n), dp2(n);
    dp1[0] = a[0];
    dp2[0] = 0;
    dp1[1] = a[1];
    dp2[1] = a[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        dp1[i] = max(dp1[i - 1], dp2[i - 1]) + a[i];
        dp2[i] = max(dp1[i - 1] + 2 * a[i], dp2[i - 1] + a[i]);
    }

    cout << max(dp1.back(), dp2.back()) << endl;

    return 0;
}