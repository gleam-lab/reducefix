#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll prev_prev = 0;      // dp[i-2]
    ll prev = a[0];        // dp[i-1]
    
    for(int i = 1; i < n; i++) {
        ll current = max(prev, prev_prev + a[i]);
        prev_prev = prev;
        prev = current;
    }

    cout << prev << endl;
}