#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <limits> // For LLONG_MAX

using namespace std;

const long long INF = (long long)numeric_limits<long long>::max();

int main() {
    int n;
    long long dp0 = 0, dp1 = LLONG_MIN, x, temp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp1 + 2LL * x, dp0);
        dp1 = max(temp + x, dp1);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}