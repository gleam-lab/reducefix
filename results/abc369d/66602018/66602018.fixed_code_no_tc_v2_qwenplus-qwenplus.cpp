#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18  // Fix: Use a sufficiently large value for INF

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF, x;
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        long long new_dp0 = max(dp0, dp1 + 2 * x);  // Case: not taking x as single, or taking it from dp1
        long long new_dp1 = max(dp1, dp0 + x);      // Case: not extending, or starting new pair
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}