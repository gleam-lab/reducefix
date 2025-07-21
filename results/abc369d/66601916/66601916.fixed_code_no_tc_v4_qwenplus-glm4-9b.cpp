#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

#define INF (long long)numeric_limits<long long>::min()

int main() {
    int n;
    long long dp0, dp1, x;
    dp0 = 0;
    dp1 = INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        long long next_dp0 = max(dp1 + 2 * x, dp0);
        dp0 = dp1;
        dp1 = next_dp0;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}