#include <iostream>
#include <algorithm>
using namespace std;

#define INF LLONG_MIN

int main() {
    int n;
    long long dp0 = 0, dp1 = -INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long temp = max(dp0, dp1 + 2 * x);
        dp0 = max(dp0, dp1 + x);
        dp1 = temp;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}