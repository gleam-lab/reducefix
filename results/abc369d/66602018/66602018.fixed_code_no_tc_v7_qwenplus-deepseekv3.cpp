#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main(){
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp0, dp1 + x);  // current element not taken or taken after previous was taken
        dp1 = max(dp1, temp + 2 * x);  // current element taken with double value after previous was not taken
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}