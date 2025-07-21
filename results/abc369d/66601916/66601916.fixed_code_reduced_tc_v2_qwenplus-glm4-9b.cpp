#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -numeric_limits<long long>::max();
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