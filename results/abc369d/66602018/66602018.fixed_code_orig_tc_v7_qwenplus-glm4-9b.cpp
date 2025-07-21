#include <iostream>
#include <limits>
using namespace std;

#define INF (long long)numeric_limits<long long>::min()

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        long long new_dp0 = max(dp1 + (x == 1 ? 2 : 1)*x, dp0);
        dp1 = max(dp0 + (x == 1 ? 2 : 1)*x, dp1);
        dp0 = new_dp0;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}