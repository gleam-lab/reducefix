#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    ll total = N * N;
    ll attacked = 0;

    // Rows
    attacked += rows.size() * N;
    // Columns
    attacked += cols.size() * N;
    // Diagonals (a - b = constant)
    for (auto d : diag1) {
        ll start_row, start_col;
        if (d >= 0) {
            start_row = 1 + d;
            start_col = 1;
        } else {
            start_row = 1;
            start_col = 1 - d;
        }
        ll length = N - max(start_row - 1, start_col - 1);
        if (start_row > N || start_col > N) {
            length = 0;
        } else {
            length = min(N - start_row + 1, N - start_col + 1);
        }
        attacked += length;
    }
    // Diagonals (a + b = constant)
    for (auto d : diag2) {
        ll start_row, start_col;
        if (d <= N + 1) {
            start_row = 1;
            start_col = d - 1;
        } else {
            start_row = d - N;
            start_col = N;
        }
        ll length;
        if (start_col < 1 || start_row > N) {
            length = 0;
        } else {
            length = min(start_col, N - start_row + 1);
        }
        attacked += length;
    }

    // Subtract intersections between rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if (diag1.count(r - c) && diag2.count(r + c)) {
                attacked -= 3;
            } else if (diag1.count(r - c) || diag2.count(r + c)) {
                attacked -= 2;
            } else {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections between rows and diag1
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c < 1 || c > N) continue;
            if (pieces.count({r, c})) continue;
            if (cols.count(c) && diag2.count(r + c)) {
                attacked -= 2;
            } else if (cols.count(c) || diag2.count(r + c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections between rows and diag2
    for (auto r : rows) {
        for (auto d2 : diag2) {
            ll c = d2 - r;
            if (c < 1 || c > N) continue;
            if (pieces.count({r, c})) continue;
            if (cols.count(c) && diag1.count(r - c)) {
                attacked -= 2;
            } else if (cols.count(c) || diag1.count(r - c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections between columns and diag1
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (r < 1 || r > N) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) && diag2.count(r + c)) {
                attacked -= 2;
            } else if (rows.count(r) || diag2.count(r + c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections between columns and diag2
    for (auto c : cols) {
        for (auto d2 : diag2) {
            ll r = d2 - c;
            if (r < 1 || r > N) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) && diag1.count(r - c)) {
                attacked -= 2;
            } else if (rows.count(r) || diag1.count(r - c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r < 1 || r > N || c < 1 || c > N) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) && cols.count(c)) {
                attacked -= 2;
            } else if (rows.count(r) || cols.count(c)) {
                attacked -= 1;
            }
        }
    }

    // Add back the squares that are counted in all three sets (row, column, diag1, diag2)
    for (auto r : rows) {
        for (auto c : cols) {
            if (!pieces.count({r, c}) && diag1.count(r - c) && diag2.count(r + c)) {
                attacked += 1;
            }
        }
    }

    // The answer is total squares minus attacked squares minus occupied squares plus squares that are both attacked and occupied (which is zero since occupied squares are already excluded)
    ll answer = total - attacked - M + pieces.size();
    cout << answer << "\n";
    return 0;
}