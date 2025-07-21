#include <iostream>
#include <algorithm>

using namespace std;

#define INF (long long)1e1+8

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        // Update dp1 first to ensure it holds the maximum value from the previous iteration
        dp1 = max(dp1, dp0 + x);
        // Then update dp0 using the maximum value from the previous iteration
        dp0 = max(dp1 + 2 * x, dp0);
    }

    // The final answer is the maximum of dp0 and dp1
    cout << max(dp0, dp1) << endl;
    return 0;
}