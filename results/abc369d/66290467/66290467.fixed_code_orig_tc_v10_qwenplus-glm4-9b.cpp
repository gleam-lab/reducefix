#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> dp(n, 0);

    // Initial conditions
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    dp[0] = a[0];
    dp[1] = dp[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        // Calculate the maximum score for the current position
        dp[i] = max(dp[i - 2] + 2 * a[i], dp[i - 1] + a[i]);
    }

    cout << dp[n - 1] << endl;
    return 0;
}