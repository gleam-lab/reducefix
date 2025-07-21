#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, x;
vector<int> a, b, p, q;

ll cost(vector<ll>& dp, int i, int w) {
    if (w == 0) return 0;
    if (dp[w] != -1) return dp[w];
    
    ll res = LLONG_MAX;
    for (int j = 0; j <= min(w / a[i], (ll)b[i]); ++j) {
        res = min(res, 1LL * j * p[i] + cost(dp, i + 1, w - j * a[i]));
    }
    for (int j = 0; j <= min(w / b[i], (ll)a[i]); ++j) {
        res = min(res, 1LL * j * q[i] + cost(dp, i + 1, w - j * b[i]));
    }
    return dp[w] = res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -1));
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (cost(dp, 0, mid) <= x) lo = mid;
        else hi = mid - 1;
    }
    
    cout << lo << endl;
    return 0;
}