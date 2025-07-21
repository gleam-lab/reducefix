#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main() {
    int n;
    cin >> n;
    
    long long dp0 = 0;       // Represents the maximum sum when the last operation was no multiply
    long long dp1 = -INF;    // Represents the maximum sum when the last operation was multiply by 2
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        long long new_dp0 = max(dp0 + x, dp1 + x);
        long long new_dp1 = dp0 + 2 * x;
        
        dp0 = max(dp0, new_dp0);
        dp1 = max(dp1, new_dp1);
    }
    
    cout << max(dp0, dp1) << endl;
    return 0;
}