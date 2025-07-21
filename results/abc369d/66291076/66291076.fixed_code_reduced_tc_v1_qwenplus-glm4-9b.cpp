#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp[0] is the maximum value when the last operation was even
    // dp[1] is the maximum value when the last operation was odd
    vector<ll> dp(2, 0);
    dp[0] = a[0] * 2;
    dp[1] = a[0] + a[1];

    rep(i, 2, n) {
        ll nextEven = max(dp[0] + a[i], dp[1] + a[i] * 2);
        ll nextOdd = max(dp[0] + a[i] * 2, dp[1] + a[i]);
        dp[0] = nextEven;
        dp[1] = nextOdd;
    }

    cout << max(dp[0], dp[1]) << endl;

    return 0;
}