#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18+7

int main(){
    int n;
    long long dp0 = 0, dp1 = 0, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if ((i + 1) % 2 == 0) { // Check if the monster number is even
            dp1 = max(dp1 + x + x, dp0); // Add twice the experience if the monster is even-numbered
        } else {
            dp1 = max(dp1 + x, dp0); // Otherwise, add normally
        }
        dp0 = max(dp1, dp0); // Update dp0 to be the maximum of itself and dp1
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}