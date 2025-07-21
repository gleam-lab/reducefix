#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18  // Fix: Was too small, caused incorrect min values

int main() {
    int n;
    long long dp0 = 0;           // dp0: max profit with no stock held
    long long dp1 = -1e18;       // dp1: max profit with stock held
    long long x;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;

        // Hold temp value of dp0 before updating
        long long prev_dp0 = dp0;

        // Update dp0: either do nothing (keep dp0), or sell the stock (dp1 + price)
        dp0 = max(dp0, dp1 + x);

        // Update dp1: either do nothing (keep dp1), or buy the stock (prev_dp0 - price)
        dp1 = max(dp1, prev_dp0 - x);
    }

    // The maximum profit is when we don't hold any stock
    cout << dp0 << endl;

    return 0;
}