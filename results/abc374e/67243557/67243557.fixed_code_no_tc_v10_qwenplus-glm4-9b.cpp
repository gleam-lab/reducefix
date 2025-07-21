#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll cost) {
    ll dp[10010] = {1e10};
    dp[0] = 0;
    for (ll i = 1; i <= 10000; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    if (cost < 10000) return 1e10;
    return dp[cost];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<pair<int, int>, pair<int, int>>> items(n);
    rep(i, n) {
        int a, b, p, q;
        cin >> a >> p >> b >> q;
        items[i] = {{a, b}, {p, q}};
    }
    ll l = 0, r = 10e9 + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll cost = 0;
        for (int i = 0; i < n; ++i) {
            ll a = items[i].first.first;
            ll b = items[i].first.second;
            ll p = items[i].second.first;
            ll q = items[i].second.second;
            ll required = ceil((double)mid / (a * b));
            if (required * (p + q) <= mid) {
                cost += required * (p + q);
            } else {
                ll extra = (required * (p + q) - mid) / (p + q);
                cost += required * (p + q) + extra * q;
            }
        }
        if (cost <= x) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}