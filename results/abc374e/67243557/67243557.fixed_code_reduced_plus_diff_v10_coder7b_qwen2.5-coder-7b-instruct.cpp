#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(const vector<int>& a, const vector<int>& b, const vector<int>& p, const vector<int>& q, ll x){
    ll n = a.size();
    vector<ll> dp(x+1, LLONG_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        vector<ll> ndp(x+1, LLONG_MAX);
        for(int j = 0; j <= x; ++j){
            if(j >= a[i]) ndp[j] = min(ndp[j], dp[j-a[i]] + p[i]);
            if(j >= b[i]) ndp[j] = min(ndp[j], dp[j-b[i]] + q[i]);
        }
        dp = move(ndp);
    }
    return *min_element(dp.begin(), dp.end());
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll l = 0, r = 10000000000;
    while(r - l > 1){
        ll m = (l + r) / 2;
        ll cost = 0;
        rep(i,n){
            cost += f({a[i]}, {b[i]}, {p[i]}, {q[i]}, m);
        }
        if(cost <= x) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}