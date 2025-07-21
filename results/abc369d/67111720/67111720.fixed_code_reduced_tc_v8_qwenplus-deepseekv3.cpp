#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    ll dp_e = a[0], dp_o = 0;
    for (int i = 1; i < n; ++i) {
        ll new_e = max(dp_e, dp_o + a[i]);
        ll new_o = max(dp_o, dp_e - a[i-1] + a[i]);
        dp_e = new_e;
        dp_o = new_o;
    }

    cout << max(dp_e, dp_o) << endl;
}