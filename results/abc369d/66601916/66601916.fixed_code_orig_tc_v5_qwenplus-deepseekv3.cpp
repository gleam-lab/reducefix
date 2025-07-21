#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define INF LONG_LONG_MIN

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> dp(n + 2, 0);
    dp[0] = 0;
    dp[1] = a[0];
    if (n >= 2) {
        dp[2] = max(a[0], a[1]);
    }
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + a[i - 1], dp[i - 3] + a[i - 1]));
    }

    cout << dp[n] << endl;
    return 0;
}