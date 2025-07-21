#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using ll = long long;

ll f(ll x, ll a, ll b, ll p, ll q) {
    ll dp = 0;
    ll costA = (x - 1) / a + 1; // Maximum number of a's that can be bought
    ll costB = (x - 1) / b + 1; // Maximum number of b's that can be bought
    ll maxCost = min(costA, costB) * max(p, q);
    dp = max(dp, maxCost);

    for (ll i = 1; i <= costA; ++i) {
        ll remaining = x - i * a;
        ll cost = i * p + (remaining > 0 ? remaining / b : 0) * q;
        dp = min(dp, cost);
    }

    for (ll i = 1; i <= costB; ++i) {
        ll remaining = x - i * b;
        ll cost = i * q + (remaining > 0 ? remaining / a : 0) * p;
        dp = min(dp, cost);
    }

    return dp;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> items(n); // Pair of cost and profit
    rep(i, n) {
        ll a, p, b, q;
        cin >> a >> p >> b >> q;
        items[i] = {a, p};
        items.push_back({b, q});
    }

    sort(items.begin(), items.end()); // Sort by cost in ascending order

    ll left = 0, right = 10000000000;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        ll tmp = 0;
        rep(i, n) {
            ll cost = f(mid, items[i].first, items[n + i].first, items[i].second, items[n + i].second);
            tmp += cost;
            if (tmp > x) break;
        }
        if (tmp <= x) left = mid;
        else right = mid;
    }

    cout << left;
    return 0;
}