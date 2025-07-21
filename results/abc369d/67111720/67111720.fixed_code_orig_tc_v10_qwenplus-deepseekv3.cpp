#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll dp0 = 0;       // max sum if we don't take current element
    ll dp1 = a[0];     // max sum if we take current element

    for (int i = 1; i < n; i++) {
        ll new_dp0 = max(dp0, dp1);  // current not taken - can come from either previous state
        ll new_dp1 = dp0 + a[i];     // current taken - must come from previous not taken
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
}