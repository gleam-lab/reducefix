#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> dp0(2, LLONG_MIN); // Initialize dp0 with negative infinity
    dp0[1] = 0; // dp0[1] holds the maximum sum including the current element
    vector<long long> dp1 = vector<long long>(2, LLONG_MIN); // dp1 holds the maximum sum excluding the current element

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        // Calculate new dp values
        long long new_dp0[2];
        new_dp0[0] = max(dp1[0] + x, dp0[0]);
        new_dp0[1] = max(dp0[1] + x, dp1[1]);

        // Update dp0 and dp1
        dp0[1] = new_dp0[1];
        dp0[0] = new_dp0[0];

        // Update dp1 for next iteration
        dp1[0] = max(dp0[1] + x, dp1[0]);
        dp1[1] = max(dp0[0] + x, dp1[1]);
    }

    // Output the maximum value between dp0[0] and dp0[1]
    cout << max(dp0[0], dp0[1]) << endl;

    return 0;
}