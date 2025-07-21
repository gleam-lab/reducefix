#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main() {
    int n;
    cin >> n;
    long long dp0 = 0;         // last element not taken
    long long dp1 = -INF;      // last element taken
    long long x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        long long new_dp0 = max(dp0, dp1 + x);
        long long new_dp1 = max(dp1, dp0 - x);
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}