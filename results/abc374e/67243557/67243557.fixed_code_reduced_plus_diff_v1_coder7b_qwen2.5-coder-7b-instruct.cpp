#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(const vector<int>& a, const vector<int>& b, const vector<int>& p, const vector<int>& q, ll x){
    ll ans = 0;
    ll pq = min(*min_element(p.begin(), p.end()), *min_element(q.begin(), q.end()));
    vector<ll> dp(x+1, LLONG_MAX);
    dp[0] = 0; // i個買う時の最小値
    rep(i,x+1){
        if(i - a[0] >= 0)dp[i] = min(dp[i], dp[i-a[0]] + p[0]);
        if(i - b[0] >= 0)dp[i] = min(dp[i], dp[i-b[0]] + q[0]);
    }
    
    for(int i = 1; i < a.size(); ++i) {
        vector<ll> ndp(x+1, LLONG_MAX);
        ndp[0] = dp[0]; // i個買う時の最小値
        rep(j,x+1){
            if(j - a[i] >= 0)ndp[j] = min(ndp[j], dp[j-a[i]] + p[i]);
            if(j - b[i] >= 0)ndp[j] = min(ndp[j], dp[j-b[i]] + q[i]);
        }
        dp = ndp;
    }

    return *min_element(dp.begin(), dp.end());
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll ans = LLONG_MAX;
    rep(i,n){
        ans = min(ans, f({a[i]}, {b[i]}, {p[i]}, {q[i]}, x));
    }
    cout << ans;
    return 0;
}