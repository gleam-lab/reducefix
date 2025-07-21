#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (ll(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp_prev_prev(n, 0);
    vector<ll> dp_prev(n, 0);
    vector<ll> dp_current(n, 0);

    dp_prev_prev[0] = a[0];
    dp_prev[0] = a[0];
    dp_prev[1] = max(a[0] + 2 * a[1], a[1]);

    for (int i = 2; i < n; ++i) {
        dp_current[i] = max(
            dp_prev_prev[i - 2] + 2 * a[i],
            dp_prev[i - 1] + a[i]
        );
        dp_prev_prev[i - 1] = dp_prev[i - 1];
        dp_prev[i] = dp_current[i];
    }

    cout << dp_prev[n - 1] << endl;

    return 0;
}