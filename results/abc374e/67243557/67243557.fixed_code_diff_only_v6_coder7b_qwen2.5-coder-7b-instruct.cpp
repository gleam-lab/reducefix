#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(int a, int b, int p, int q, ll x){
    vector<ll> dp(x+1, LLONG_MAX);
    dp[0] = 0;
    for(int i = 1; i <= x; ++i){
        if(i >= a) dp[i] = min(dp[i], dp[i-a] + p);
        if(i >= b) dp[i] = min(dp[i], dp[i-b] + q);
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll ans = 0;
    rep(i,n){
        ans += f(a[i], b[i], p[i], q[i], x);
    }
    
    cout << ans;
    return 0;
}