#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp = 0, temp;

    rep(i,n)
    {
        temp = max(dp, dp + 2 * a[i]);
        dp = max(temp, dp + a[i]);
    }

    cout << max(dp, 0LL) << endl;
}