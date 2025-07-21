#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main(){
    int n;
    long long dp0, dp1, x;
    dp0 = 0;        // dp0: maximum sum when we haven't taken any element or when we've taken an even number of elements
    dp1 = -INF;     // dp1: maximum sum when we've taken an odd number of elements
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        long long new_dp0 = max(dp0, dp1 - x);  // Either keep previous dp0 or take current element from dp1
        long long new_dp1 = max(dp1, dp0 + x);  // Either keep previous dp1 or take current element from dp0
        
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}