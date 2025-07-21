#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> q(m);
    set<ll> rows, cols, d1, d2;
    set<pll> occupied;

    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
        rows.insert(q[i].first);
        cols.insert(q[i].second);
        d1.insert(q[i].first - q[i].second);
        d2.insert(q[i].first + q[i].second);
        occupied.insert(q[i]);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * n;
    unsafe += cols.size() * n;
    unsafe -= rows.size() * cols.size();

    // Diagonals (i - j)
    for (auto &d : d1) {
        ll cnt = n - abs(d);
        unsafe += cnt;
    }

    // Anti-diagonals (i + j)
    for (auto &d : d2) {
        ll cnt;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - d + 1;
        }
        unsafe += cnt;
    }

    // Subtract intersections between rows/columns and diagonals/anti-diagonals
    for (auto &d : d1) {
        set<pll> intersections;
        for (auto &r : rows) {
            pll p = {r, r - d};
            if (inBounds(p, n)) {
                intersections.insert(p);
            }
        }
        for (auto &c : cols) {
            pll p = {c + d, c};
            if (inBounds(p, n)) {
                intersections.insert(p);
            }
        }
        unsafe -= intersections.size();
    }

    for (auto &d : d2) {
        set<pll> intersections;
        for (auto &r : rows) {
            pll p = {r, d - r};
            if (inBounds(p, n)) {
                intersections.insert(p);
            }
        }
        for (auto &c : cols) {
            pll p = {d - c, c};
            if (inBounds(p, n)) {
                intersections.insert(p);
            }
        }
        for (auto &od : d1) {
            ll i = (d + od) / 2;
            ll j = (d - od) / 2;
            if ((d + od) % 2 != 0) continue;
            pll p = {i, j};
            if (inBounds(p, n)) {
                intersections.insert(p);
            }
        }
        unsafe -= intersections.size();
    }

    // Add back the intersections between diagonals and anti-diagonals
    set<pll> diagonal_intersections;
    for (auto &d1_val : d1) {
        for (auto &d2_val : d2) {
            ll i = (d2_val + d1_val) / 2;
            ll j = (d2_val - d1_val) / 2;
            if ((d2_val + d1_val) % 2 != 0 || (d2_val - d1_val) % 2 != 0) continue;
            pll p = {i, j};
            if (inBounds(p, n)) {
                diagonal_intersections.insert(p);
            }
        }
    }
    unsafe += diagonal_intersections.size();

    // Subtract the occupied squares since they are already counted in unsafe but not available
    ll total = n * n;
    ll safe = total - unsafe - (m - occupied.size());

    cout << max(safe, 0LL) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}