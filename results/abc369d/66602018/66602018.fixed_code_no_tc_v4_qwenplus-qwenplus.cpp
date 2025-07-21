#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18  // Fixed: Previously too small for large inputs

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF, x;
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        // Use temporary values to avoid overwriting dp0 before it's used
        long long new_dp0 = max(dp0, dp1 + 2 * x);
        long long new_dp1 = max(dp1, dp0 + x);
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}