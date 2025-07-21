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

    ll dp_e = 0, dp_o = 0, temp;

    rep(i,n)
    {
        temp = dp_e;
        dp_e = max(dp_o + a[i], dp_e);
        dp_o = max(temp, dp_o);
    }

    cout << max(dp_e, dp_o) << endl;
}