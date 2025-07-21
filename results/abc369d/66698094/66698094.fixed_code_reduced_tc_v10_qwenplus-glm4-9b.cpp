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
    for (ll &x : v)
        cin >> x;

    vector<ll> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = min(v[0], 2LL * v[0]);

    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], (dp[i - 2] + min(v[i], 2LL * v[i])));
    }

    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}