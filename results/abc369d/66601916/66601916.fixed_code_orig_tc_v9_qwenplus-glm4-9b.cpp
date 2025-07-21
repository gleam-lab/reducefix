#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = (long long)1e18;

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        // Update dp0 and dp1 using the correct formulas
        dp0 = max(dp1 + 2 * x, dp0);
        dp1 = max(dp0 - x - 2 * x, dp1); // Fix the formula to ensure dp1 does not grow too quickly
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}