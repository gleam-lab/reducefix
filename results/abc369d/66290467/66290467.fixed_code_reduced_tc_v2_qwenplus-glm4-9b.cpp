#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    // æ©æãªã¿ã¼ã³
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + a[1] << endl; // ä¿®æ­£: 2 * a[1]ããa[1]ã«ä¿®æ­£
        return 0;
    }

    vector<ll> dp(n, 0); // iä½ç®ãåãã¾ã§ã®æå¤§ã®çµé¨å¤

    dp[0] = a[0];
    dp[1] = a[0] + a[1]; // ä¿®æ­£: dp[1]ã®è¨ç®å¼ãä¿®æ­£

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 2] + 2 * a[i], dp[i - 1] + a[i]); // ä¿®æ­£: 2 * a[i]ããa[i]ã«ä¿®æ­£
    }
    cout << dp[n - 1] << endl;

    return 0;
}