#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> a(M), b(M);
    unordered_set<ll> rows, cols, diags, anti_diags;

    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diags.insert(a[i] + b[i]);
        anti_diags.insert(a[i] - b[i]);
    }

    ll total = N * N;
    ll attacked = 0;

    // Attacked by rows
    attacked += rows.size() * N;
    // Attacked by columns
    attacked += cols.size() * N;
    // Attacked by diagonals (i + j = k)
    for (ll d : diags) {
        ll lower = max(1LL, d - N);
        ll upper = min(N, d - 1);
        if (lower <= upper) {
            attacked += upper - lower + 1;
        }
    }
    // Attacked by anti-diagonals (i - j = k)
    for (ll d : anti_diags) {
        ll lower = max(1LL, 1 + d);
        ll upper = min(N, N + d);
        if (lower <= upper) {
            attacked += upper - lower + 1;
        }
    }

    // Inclusion-exclusion for overlaps
    // Overlap between rows and columns
    ll row_col = rows.size() * cols.size();
    attacked -= row_col;

    // Overlap between rows and diagonals
    ll row_diag = 0;
    for (ll r : rows) {
        for (ll d : diags) {
            ll j = d - r;
            if (1 <= j && j <= N) {
                row_diag++;
            }
        }
    }
    attacked -= row_diag;

    // Overlap between rows and anti-diagonals
    ll row_anti_diag = 0;
    for (ll r : rows) {
        for (ll d : anti_diags) {
            ll j = r - d;
            if (1 <= j && j <= N) {
                row_anti_diag++;
            }
        }
    }
    attacked -= row_anti_diag;

    // Overlap between columns and diagonals
    ll col_diag = 0;
    for (ll c : cols) {
        for (ll d : diags) {
            ll i = d - c;
            if (1 <= i && i <= N) {
                col_diag++;
            }
        }
    }
    attacked -= col_diag;

    // Overlap between columns and anti-diagonals
    ll col_anti_diag = 0;
    for (ll c : cols) {
        for (ll d : anti_diags) {
            ll i = d + c;
            if (1 <= i && i <= N) {
                col_anti_diag++;
            }
        }
    }
    attacked -= col_anti_diag;

    // Overlap between diagonals and anti-diagonals
    ll diag_anti_diag = 0;
    for (ll d1 : diags) {
        for (ll d2 : anti_diags) {
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    diag_anti_diag++;
                }
            }
        }
    }
    attacked -= diag_anti_diag;

    // Overlap between rows, columns, and diagonals
    ll row_col_diag = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            ll d = r + c;
            if (diags.find(d) != diags.end()) {
                row_col_diag++;
            }
        }
    }
    attacked += row_col_diag;

    // Overlap between rows, columns, and anti-diagonals
    ll row_col_anti_diag = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            ll d = r - c;
            if (anti_diags.find(d) != anti_diags.end()) {
                row_col_anti_diag++;
            }
        }
    }
    attacked += row_col_anti_diag;

    // Overlap between rows, diagonals, and anti-diagonals
    ll row_diag_anti_diag = 0;
    for (ll r : rows) {
        for (ll d1 : diags) {
            ll j = d1 - r;
            if (1 <= j && j <= N) {
                ll d2 = r - j;
                if (anti_diags.find(d2) != anti_diags.end()) {
                    row_diag_anti_diag++;
                }
            }
        }
    }
    attacked += row_diag_anti_diag;

    // Overlap between columns, diagonals, and anti-diagonals
    ll col_diag_anti_diag = 0;
    for (ll c : cols) {
        for (ll d1 : diags) {
            ll i = d1 - c;
            if (1 <= i && i <= N) {
                ll d2 = i - c;
                if (anti_diags.find(d2) != anti_diags.end()) {
                    col_diag_anti_diag++;
                }
            }
        }
    }
    attacked += col_diag_anti_diag;

    // Overlap between rows, columns, diagonals, and anti-diagonals
    ll all_four = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            ll d1 = r + c;
            ll d2 = r - c;
            if (diags.find(d1) != diags.end() && anti_diags.find(d2) != anti_diags.end()) {
                all_four++;
            }
        }
    }
    attacked -= all_four;

    ll safe = total - attacked + M; // Since M squares are already occupied, they were subtracted multiple times.
    cout << safe << endl;

    return 0;
}