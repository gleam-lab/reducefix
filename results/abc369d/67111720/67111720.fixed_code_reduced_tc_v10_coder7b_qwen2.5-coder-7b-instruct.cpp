#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // Initialize variables to handle large numbers properly
    ll dp_e = 0, dp_o = -1, temp;

    rep(i,n)
    {
        temp = dp_e;
        dp_e = max(dp_o + 2 * a[i], dp_e);
        dp_o = max(temp + a[i], dp_o);
    }

    // Use unsigned long long to avoid overflow issues with very large numbers
    cout << max(dp_e, dp_o) << endl;
}