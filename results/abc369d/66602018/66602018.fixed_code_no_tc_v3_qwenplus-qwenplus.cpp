#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18  // Fix: Use a much larger value for INF to represent negative infinity

int main(){
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;         // dp0 represents max profit with no stock at the end of day i
    dp1 = -INF;      // dp1 represents max profit with holding stock at the end of day i
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp0, dp1 + x);           // Sell stock or do nothing
        dp1 = max(dp1, temp - x);          // Buy stock or do nothing
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}