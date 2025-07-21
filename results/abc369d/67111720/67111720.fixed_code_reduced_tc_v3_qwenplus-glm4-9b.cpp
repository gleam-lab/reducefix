#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0; i < (n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll dp_e = 0, dp_o = -1, dp_ne = -1; // dp_ne is the non-extended version of dp_e

    rep(i, n) {
        ll new_dp_e = max(dp_o + 2 * a[i], dp_ne + 2 * a[i]);
        ll new_dp_o = max(dp_ne, dp_e);
        ll new_dp_ne = max(dp_e, dp_ne);

        dp_ne = new_dp_ne;
        dp_e = new_dp_e;
        dp_o = new_dp_o;
    }

    cout << max(dp_e, max(dp_o, dp_ne)) << endl;
}