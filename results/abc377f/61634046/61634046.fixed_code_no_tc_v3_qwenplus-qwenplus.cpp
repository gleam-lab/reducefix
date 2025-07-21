#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr int MAX_M = 2000;

int main() {
    ll N;
    int M;
    cin >> N >> M;

    set<pii> occupied;
    set<ll> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.emplace(a, b);
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares not attacked by any piece
    ll total = N * N;

    // Subtract squares attacked by existing pieces
    total -= (ll)rows.size() * N; // All rows with pieces
    total -= (ll)cols.size() * N; // All columns with pieces
    total -= (ll)diag1.size() * N; // Diagonals (\)
    total -= (ll)diag2.size() * N; // Anti-diagonals (/)

    // Inclusion-Exclusion principle to add back over-subtracted overlaps

    // Row-Col intersections (already counted in occupied cells)
    for (ll r : rows) {
        for (ll c : cols) {
            if (!occupied.count({r, c})) {
                total += 1; // Was subtracted twice: once in row, once in col
            }
        }
    }

    // Row-Diag1 intersections
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (1 <= c && c <= N && !occupied.count({r, c})) {
                total += 1; // Was subtracted twice: row and diag1
            }
        }
    }

    // Row-Diag2 intersections
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N && !occupied.count({r, c})) {
                total += 1; // Was subtracted twice: row and diag2
            }
        }
    }

    // Col-Diag1 intersections
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N && !occupied.count({r, c})) {
                total += 1; // Was subtracted twice: col and diag1
            }
        }
    }

    // Col-Diag2 intersections
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d + c;
            if (1 <= r && r <= N && !occupied.count({r, c})) {
                total += 1; // Was subtracted twice: col and diag2
            }
        }
    }

    // Diag1-Diag2 intersections
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N &&
                !occupied.count({r, c})) {
                total += 1; // Was subtracted twice: diag1 and diag2
            }
        }
    }

    // Add back triple overlaps removed too many times

    // Row-Col-Diag1
    for (ll r : rows) {
        for (ll c : cols) {
            ll d1 = r + c;
            if (diag1.count(d1) && !occupied.count({r, c})) {
                total -= 1;
            }
        }
    }

    // Row-Col-Diag2
    for (ll r : rows) {
        for (ll c : cols) {
            ll d2 = r - c;
            if (diag2.count(d2) && !occupied.count({r, c})) {
                total -= 1;
            }
        }
    }

    // Row-Diag1-Diag2
    for (ll r : rows) {
        for (ll d1 : diag1) {
            for (ll d2 : diag2) {
                ll c1 = d1 - r;
                ll c2 = r - d2;
                if (c1 == c2 && 1 <= c1 && c1 <= N && !occupied.count({r, c1})) {
                    total -= 1;
                }
            }
        }
    }

    // Col-Diag1-Diag2
    for (ll c : cols) {
        for (ll d1 : diag1) {
            for (ll d2 : diag2) {
                ll r1 = d1 - c;
                ll r2 = d2 + c;
                if (r1 == r2 && 1 <= r1 && r1 <= N && !occupied.count({r1, c})) {
                    total -= 1;
                }
            }
        }
    }

    // Add back quadruple overlaps
    for (ll r : rows) {
        for (ll c : cols) {
            ll d1 = r + c;
            ll d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2) && !occupied.count({r, c})) {
                total += 1;
            }
        }
    }

    // Finally, remove the occupied cells entirely
    total -= M;

    cout << total << endl;

    return 0;
}