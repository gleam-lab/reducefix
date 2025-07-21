#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main(){
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp1 + x, dp0); // Corrected: dp1 should be added without doubling x for odd-indexed monsters
        if ((i + 1) % 2 == 0) { // Check if the current monster is at an even index (considering 0-based indexing)
            dp1 = max(temp + 2 * x, dp1); // Double the experience points for even-indexed monsters
        } else {
            dp1 = max(temp + x, dp1); // Single experience point for odd-indexed monsters
        }
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}