#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = N * N;
    ll row_attack = rows.size() * N;
    ll col_attack = cols.size() * N;
    ll row_col_overlap = rows.size() * cols.size();
    ll diag1_attack = 0;
    for (ll d : diag1) {
        if (d >= 0) {
            diag1_attack += N - d;
        } else {
            diag1_attack += N + d;
        }
    }
    ll diag2_attack = 0;
    for (ll d : diag2) {
        if (d <= N + 1) {
            diag2_attack += d - 1;
        } else {
            diag2_attack += 2 * N - d + 1;
        }
    }

    total -= row_attack + col_attack - row_col_overlap;
    total -= diag1_attack + diag2_attack;

    // Now, add back overlaps between diagonals and rows/columns
    // and between diagonals themselves
    set<pair<ll, ll>> intersections;

    // Overlap between row and diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Overlap between col and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Overlap between row and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Overlap between col and diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Overlap between diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 &&
                1 <= x && x <= N && 1 <= y && y <= N) {
                intersections.insert({x, y});
            }
        }
    }

    total += intersections.size();

    cout << total << endl;
    return 0;
}