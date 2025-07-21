#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
        rows.insert(queens[i].first);
        cols.insert(queens[i].second);
        diag1.insert(queens[i].first - queens[i].second);
        diag2.insert(queens[i].first + queens[i].second);
    }

    ll total_squares = N * N;
    ll attacked = 0;

    // Squares attacked by rows or columns
    ll row_attacks = rows.size() * N;
    ll col_attacks = cols.size() * N;
    ll row_col_intersect = rows.size() * cols.size();

    attacked += row_attacks + col_attacks - row_col_intersect;

    // Squares attacked by diagonals (i - j = constant)
    for (ll d : diag1) {
        // Number of squares on diagonal i - j = d
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }

    // Squares attacked by anti-diagonals (i + j = constant)
    for (ll d : diag2) {
        // Number of squares on anti-diagonal i + j = d
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }

    // Now, subtract the overlaps between rows/columns and diagonals/anti-diagonals
    // Also, subtract overlaps between diagonals and anti-diagonals
    set<pll> intersection_points;

    // Intersection of rows and diagonals (i - j = d)
    for (ll r : rows) {
        for (ll d : diag1) {
            ll j = r - d;
            if (j >= 1 && j <= N) {
                intersection_points.insert({r, j});
            }
        }
    }

    // Intersection of columns and diagonals (i - j = d)
    for (ll c : cols) {
        for (ll d : diag1) {
            ll i = c + d;
            if (i >= 1 && i <= N) {
                intersection_points.insert({i, c});
            }
        }
    }

    // Intersection of rows and anti-diagonals (i + j = d)
    for (ll r : rows) {
        for (ll d : diag2) {
            ll j = d - r;
            if (j >= 1 && j <= N) {
                intersection_points.insert({r, j});
            }
        }
    }

    // Intersection of columns and anti-diagonals (i + j = d)
    for (ll c : cols) {
        for (ll d : diag2) {
            ll i = d - c;
            if (i >= 1 && i <= N) {
                intersection_points.insert({i, c});
            }
        }
    }

    // Intersection of diagonals (i - j = d1) and anti-diagonals (i + j = d2)
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                intersection_points.insert({i, j});
            }
        }
    }

    // Add the queen positions themselves, as they are already counted in the initial attacks
    for (pll q : queens) {
        intersection_points.insert(q);
    }

    // Subtract the intersections from the total attacked squares
    attacked -= intersection_points.size();

    // The safe squares are total_squares - attacked - M (since queens are placed on M squares)
    ll safe_squares = total_squares - attacked - M;
    cout << safe_squares << endl;

    return 0;
}