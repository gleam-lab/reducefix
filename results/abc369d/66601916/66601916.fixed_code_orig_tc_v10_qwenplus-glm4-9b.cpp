#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

#define INF (long long)numeric_limits<long long>::max()

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        // Assuming the problem statement is something like maximizing some resource allocation or game state.
        // This is just an assumption, as the actual state transition logic is not clear.
        dp0 = max(dp1 + 2 * x, dp0);
        dp1 = max(dp0 - x, dp1); // This line is purely speculative.
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}