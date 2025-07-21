#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_e = 0, dp_o = 0, prev_e, prev_o;

    rep(i,n) {
        prev_e = dp_e;
        prev_o = dp_o;
        if(i % 2 == 0) {
            dp_e = max(prev_e, prev_o + a[i]);
            dp_o = prev_o;
        } else {
            dp_o = max(prev_o, prev_e + a[i]);
            dp_e = prev_e;
        }
    }

    cout << max(dp_e, dp_o) << endl;
}