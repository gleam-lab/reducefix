#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>

using namespace std;

#define INF (long long)1e18

int main(){
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp0, dp1 + x);  // Standard non-consecutive selection
        dp1 = max(temp + x, dp1);  // Standard selection or maintain previous dp1
        // Special case: if we take two consecutive, double the current one
        if (i > 0) {
            dp0 = max(dp0, temp + 2 * x);
        }
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}