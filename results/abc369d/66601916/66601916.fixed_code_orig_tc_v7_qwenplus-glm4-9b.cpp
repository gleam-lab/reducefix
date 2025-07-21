#include <iostream>
#include <algorithm>  // For std::max

using namespace std;

int main() {
    int n;
    long long dp0, dp1, x;
    dp0 = 0; // No profit at the start
    dp1 = -INF; // Initialize with a very small number

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        long long new_dp0 = max(dp0, dp1 + 2 * x); // Update dp0
        dp1 = max(dp1, dp0 + x); // Update dp1
        dp0 = new_dp0;
    }

    cout << max(dp0, dp1) << endl; // The result is the maximum of dp0 and dp1
    return 0;
}