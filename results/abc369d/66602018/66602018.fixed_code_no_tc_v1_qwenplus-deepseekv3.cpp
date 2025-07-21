#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;          // Represents the maximum sum ending with a 1x multiplier
    dp1 = -INF;       // Represents the maximum sum ending with a 2x multiplier
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp0, dp1 + x);   // Current element is multiplied by 1 (either take previous 2x or not)
        dp1 = max(dp1, temp + 2 * x); // Current element is multiplied by 2 (must come after 1x)
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}