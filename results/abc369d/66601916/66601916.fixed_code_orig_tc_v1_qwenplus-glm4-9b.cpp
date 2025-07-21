#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    long long dp0 = 0, dp1 = LLONG_MIN;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;

        // Update dp0 to be the maximum of the two possibilities from the previous step.
        // It can either be the previous dp0, or the previous dp1 plus 2*x.
        long long next_dp0 = max(dp0, dp1 + 2 * x);

        // Update dp1 to be the maximum of the two possibilities from the previous step.
        // It can either be the previous dp1, or the previous dp0 plus x.
        dp1 = max(dp1, dp0 + x);

        // Move to the next values for dp0 and dp1.
        dp0 = next_dp0;
    }

    // At the end of the loop, print the maximum of dp0 and dp1.
    cout << max(dp0, dp1) << endl;

    return 0;
}