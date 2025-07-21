#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;
    
    if (n == 0) {
        cout << "0\n";
        return;
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[1][0] = v[0];
    dp[1][1] = v[0];
    
    for (int i = 1; i < n; ++i) {
        dp[i + 1][0] = max(dp[i][1] + 2 * v[i], dp[i][0]);
        dp[i + 1][1] = max(dp[i][0] + v[i], dp[i][1]);
    }
    
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    fast;
    int t = 1;
    while (t--)
        solve();
    return 0;
}