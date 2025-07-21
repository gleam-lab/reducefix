#include <iostream>
using namespace std;

#define INF (long long)1e9 + 5 // Adjusted to a more reasonable number for large sums

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp1 + (2 * x), dp0); // State 0 is the maximum of the previous state 1 plus twice the current x, or the previous state 0
        dp1 = max(temp + x, dp1);     // State 1 is the maximum of the previous state 0 plus the current x, or the previous state 1
    }

    cout << max(dp0, dp1) << endl; // Finally, output the maximum of the last two states
    return 0;
}