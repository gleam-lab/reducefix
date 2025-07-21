#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;

    // dynamic programming array with two states:
    // dp[i][0] - max sum up to i, without selecting v[i]
    // dp[i][1] - max sum up to i, selecting v[i]
    ll dp[n + 1][2];

    dp[0][0] = 0; // base case: no elements
    dp[0][1] = 0; // base case: no elements

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]); // not taking current element
        dp[i][1] = dp[i - 1][0] + v[i - 1];       // taking current element
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}