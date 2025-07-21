#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    ll dp_e = a[0], dp_o = a[0];
    rep(i, 2, n) {
        ll temp_e = dp_e;
        dp_e = max(dp_o + 2 * a[i], dp_e);
        dp_o = max(temp_e + a[i], dp_o);
    }

    cout << max(dp_e, dp_o) << endl;
}