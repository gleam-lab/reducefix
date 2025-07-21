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
    ll dp[2][2];  // Use 2x2 array instead of 2x(n+1) to save space.

    for (int &x : v)
        cin >> x;

    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = dp[1][1] = v[0];

    for (int i = 1; i < n; ++i) {
        dp[i % 2][0] = max(dp[(i - 1) % 2][1] + 2 * v[i], dp[(i - 1) % 2][0] + v[i]);
        dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + v[i]);
    }

    cout << max(dp[(n - 1) % 2][0], dp[(n - 1) % 2][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}