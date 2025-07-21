#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0; i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_e=0, dp_o=-1;

    rep(i,n)
    {
        ll new_dp_e = max(dp_o + 2 * a[i], dp_e);
        dp_o = max(dp_e, dp_o + a[i]);
        dp_e = new_dp_e;
    }

    cout << max(dp_e, dp_o) << endl;
}