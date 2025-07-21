#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (long long)1e18

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF, x;
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        long long new_dp1 = max(dp0 + 2 * x, dp1);
        dp0 = max(dp1 + x, dp0);
        dp1 = new_dp1;
    }
    
    cout << max(dp0, dp1) << endl;
    return 0;
}