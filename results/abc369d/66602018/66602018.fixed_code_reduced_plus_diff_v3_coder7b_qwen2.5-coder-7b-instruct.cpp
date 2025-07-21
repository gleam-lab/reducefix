#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long dp0 = 0, dp1 = -INF, x;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(x > 0) {
            dp0 += x;
        } else {
            long long temp = dp0;
            dp0 = max(dp1, dp0);
            dp1 = max(temp, dp1 + x);
        }
    }

    cout << max(dp0, dp1) << '\n';
    return 0;
}