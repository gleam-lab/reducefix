#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_e = 0, dp_o = -1e18, temp;

    rep(i,n)
    {
        temp = dp_e;
        dp_e = max(dp_e, dp_o + a[i]);
        dp_o = max(dp_o, temp + a[i]);
    }

    cout << max(dp_e, dp_o) << endl;
}