#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_e = 0, dp_o = 0; // dp_e: even step, dp_o: odd step
    rep(i,n)
    {
        ll new_e = max(dp_e, dp_o + 2*a[i]); // can take current (even multiplied) or skip
        ll new_o = max(dp_o, dp_e + a[i]);   // can take current (normal) or skip
        dp_e = new_e;
        dp_o = new_o;
    }

    cout << max(dp_e, dp_o) << endl;
}