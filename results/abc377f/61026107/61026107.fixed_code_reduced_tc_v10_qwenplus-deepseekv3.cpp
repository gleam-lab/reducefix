#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef HOME
#include<debug.h>
#else
#define dump(...)
#endif

void solve() {
    ll N, M; cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> intersections;

    for (int i = 0; i < M; ++i) {
        ll a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        intersections.insert({a, b});
    }

    ll total_squares = N * N;

    // Subtract squares covered by rows
    ll row_squares = rows.size() * N;
    total_squares -= row_squares;

    // Subtract squares covered by columns (excluding those already in rows)
    ll col_squares = cols.size() * N;
    total_squares -= col_squares;
    // Add back intersections of rows and columns (since they were subtracted twice)
    ll row_col_intersections = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (intersections.count({r, c})) continue;
            row_col_intersections++;
        }
    }
    total_squares += row_col_intersections;

    // Subtract squares covered by diag1 (a - b = constant)
    for (auto d : diag1) {
        ll min_x = max(1LL, 1 + d);
        ll max_x = min(N, N + d);
        if (max_x < min_x) continue;
        ll count = max_x - min_x + 1;
        total_squares -= count;
    }

    // Subtract squares covered by diag2 (a + b = constant)
    for (auto d : diag2) {
        ll min_x = max(1LL, d - N);
        ll max_x = min(N, d - 1);
        if (max_x < min_x) continue;
        ll count = max_x - min_x + 1;
        total_squares -= count;
    }

    // Add back intersections of rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll y = r - d;
            if (y < 1 || y > N) continue;
            if (intersections.count({r, y})) continue;
            if (cols.count(y)) continue; // already counted in row_col_intersections
            total_squares++;
        }
    }

    // Add back intersections of rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll y = d - r;
            if (y < 1 || y > N) continue;
            if (intersections.count({r, y})) continue;
            if (cols.count(y)) continue;
            total_squares++;
        }
    }

    // Add back intersections of cols and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll x = c + d;
            if (x < 1 || x > N) continue;
            if (intersections.count({x, c})) continue;
            if (rows.count(x)) continue;
            total_squares++;
        }
    }

    // Add back intersections of cols and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll x = d - c;
            if (x < 1 || x > N) continue;
            if (intersections.count({x, c})) continue;
            if (rows.count(x)) continue;
            total_squares++;
        }
    }

    // Add back intersections of diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if (x < 1 || x > N || y < 1 || y > N) continue;
            if (intersections.count({x, y})) continue;
            if (rows.count(x) || cols.count(y)) continue;
            total_squares++;
        }
    }

    // Subtract the squares occupied by existing pieces
    total_squares -= M;

    cout << total_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}