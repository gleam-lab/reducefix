#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;
    
    vector<ll> dp(2, 0);
    dp[1] = v[0];
    
    for (int i = 1; i < n; ++i) {
        dp = vector<ll>(2, 0);
        dp[0] = max(dp[0], dp[1] + v[i]);
        dp[1] = max(dp[1], dp[0] + 2LL * v[i]);
    }
    
    cout << max(dp[0], dp[1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}