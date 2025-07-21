#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;          // Represents not taking current element
    dp1 = -INF;       // Represents taking current element (initially invalid)
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        // Either take previous dp1 (if valid) plus current x*2,
        // or stay with previous dp0
        dp0 = max(dp0, dp1 + 2 * x);
        // Either take previous dp0 plus current x,
        // or stay with previous dp1 (if it was better)
        dp1 = max(dp1, temp + x);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}