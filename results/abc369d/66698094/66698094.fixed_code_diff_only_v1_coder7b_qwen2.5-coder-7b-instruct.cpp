#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll dp[n + 1][2];
    for (ll &x : v)
        cin >> x;
    memset(dp, 0, sizeof(dp));
    dp[1][0] = v[0]; // Only one element can be chosen initially if we choose the first element
    dp[1][1] = 0;   // No elements chosen initially
    for (int i = 1; i < n; ++i) {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + v[i]); // Choose current element and add to previous non-adjacent sum
        dp[i + 1][1] = max(dp[i + 1][1], max(dp[i][0], dp[i][1])); // Skip current element and take maximum of previous choices
    }
    cout << max(dp[n][0], dp[n][1]) << '\n'; // Result is the maximum of choosing or not choosing the last element
}

int main() {
    fast;
    int t = 1;
    while (t--) solve();
    return 0;
}