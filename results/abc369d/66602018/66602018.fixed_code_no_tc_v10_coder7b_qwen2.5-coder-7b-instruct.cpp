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
        dp0 = max(dp1 + (2 * x), dp0); // Corrected: should be dp1 + (2 * x)
        dp1 = max(temp + x, dp1);      // Corrected: should be temp + x
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}