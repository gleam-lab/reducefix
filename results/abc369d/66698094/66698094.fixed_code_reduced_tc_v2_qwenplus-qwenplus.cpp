#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;

    // dp[i][0] = max sum selecting even number of elements ending at i
    // dp[i][1] = max sum selecting odd number of elements ending at i
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    dp[0][0] = dp[0][1] = 0;
    if (n >= 1) {
        dp[1][0] = 0; // Selecting 0 elements from first 1
        dp[1][1] = v[0]; // Selecting 1 element from first 1
    }

    for (int i = 1; i < n; ++i) {
        // If we don't take current element, carry forward previous max
        dp[i+1][0] = max(dp[i][0], dp[i][1]);
        // If we take current element:
        // - if previous was odd length, now becomes even with added element
        // - if previous was even and we start new sequence with taking this one (odd length)
        dp[i+1][1] = max(dp[i][0] + v[i], dp[i][1]);
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}