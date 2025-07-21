#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long dp0 = 0, dp1 = -1e18; // Initialize dp1 to -1e18 to handle the case where all inputs are negative
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        long long temp = max(dp0 - x, dp1);
        dp1 = dp0;
        dp0 = temp + 2 * x;
    }
    cout << max(dp0, dp1) << endl;
    return 0;
}