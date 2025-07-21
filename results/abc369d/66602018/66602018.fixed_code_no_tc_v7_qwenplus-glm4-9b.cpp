#include <iostream>
#include <algorithm>
using namespace std;

#define INF (long long)1e9+5

int main() {
    int n;
    long long dp0, dp1, x;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        long long temp = dp0;
        dp0 = max(dp1 + (2 * x), dp0);
        dp1 = max(temp + x, dp1);
    }

    cout << max(dp0, dp1);
    return 0;
}