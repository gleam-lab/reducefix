#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

vector<vector<ll>> dp;

ll solve(vector<pair<int, int>>& sa, vector<pair<int, int>>& tb, ll cap) {
    dp.assign(cap + 1, LLONG_MAX);
    dp[0] = 0;
    
    for(auto [a, p] : sa) {
        for(int j = cap; j >= a; --j) {
            dp[j] = min(dp[j], dp[j - a] + p);
        }
    }
    
    for(auto [b, q] : tb) {
        for(int j = cap; j >= b; --j) {
            dp[j] = min(dp[j], dp[j - b] + q);
        }
    }
    
    for(int i = 1; i <= cap; ++i) {
        dp[i] = min(dp[i], dp[i - 1]);
    }
    
    return dp[cap];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> sa, tb;
    
    rep(i, n) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        sa.push_back({a, p});
        tb.push_back({b, q});
    }
    
    int l = 0, r = 1e7;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(solve(sa, tb, m) <= x) l = m;
        else r = m - 1;
    }
    
    cout << l << endl;
    return 0;
}