#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll, ll>

using namespace std;

ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    set<PII> h, v, d1, d2;

    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        --x; --y; // Adjusting indices to zero-based for easier handling
        h.insert({x, y});
        v.insert({y, x});
        d1.insert({x + y, y});
        d2.insert({x - y, x});
    }

    ll total_squares = n * n;
    ll occupied_squares = h.size() + v.size();

    for (auto [sum, col] : d1) {
        set<ll> s;
        for (auto [x, y] : h) {
            if (x + y == sum) s.insert(y);
        }
        for (auto [y, x] : v) {
            if (x + y == sum) s.insert(y);
        }
        occupied_squares += (sum <= n) ? (min(sum, n) - s.size()) : (max(n - sum + 1, 1LL) - s.size());
    }

    for (auto [diff, row] : d2) {
        set<ll> s;
        for (auto [x, y] : h) {
            if (x - y == diff) s.insert(y);
        }
        for (auto [y, x] : v) {
            if (x - y == diff) s.insert(y);
        }
        for (auto [sum, col] : d1) {
            if ((sum + diff) % 2 == 0 && (sum - diff) % 2 == 0) {
                int si = (sum + diff) / 2, sj = (sum - diff) / 2;
                if (si >= 0 && si < n && sj >= 0 && sj < n) s.insert(si);
            }
        }
        occupied_squares += (diff >= 0) ? (min(diff, n) - s.size()) : (max(n - diff, 1LL) - s.size());
    }

    cout << (total_squares - occupied_squares) % mod << endl;

    return 0;
}