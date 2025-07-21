#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(pll a, ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pll> q(m);
    set<ll> rows, cols, diag1, diag2;
    for (auto &[a, b] : q) {
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = n * n;
    ll rows_cnt = rows.size();
    ll cols_cnt = cols.size();
    ll diag1_cnt = diag1.size();
    ll diag2_cnt = diag2.size();

    total -= rows_cnt * n;
    total -= cols_cnt * n;
    total += rows_cnt * cols_cnt;

    for (auto d : diag1) {
        ll min_ij = max(1LL, 1 + d);
        ll max_ij = min(n, n + d);
        if (min_ij > max_ij) continue;
        ll cnt = max_ij - min_ij + 1;
        total -= cnt;

        set<pll> intersections;
        for (auto r : rows) {
            pll p = {r, r - d};
            if (inBounds(p, n)) intersections.insert(p);
        }
        for (auto c : cols) {
            pll p = {c + d, c};
            if (inBounds(p, n)) intersections.insert(p);
        }
        total += intersections.size();
    }

    for (auto d : diag2) {
        ll min_sum = max(2LL, d - n + 1);
        ll max_sum = min(2 * n, d + n - 1);
        if (min_sum > max_sum) continue;
        ll cnt = (max_sum - min_sum) / 2 + 1;
        total -= cnt;

        set<pll> intersections;
        for (auto r : rows) {
            pll p = {r, d - r};
            if (inBounds(p, n)) intersections.insert(p);
        }
        for (auto c : cols) {
            pll p = {d - c, c};
            if (inBounds(p, n)) intersections.insert(p);
        }
        for (auto d1 : diag1) {
            ll i = (d + d1) / 2;
            ll j = (d - d1) / 2;
            if ((d + d1) % 2 != 0 || (d - d1) % 2 != 0) continue;
            pll p = {i, j};
            if (inBounds(p, n)) intersections.insert(p);
        }
        total += intersections.size();
    }

    cout << total << endl;
    return 0;
}