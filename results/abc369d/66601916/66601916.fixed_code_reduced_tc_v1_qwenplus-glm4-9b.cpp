#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long dp0 = 0, dp1 = -LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        long long temp = dp0;
        dp0 = max(dp1 + 2 * x, dp0);
        dp1 = max(temp + x, dp1);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}