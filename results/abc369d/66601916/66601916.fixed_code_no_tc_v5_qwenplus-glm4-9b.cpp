#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    long long dp0, dp1;
    dp0 = 0;
    dp1 = -numeric_limits<long long>::max();
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long temp0 = max(dp0, dp1 + 2 * x);
        dp0 = temp0;
        dp1 = max(dp0 - x, dp1);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}