#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
        rows.insert(queens[i].first);
        cols.insert(queens[i].second);
        diag1.insert(queens[i].first - queens[i].second);
        diag2.insert(queens[i].first + queens[i].second);
    }

    ll total = N * N - M; // Total empty squares initially

    // Squares attacked by rows
    ll row_attacks = rows.size() * N;
    // Squares attacked by columns
    ll col_attacks = cols.size() * N;
    // Overlapping squares (attacked by both rows and columns)
    ll row_col_overlap = rows.size() * cols.size();

    // Squares attacked by diagonals (i - j)
    ll diag1_attacks = 0;
    for (ll d : diag1) {
        if (d >= 0) {
            diag1_attacks += N - d;
        } else {
            diag1_attacks += N + d;
        }
    }
    // Squares attacked by diagonals (i + j)
    ll diag2_attacks = 0;
    for (ll d : diag2) {
        if (d <= N + 1) {
            diag2_attacks += d - 1;
        } else {
            diag2_attacks += 2 * N - d + 1;
        }
    }

    // Subtract the overlaps between rows and diagonals, columns and diagonals, etc.
    // We need to compute the intersections between these sets.
    set<pair<ll, ll>> intersections;

    // Intersections between rows and diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Intersections between rows and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Intersections between cols and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Intersections between cols and diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Intersections between diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d2 + d1) % 2 == 0 && (d2 - d1) % 2 == 0) {
                ll r = (d2 + d1) / 2;
                ll c = (d2 - d1) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    intersections.insert({r, c});
                }
            }
        }
    }

    // Remove intersections that are already occupied by queens
    for (auto &queen : queens) {
        intersections.erase(queen);
    }

    // Total attacked squares: rows + cols + diag1 + diag2 - overlaps
    ll total_attacked = row_attacks + col_attacks - row_col_overlap + diag1_attacks + diag2_attacks - intersections.size();
    total -= total_attacked;

    cout << total << endl;

    return 0;
}