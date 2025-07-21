#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0; i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_even = 0, dp_odd = -1, temp;

    rep(i,n)
    {
        temp = dp_even;
        dp_even = max(dp_even, dp_odd + 2 * a[i]);
        dp_odd = max(dp_odd, temp + a[i]);
    }

    cout << max(dp_even, dp_odd) << endl;
}