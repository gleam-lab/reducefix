#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp_odd[i]: 最も右が奇数回攻撃された状態での最大値
    // dp_even[i]: 最も右が偶数回攻撃された状態での最大値
    vector<ll> dp_odd(n, 0), dp_even(n, 0);

    dp_odd[0] = a[0];
    dp_even[0] = 0;

    for (int i = 1; i < n; ++i) {
        dp_odd[i] = dp_even[i - 1] + a[i];
        dp_even[i] = max(dp_odd[i - 1], dp_even[i - 1]) + 2 * a[i];
    }

    cout << max(dp_odd[n - 1], dp_even[n - 1]) << endl;

    return 0;
}