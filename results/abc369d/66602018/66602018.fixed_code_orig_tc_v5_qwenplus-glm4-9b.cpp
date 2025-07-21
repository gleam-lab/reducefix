#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18  // Use a larger number for INF to fit the problem scope

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF;  // Initialize dp1 to INF to represent the maximum possible sum
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        // Update dp0 and dp1 for the current item x
        long long new_dp0 = max(dp0, dp1 + x);  // Skip the current item
        dp1 = max(dp1, dp0 + x);             // Take the current item
        dp0 = new_dp0;
    }

    // Since dp1 is initially set to -INF, and we are maximizing, we need to add INF at the end
    // Only if all dp1 remains negative, which would be impossible in this context
    cout << max(dp0, dp1 + INF) << endl;
    return 0;
}