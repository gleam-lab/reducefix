#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    if(n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    ll dp_e = a[0], dp_o = a[1];
    ll temp_e, temp_o;

    for(int i = 2; i < n; i++) {
        temp_e = dp_e;
        temp_o = dp_o;
        if(i % 2 == 0) {
            dp_e = max(temp_e, temp_o + a[i]);
        } else {
            dp_o = max(temp_o, temp_e + a[i]);
        }
    }

    if(n % 2 == 0) {
        cout << max(dp_e, dp_o) << endl;
    } else {
        cout << dp_e << endl;
    }
}