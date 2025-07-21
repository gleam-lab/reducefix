#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18  // Fix: Use a sufficiently large value for INF

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp0, dp1 + 2 * x);  // Fix: Correct transition from dp1 to dp0
        dp1 = max(dp1 + x, temp);    // Fix: Correct transition from dp0 to dp1
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}