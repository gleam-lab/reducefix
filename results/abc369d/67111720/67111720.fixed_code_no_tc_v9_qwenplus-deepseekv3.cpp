#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    ll dp_prev_prev = 0;          // dp[i-2]
    ll dp_prev = a[0];            // dp[i-1]
    ll dp_curr;

    for (int i = 1; i < n; ++i) {
        // Current max is either:
        // 1. Take a[i] alone (add to dp[i-2])
        // 2. Take a[i] with a[i-1] (add 2*a[i] to dp[i-2])
        // 3. Skip a[i] (use dp[i-1])
        dp_curr = max({dp_prev_prev + a[i], dp_prev_prev + 2 * a[i], dp_prev});
        
        dp_prev_prev = dp_prev;
        dp_prev = dp_curr;
    }

    cout << dp_prev << endl;
}