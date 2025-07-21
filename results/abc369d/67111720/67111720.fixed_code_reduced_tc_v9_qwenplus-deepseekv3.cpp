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

    ll dp_e = 0, dp_o = a[0], temp;

    for (int i = 1; i < n; ++i)
    {
        temp = dp_e;
        dp_e = max(dp_o, dp_e);
        dp_o = temp + a[i];
    }

    cout << max(dp_e, dp_o) << endl;
}