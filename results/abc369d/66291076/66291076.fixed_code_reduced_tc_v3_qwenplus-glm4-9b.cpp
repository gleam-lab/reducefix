#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    } else if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp(n, 0);
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[0] + 2 * a[1];

    for (ll i = 3; i < n; ++i) {
        dp[i] = max(dp[i - 2] + 2 * a[i], dp[i - 1] + a[i]);
    }

    cout << max(dp[n - 1], dp[n - 2]) << endl;

    return 0;
}