#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(ll i, ll j, ll n) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> queens(m);
    for (auto &q : queens) {
        cin >> q.first >> q.second;
    }

    set<ll> rows, cols, diag1, diag2;
    for (const auto &q : queens) {
        rows.insert(q.first);
        cols.insert(q.second);
        diag1.insert(q.first - q.second);
        diag2.insert(q.first + q.second);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * n;
    unsafe += cols.size() * n;
    unsafe -= rows.size() * cols.size(); // intersections

    // Diagonals (i-j)
    for (const auto &d : diag1) {
        ll cnt = n - abs(d);
        unsafe += cnt;
    }

    // Diagonals (i+j)
    for (const auto &d : diag2) {
        ll a, b;
        if (d <= n + 1) {
            a = d - 1;
        } else {
            a = 2 * n - d + 1;
        }
        unsafe += a;
    }

    // Subtract intersections between diagonals and rows/columns
    set<pll> intersections;

    // Intersections of diag1 with rows and columns
    for (const auto &d : diag1) {
        for (const auto &r : rows) {
            ll j = r - d;
            if (inBounds(r, j, n)) {
                intersections.insert({r, j});
            }
        }
        for (const auto &c : cols) {
            ll i = c + d;
            if (inBounds(i, c, n)) {
                intersections.insert({i, c});
            }
        }
    }

    // Intersections of diag2 with rows and columns
    for (const auto &d : diag2) {
        for (const auto &r : rows) {
            ll j = d - r;
            if (inBounds(r, j, n)) {
                intersections.insert({r, j});
            }
        }
        for (const auto &c : cols) {
            ll i = d - c;
            if (inBounds(i, c, n)) {
                intersections.insert({i, c});
            }
        }
    }

    // Intersections between diag1 and diag2
    for (const auto &d1 : diag1) {
        for (const auto &d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && inBounds(i, j, n)) {
                intersections.insert({i, j});
            }
        }
    }

    unsafe -= intersections.size();

    // Total safe squares
    ll total = n * n;
    ll safe = total - unsafe;
    safe -= m; // subtract the squares already occupied by queens
    safe += intersections.size(); // since these were subtracted twice

    cout << safe << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}