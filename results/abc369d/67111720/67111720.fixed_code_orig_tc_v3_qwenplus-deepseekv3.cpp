#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_prev_prev = 0;
    ll dp_prev = a[0];
    ll dp_curr;

    for(int i = 1; i < n; i++)
    {
        dp_curr = max(dp_prev, dp_prev_prev + a[i]);
        dp_prev_prev = dp_prev;
        dp_prev = dp_curr;
    }

    cout << dp_prev << endl;
}