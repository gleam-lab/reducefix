#include <iostream>
#include <limits>

using namespace std;

int main() {
    int n;
    long long dp0 = 0, dp1 = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        dp1 = max(dp0 + x, dp1);
        dp0 = max(dp1, dp0);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}