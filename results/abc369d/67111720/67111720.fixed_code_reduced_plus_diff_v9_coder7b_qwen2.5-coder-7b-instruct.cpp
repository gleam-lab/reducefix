#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;
using __int128 = __int128_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<__int128> a(n);
    rep(i, n) cin >> a[i];

    __int128 dp_e = 0, dp_o = -1, temp;

    rep(i, n) {
        temp = dp_e;
        dp_e = max(dp_o + 2 * a[i], dp_e);
        dp_o = max(temp + a[i], dp_o);
    }

    cout << max(dp_e, dp_o) << '\n';

    return 0;
}