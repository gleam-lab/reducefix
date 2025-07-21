#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    long long dp0, dp1, x;
    dp0 = 0;
    dp1 = LLONG_MIN; // Use LLONG_MIN instead of -INF for minimum value initialization
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        dp1 = max(dp0 + 2 * x, dp1); // Update dp1 based on previous dp0 and current x
        dp0 = max(dp0, dp1); // Update dp0 with the maximum value between itself and dp1
    }

    cout << max(dp0, dp1) << endl; // Output the maximum of dp0 and dp1 as the result
    return 0;
}