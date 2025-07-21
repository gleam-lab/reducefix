#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (long long)1e15 // Adjusted to a higher value for long long range

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        
        // Update dp1 to be the maximum of the previous dp0 and dp1 + 2*x
        long long new_dp1 = max(dp0, dp1 + 2 * x);
        
        // Update dp0 to be the maximum of the previous dp1 and dp0 + x
        dp0 = max(dp1, dp0 + x);
        
        // Set dp1 to the new_dp1
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}