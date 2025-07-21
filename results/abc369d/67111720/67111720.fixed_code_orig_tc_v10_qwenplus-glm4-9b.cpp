#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll dp_e = 0, dp_o = -1, temp;

    rep(i, n) {
        temp = dp_e;
        dp_e = max(dp_o + 2 * a[i], dp_e + a[i]); // Update dp_e to be the maximum of the two possible transitions
        dp_o = max(temp + a[i], dp_o); // Update dp_o to be the maximum of the two possible transitions
    }

    cout << max(dp_e, dp_o) << endl;
    return 0;
}