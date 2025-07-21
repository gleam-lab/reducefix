#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define INF LONG_LONG_MAX

int main() {
    int n;
    long long dp0, dp1, x;
    dp0 = 0;          // maximum sum when not taking current element
    dp1 = -INF;       // maximum sum when taking current element
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        long long new_dp0 = max(dp0, dp1);  // current not taken = max of previous taken/not taken
        long long new_dp1 = dp0 + x;        // current taken = previous not taken + current value
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}