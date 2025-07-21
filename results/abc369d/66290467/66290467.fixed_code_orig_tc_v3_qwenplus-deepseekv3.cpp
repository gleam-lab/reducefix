#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (int(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp[i][0] = max experience when not taking i-th element
    // dp[i][1] = max experience when taking i-th element
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    
    dp[0][1] = a[0];
    if (n >= 2) {
        dp[1][0] = a[0];
        dp[1][1] = a[0] + 2 * a[1];
    }

    for (int i = 2; i < n; ++i) {
        // If we don't take current element, previous must be taken
        dp[i][0] = dp[i-1][1];
        
        // If we take current element, previous could be either taken or not
        dp[i][1] = max(dp[i-1][0] + 2 * a[i], dp[i-1][1] + a[i]);
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}