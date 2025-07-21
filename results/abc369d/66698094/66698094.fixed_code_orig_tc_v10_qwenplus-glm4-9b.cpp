#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// freopen("equal.in", "r", stdin); freopen("output.txt", "w", stdout);
const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll dp[n + 1][2];
    for (ll &x : v)
        cin >> x;
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = dp[i][1] = -1;
    }
    dp[0][0] = dp[0][1] = 0;
    dp[1][1] = v[0];
    dp[1][0] = v[0];
    for (int i = 1; i < n; ++i) {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + v[i]); // Take current element in first child's subsequence
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + v[i]); // Take current element in second child's subsequence
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 2 * v[i]); // Take current element in both subsequences
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}