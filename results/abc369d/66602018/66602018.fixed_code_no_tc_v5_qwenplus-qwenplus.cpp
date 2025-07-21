#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18  // Fix: Use a sufficiently large value for INF

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF, x;
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        // Store the previous dp0 value before updating it
        long long prev_dp0 = dp0;
        
        // Transition:
        // dp0[i] = max(dp0[i-1], dp1[i-1] + 2*x)
        dp0 = max(dp0, dp1 + 2 * x);
        
        // dp1[i] = max(dp1[i-1], dp0_prev[i-1] + x)
        dp1 = max(dp1, prev_dp0 + x);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}