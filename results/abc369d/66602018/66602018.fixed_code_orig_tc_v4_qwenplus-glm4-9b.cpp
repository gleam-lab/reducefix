#include <iostream>
#include <climits>
using namespace std;

#define INF LLONG_MIN

int main() {
    int n;
    long long dp0 = 0, dp1 = 0, x, temp;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp1 + 2LL * x, dp0);
        dp1 = max(temp + x, dp1);
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}