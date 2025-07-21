#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    vector<ll> dp(3, 0);
    dp[1] = v[0];
    for (int i = 1; i < n; ++i) {
        dp[2] = max(dp[0] + v[i], dp[1] + 2 * v[i]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    
    cout << max(dp[0], dp[1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}