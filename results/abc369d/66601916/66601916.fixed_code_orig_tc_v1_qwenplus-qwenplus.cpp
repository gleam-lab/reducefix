#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>

using namespace std;

#define INF 1e18  // Use a sufficiently large value to represent negative infinity

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF, x, temp;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp0, dp1 + 2 * x);
        dp1 = max(dp1, temp + x);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}