#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    int n;
    long long dp0 = 0, dp1 = -1e18; // Use a large enough constant for dp1
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long temp = dp0;
        dp0 = max(dp1 + 2 * x, dp0);
        dp1 = max(temp + x, dp1);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}