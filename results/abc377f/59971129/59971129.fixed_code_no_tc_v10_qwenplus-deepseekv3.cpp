#include<bits/stdc++.h>

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

    ll total_rows = rows.size();
    ll total_cols = cols.size();
    ll total_diag1 = diag1.size();
    ll total_diag2 = diag2.size();

    // Calculate the total forbidden squares due to rows and columns
    ll forbidden_rows_cols = total_rows * N + total_cols * N - total_rows * total_cols;

    // Calculate the total forbidden squares due to diagonals
    ll forbidden_diag1 = 0;
    for (auto d : diag1) {
        ll cnt;
        if (d > 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        forbidden_diag1 += cnt;
    }

    ll forbidden_diag2 = 0;
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        forbidden_diag2 += cnt;
    }

    // Calculate overlaps between diagonals and rows/columns
    ll overlap_rows_diag1 = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                overlap_rows_diag1++;
            }
        }
    }

    ll overlap_cols_diag1 = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r >= 1 && r <= N) {
                overlap_cols_diag1++;
            }
        }
    }

    ll overlap_rows_diag2 = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                overlap_rows_diag2++;
            }
        }
    }

    ll overlap_cols_diag2 = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                overlap_cols_diag2++;
            }
        }
    }

    ll overlap_diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                overlap_diag1_diag2++;
            }
        }
    }

    // Apply inclusion-exclusion principle to calculate total forbidden squares
    ll total_forbidden = forbidden_rows_cols + forbidden_diag1 + forbidden_diag2
                        - overlap_rows_diag1 - overlap_cols_diag1
                        - overlap_rows_diag2 - overlap_cols_diag2
                        + overlap_diag1_diag2;

    // Total safe squares is total empty squares minus total forbidden squares (excluding existing pieces)
    ll total_empty = N * N - M;
    ll safe_squares = total_empty - (total_forbidden - M);

    cout << safe_squares << endl;

    return 0;
}