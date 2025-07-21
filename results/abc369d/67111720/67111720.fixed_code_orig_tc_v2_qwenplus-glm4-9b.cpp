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
        ll temp = dp_e; // Copy the value of dp_e before updating
        dp_e = max(dp_o + 2 * a[i], dp_e); // Update dp_e
        dp_o = max(temp + a[i], dp_o); // Update dp_o
    }

    cout << max(dp_e, dp_o) << endl; // Print the maximum of dp_e and dp_o after all iterations
}