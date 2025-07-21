#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll dp[2][n + 1];
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    dp[0][0] = dp[1][0] = 0;
    dp[0][1] = dp[1][1] = v[0];
    for (int i = 1; i < n; ++i) {
        dp[0][i + 1] = max(dp[0][i], dp[1][i] + 2LL * v[i]);
        dp[1][i + 1] = max(dp[1][i], dp[0][i] + v[i]);
    }
    ll maxSum = max(dp[0][n], dp[1][n]);
    cout << maxSum << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}