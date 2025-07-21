#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    
    ll dp[2] = {0}; // dp[0] for letting go, dp[1] for defeating
    
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 2 == 0) { // Even-indexed
            dp[1] = max(dp[1], dp[0] + 2 * a[i]);
        } else { // Odd-indexed
            dp[1] = max(dp[1], dp[0] + a[i]);
        }
        dp[0] = max(dp[0], dp[1]);
    }
    
    cout << max(dp[0], dp[1]) << '\n';
    return 0;
}