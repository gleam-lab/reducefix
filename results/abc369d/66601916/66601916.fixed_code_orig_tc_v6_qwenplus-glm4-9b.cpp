#include <iostream>
#include <algorithm>

using namespace std;

#define INF (long long)1e18

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF, temp;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;

        // Update dp1 and dp0 according to the recurrence relation
        temp = dp1; // Temporary store the previous dp1
        dp1 = max(dp0 + 2 * x, dp1); // Update dp1 for the current x
        dp0 = temp + x; // Update dp0 using the previous dp1
    }

    // Since we have the values of dp0 and dp1 for the last x, the answer is max(dp0, dp1)
    cout << max(dp0, dp1) << endl;
    return 0;
}