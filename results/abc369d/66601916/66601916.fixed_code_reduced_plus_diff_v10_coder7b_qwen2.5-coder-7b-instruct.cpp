#include <vector>
#include <iostream>
#include <algorithm>
#include <climits> // For INT_MAX and INT_MIN
#include <string>

using namespace std;

int main() {
    int n;
    long long dp0 = 0, dp1 = INT_MIN;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        long long new_dp0 = max(dp1 + 2 * x, dp0);
        dp1 = max(dp1, dp0 + x);
        dp0 = new_dp0;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}