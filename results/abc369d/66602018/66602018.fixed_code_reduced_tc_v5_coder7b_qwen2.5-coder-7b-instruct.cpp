#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long dp0 = 0, dp1 = LLONG_MIN;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        dp0 = max(dp1 + (2 * x), dp0);
        dp1 = max(dp1, dp0 - x);
    }

    cout << max(dp0, dp1) << '\n';
    return 0;
}