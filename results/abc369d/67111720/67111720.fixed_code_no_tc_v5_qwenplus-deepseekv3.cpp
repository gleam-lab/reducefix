#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_include = 0, dp_exclude = 0;

    rep(i,n)
    {
        ll new_include = dp_exclude + a[i];
        ll new_exclude = max(dp_include, dp_exclude);
        
        dp_include = new_include;
        dp_exclude = new_exclude;
    }

    cout << max(dp_include, dp_exclude) << endl;
}