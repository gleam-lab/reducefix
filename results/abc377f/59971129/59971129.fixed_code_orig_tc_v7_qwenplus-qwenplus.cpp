#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    set<pll> occupied;
    set<ll> row, col, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        row.insert(a);
        col.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total empty squares
    ll total_empty = N * N - M;

    // Squares attacked by row or column
    set<ll> attacked_rows(row.begin(), row.end());
    set<ll> attacked_cols(col.begin(), col.end());

    ll attacked_by_row_or_col = (N - row.size()) * col.size() + (N - col.size()) * row.size();
    // But we double-counted the intersections: (non-occupied squares in both attacked rows and cols)
    ll overlap = 0;
    for (ll r : row) {
        for (ll c : col) {
            if (!occupied.count({r, c})) {
                overlap++;
            }
        }
    }
    attacked_by_row_or_col -= overlap;

    // Now attack via diagonals
    set<pll> attacked_by_diag;

    for (ll d : diag1) {
        for (ll r : row) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                attacked_by_diag.insert({r, c});
            }
        }
        for (ll c : col) {
            ll r = d + c;
            if (1 <= r && r <= N) {
                attacked_by_diag.insert({r, c});
            }
        }
    }

    for (ll d : diag2) {
        for (ll r : row) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                attacked_by_diag.insert({r, c});
            }
        }
        for (ll c : col) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                attacked_by_diag.insert({r, c});
            }
        }
    }

    // Remove already occupied and overlapping with row/col attacks
    for (auto p : attacked_by_diag) {
        if (!occupied.count(p) && !attacked_by_row_or_col.count(p)) {
            total_empty--;
        }
    }

    cout << total_empty << endl;
    return 0;
}