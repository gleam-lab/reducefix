#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define drep(i, n) for (int i = n - 1; i >= 0; --i)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);

    // Use a larger buffer size for input stream
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.rdbuf(new stringstream);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Early return for small cases
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp(n, 0); // i-th switch to flip

    dp[0] = a[0];
    dp[1] = dp[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 2] + 2 * a[i], dp[i - 1] + a[i]);
    }
    cout << dp[n - 1] << endl;

    return 0;
}