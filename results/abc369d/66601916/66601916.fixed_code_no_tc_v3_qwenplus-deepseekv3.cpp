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
    dp0 = 0;       // Can add x in next step
    dp1 = -INF;    // Can add 2*x in next step
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        // To get to dp0 state, we can come from either:
        // 1. Previous dp0 state (can't multiply by 2)
        // 2. Previous dp1 state (after multiplying by 2)
        dp0 = max(dp0, dp1 + 2*x);
        // To get to dp1 state, we can come from:
        // 1. Previous dp0 state (after adding x)
        dp1 = max(dp1, temp + x);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}