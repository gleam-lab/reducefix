#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long dp0 = 0, dp1 = 0, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        long long new_dp0 = max(dp0, dp1);
        long long new_dp1 = dp0 + x;
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}