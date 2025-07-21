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
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        // The new dp0 is max between:
        // - previous dp0 (doing nothing with x)
        // - previous dp1 (can't double after a double)
        dp0 = max(dp0, dp1);
        // The new dp1 is max between:
        // - previous dp0 + x (single)
        // - previous dp0 + 2*x (double, but this would skip next element)
        // However, since we can't double after a double, we need to ensure the transitions are correct
        dp1 = temp + x;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}