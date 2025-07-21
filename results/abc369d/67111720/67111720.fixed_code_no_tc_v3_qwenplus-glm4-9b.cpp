#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_e=0, dp_o=-1;

    rep(i,n)
    {
        ll prev_e = dp_e;
        ll prev_o = dp_o;

        dp_e = max(prev_o + 2 * a[i], prev_e);
        dp_o = max(prev_e + a[i], prev_o);
    }

    cout << max(dp_e, dp_o) << endl;
}