#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18  // Fixed: Was too small, caused incorrect comparisons

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp0, dp1 + 2 * x);  // Fixed: Should update dp0 with max of itself and new value
        dp1 = max(dp1, temp + x);    // Fixed: Same logic for dp1
    }

    cout << max(dp0, dp1) << endl;  // Final result is max of the two states
    return 0;
}