#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // æ©æãªã¿ã¼ã³
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // iä½ç®ã¾ã§ã®æå¤§ã®çµé¨å¤ãiä½ç®ã¾ã§ã§ãodd/evenååããå ´å
    vector<ll> dp(n, 0);
    dp[0] = a[0];
    dp[1] = max(a[0] + a[1], 2 * a[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1] + a[i], dp[i - 2] + 2 * a[i]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}