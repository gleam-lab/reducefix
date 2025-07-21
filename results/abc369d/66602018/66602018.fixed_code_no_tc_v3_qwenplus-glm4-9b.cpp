#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int main() {
    int n;
    cin >> n;

    long long dp0 = 0, dp1 = -1e9;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long temp = dp0;
        dp0 = max(dp1 + (2LL * x), dp0);
        dp1 = max(temp + x, dp1);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}