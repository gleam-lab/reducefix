#include <bits/stdc++.h>
using namespace std;

#define INF (long long)(1e18) - 1  // Use a larger INF value to prevent overflow

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp1 + (2LL * x), dp0);  // Use 2LL to make sure the multiplication is done with long long
        dp1 = max(temp + x, dp1);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}