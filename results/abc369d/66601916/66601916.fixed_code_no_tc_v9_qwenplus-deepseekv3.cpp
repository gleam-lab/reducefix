#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define INF LLONG_MAX

int main() {
    int n;
    cin >> n;
    
    long long dp0 = 0;          // Represents state where last operation was not 2*x
    long long dp1 = -INF;       // Represents state where last operation was 2*x
    long long x;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        long long new_dp0 = max(dp0, dp1 + 2 * x);
        long long new_dp1 = max(dp1, dp0 + x);
        
        dp0 = new_dp0;
        dp1 = new_dp1;
    }
    
    cout << max(dp0, dp1) << endl;
    return 0;
}