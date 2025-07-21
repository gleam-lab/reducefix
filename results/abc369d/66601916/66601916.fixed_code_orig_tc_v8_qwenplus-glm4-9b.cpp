#include <iostream>

using namespace std;

#define INF LLONG_MAX

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        
        // Update dp0 and dp1 to reflect the new situation after an update with value x
        dp0 = max(dp1 + 2LL * x, dp0);
        dp1 = max(temp + x, dp1);
    }

    // Output the maximum of dp0 and dp1 as the final result
    cout << max(dp0, dp1) << endl;
    return 0;
}