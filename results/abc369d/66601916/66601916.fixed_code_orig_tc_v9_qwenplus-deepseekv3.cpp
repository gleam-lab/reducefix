#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define INF LONG_LONG_MIN

int main() {
    int n;
    cin >> n;
    
    long long dp0 = 0;       // last operation was normal addition (x)
    long long dp1 = INF;      // last operation was double addition (2x)
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        long long new_dp0 = max(dp0, dp1 + x);
        long long new_dp1 = max(dp1, dp0 + 2 * x);
        
        dp0 = new_dp0;
        dp1 = new_dp1;
    }
    
    cout << max(dp0, dp1) << endl;
    return 0;
}