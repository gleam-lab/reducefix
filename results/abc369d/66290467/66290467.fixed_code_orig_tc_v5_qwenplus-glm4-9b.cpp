#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void rep(int &i, int n) {
    for (i = 0; i < n; ++i);
}

void drep(int &i, int n) {
    for (i = n - 1; i >= 0; --i);
}

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    cin >> n;
    vector<ll> dp(n, 0);

    if (n == 1) {
        cin >> dp[0];
        cout << dp[0] << endl;
        return 0;
    } else if (n == 2) {
        cin >> dp[0] >> dp[1];
        cout << dp[0] + 2 * dp[1] << endl;
        return 0;
    }

    cin >> dp[0] >> dp[1];
    dp[2] = max(dp[0] + 2 * dp[2], dp[1] + dp[2]);

    rep(i, n - 3) {
        cin >> dp[i + 3];
        dp[i + 3] = max(dp[i + 1] + dp[i + 3], dp[i] + 2 * dp[i + 3]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}