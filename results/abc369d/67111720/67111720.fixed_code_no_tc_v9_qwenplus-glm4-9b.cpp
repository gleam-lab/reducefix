#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_e=0, dp_o=-1; // Initialize dp_e with 0 and dp_o with -1
    ll temp;

    rep(i,n)
    {
        temp = dp_e; // Store dp_e before updating it
        dp_e = max(dp_o + 2 * a[i], dp_e); // Update dp_e considering the previous dp_o value
        dp_o = max(temp + a[i], dp_o); // Update dp_o considering the previous dp_e value
    }

    cout << max(dp_e, dp_o) << endl; // Output the maximum value of dp_e and dp_o
}