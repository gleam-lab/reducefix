#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (ll(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp_normal(n, 0);   // last attack was normal (count = 1)
    vector<ll> dp_strong(n, 0);   // last attack was strong (count = 2)
    vector<ll> dp_skip(n, 0);     // skipped this monster

    dp_normal[0] = a[0];
    dp_strong[0] = 0;
    dp_skip[0] = 0;

    dp_normal[1] = a[1];
    dp_strong[1] = a[0] + 2 * a[1];
    dp_skip[1] = a[0];

    for (int i = 2; i < n; ++i) {
        dp_normal[i] = a[i] + max({dp_normal[i-2], dp_strong[i-2], dp_skip[i-1]});
        dp_strong[i] = 2 * a[i] + max(dp_normal[i-1], dp_skip[i-1]);
        dp_skip[i] = max({dp_normal[i-1], dp_strong[i-1], dp_skip[i-1]});
    }

    cout << max({dp_normal[n-1], dp_strong[n-1], dp_skip[n-1]}) << endl;

    return 0;
}