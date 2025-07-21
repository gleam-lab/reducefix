#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define INF LONG_LONG_MAX

int main() {
    int n;
    cin >> n;
    
    long long dp0 = 0;          // Represents state where previous element was not doubled
    long long dp1 = -INF;       // Represents state where previous element was doubled
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        long long new_dp0 = max(dp0, dp1 + 2 * x);  // Current not doubled: take max of previous states
        long long new_dp1 = dp0 + x;                // Current doubled: can only come from previous not doubled
        
        dp0 = new_dp0;
        dp1 = new_dp1;
    }
    
    cout << max(dp0, dp1) << endl;
    return 0;
}