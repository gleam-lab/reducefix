#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);

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

    ll total_squares = N * N;
    ll threatened = 0;

    // Subtract rows and columns
    threatened += rows.size() * N;
    threatened += cols.size() * N;

    // Subtract diagonals and anti-diagonals
    for (ll d : diag1) {
        ll start_row = max(1LL, 1 + d);
        ll end_row = min(N, N + d);
        if (end_row < start_row) continue; // no squares in this diagonal
        threatened += (end_row - start_row + 1);
    }

    for (ll d : diag2) {
        ll start_row = max(1LL, d - N);
        ll end_row = min(N, d - 1);
        if (end_row < start_row) continue; // no squares in this anti-diagonal
        threatened += (end_row - start_row + 1);
    }

    // Add back intersections (inclusion-exclusion principle)
    // Rows and columns
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                threatened -= 3;
            } else if (diag1.count(r - c) || diag2.count(r + c)) {
                threatened -= 1;
            }
        }
    }

    // Rows and diagonals (main)
    for (ll r : rows) {
        for (ll d1 : diag1) {
            ll c = r - d1;
            if (c >= 1 && c <= N) {
                if (cols.count(c) && diag2.count(r + c)) {
                    threatened -= 2;
                } else if (cols.count(c) || diag2.count(r + c)) {
                    threatened -= 1;
                }
            }
        }
    }

    // Rows and anti-diagonals
    for (ll r : rows) {
        for (ll d2 : diag2) {
            ll c = d2 - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) && diag1.count(r - c)) {
                    threatened -= 2;
                } else if (cols.count(c) || diag1.count(r - c)) {
                    threatened -= 1;
                }
            }
        }
    }

    // Columns and diagonals (main)
    for (ll c : cols) {
        for (ll d1 : diag1) {
            ll r = c + d1;
            if (r >= 1 && r <= N) {
                if (rows.count(r) && diag2.count(r + c)) {
                    threatened -= 2;
                } else if (rows.count(r) || diag2.count(r + c)) {
                    threatened -= 1;
                }
            }
        }
    }

    // Columns and anti-diagonals
    for (ll c : cols) {
        for (ll d2 : diag2) {
            ll r = d2 - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) && diag1.count(r - c)) {
                    threatened -= 2;
                } else if (rows.count(r) || diag1.count(r - c)) {
                    threatened -= 1;
                }
            }
        }
    }

    // Diagonals and anti-diagonals intersections
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                if (rows.count(r) && cols.count(c)) {
                    threatened -= 3;
                } else if (rows.count(r) || cols.count(c)) {
                    threatened -= 1;
                }
            }
        }
    }

    // The squares occupied by existing pieces are added back once (since they were subtracted multiple times)
    threatened -= M;

    ll safe_squares = total_squares - threatened;
    cout << safe_squares << "\n";

    return 0;
}