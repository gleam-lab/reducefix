#include <iostream>
#include <algorithm>
using namespace std;

#define INF (long long)(1e18) // Assuming the problem involves very large numbers

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0; // Store previous dp0 value
        // Update dp0 to the maximum value of not taking action or taking action n times
        dp0 = max(dp0, dp1 + x * 2);
        // Update dp1 to the maximum value of taking action once or not taking any action
        dp1 = max(temp + x, dp1);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}