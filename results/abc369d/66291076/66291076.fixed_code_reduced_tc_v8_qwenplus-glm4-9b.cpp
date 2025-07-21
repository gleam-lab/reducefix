#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (ll(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // æ©æãªã¿ã¼ã³
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // iä½ç®ã¾ã§ã®æå¤§ã®çµé¨å¤ãiä½ç®ã¾ã§ã§ãodd/evenååããå ´å
    vector<ll> dp_odd(n, 0), dp_even(n, 0);
    dp_odd[0] = a[0];
    dp_even[0] = a[0];
    dp_odd[1] = max(a[0] + 2 * a[1], a[1]);
    dp_even[1] = a[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        dp_odd[i] = max(dp_odd[i - 2] + 2 * a[i], dp_even[i - 1] + a[i]);
        dp_even[i] = max(dp_even[i - 2] + a[i], dp_odd[i - 1] + 2 * a[i]);
    }
    cout << max(dp_odd[n - 1], dp_even[n - 1]) << endl;

    return 0;
}