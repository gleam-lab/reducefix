#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pll> queens(m);
    for (int i = 0; i < m; ++i) {
        cin >> queens[i].first >> queens[i].second;
    }

    set<ll> rows, cols, diag1, diag2;
    for (auto &q : queens) {
        rows.insert(q.first);
        cols.insert(q.second);
        diag1.insert(q.first - q.second);
        diag2.insert(q.first + q.second);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * n;
    unsafe += cols.size() * n;
    unsafe -= rows.size() * cols.size(); // Subtract intersections counted twice

    // Diagonals (i - j)
    for (auto &d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = n - d;
        } else {
            cnt = n + d;
        }
        unsafe += cnt;
    }

    // Diagonals (i + j)
    for (auto &d : diag2) {
        ll cnt;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - d + 1;
        }
        unsafe += cnt;
    }

    // Subtract intersections between rows/columns and diagonals
    set<pll> intersections;
    for (auto &r : rows) {
        for (auto &c : cols) {
            intersections.insert({r, c});
        }
    }
    for (auto &d1 : diag1) {
        for (auto &d2 : diag2) {
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && x >= 1 && x <= n && y >= 1 && y <= n) {
                intersections.insert({x, y});
            }
        }
    }
    unsafe -= intersections.size();

    // Total safe squares
    ll total = n * n;
    ll answer = total - unsafe + m; // Add M because queens' positions were subtracted multiple times

    cout << answer << endl;
    return 0;
}