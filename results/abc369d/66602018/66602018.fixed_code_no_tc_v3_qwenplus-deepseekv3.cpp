#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;        // Represents the maximum sum up to current element without taking it
    dp1 = -INF;     // Represents the maximum sum up to current element taking it
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp0, dp1);        // Current not taken = max of previous taken or not taken
        dp1 = temp + x;             // Current taken = previous not taken + current value
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}