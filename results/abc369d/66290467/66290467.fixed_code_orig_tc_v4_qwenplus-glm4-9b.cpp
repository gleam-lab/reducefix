#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Corrected the rep macro definition
#define rep(i, n) for (int i = 0; i < n; ++i)
// Corrected the drep macro definition
#define drep(i, n) for (int i = n - 1; i >= 0; --i)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    // Early return for n == 1 and n == 2 cases
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp(n, 0); // dp[i] stores the maximum experience value up to warrior i

    dp[0] = a[0];
    dp[1] = dp[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        // Update dp[i] considering the maximum of two scenarios: either taking the i-th warrior directly or taking the i-th warrior after defeating the i-2 and i-1 warriors
        dp[i] = max(dp[i - 2] + 2 * a[i], dp[i - 1] + a[i]);
    }
    cout << dp[n - 1] << endl;

    return 0;
}