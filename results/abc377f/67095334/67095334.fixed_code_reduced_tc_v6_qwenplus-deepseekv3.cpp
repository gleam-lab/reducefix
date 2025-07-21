#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int total_safe = 0;

    // Total squares: N^2
    // Squares in rows under attack: |rows| * N
    // Squares in cols under attack: |cols| * N
    // Subtracting the squares counted twice (rows and cols): + |rows intersect cols|
    int rows_attack = rows.size() * N;
    int cols_attack = cols.size() * N;
    int rows_cols_intersect = 0;
    for (int r : rows) {
        if (cols.find(r) != cols.end()) {
            rows_cols_intersect++;
        }
    }
    int rows_cols_common = rows_attack + cols_attack - rows.size() * cols.size();

    // Diagonals type 1 (i + j = d)
    int diag1_attack = 0;
    for (int d : diag1) {
        int len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N - d + 1;
        }
        diag1_attack += len;
    }

    // Diagonals type 2 (i - j = d)
    int diag2_attack = 0;
    for (int d : diag2) {
        int len;
        if (d >= 0) {
            len = N - d;
        } else {
            len = N + d;
        }
        diag2_attack += len;
    }

    // Overlaps between diag1 and diag2
    int diag_overlap = 0;
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    diag_overlap++;
                }
            }
        }
    }

    // Overlaps between rows and diag1
    int rows_diag1_overlap = 0;
    for (int r : rows) {
        for (int d : diag1) {
            int j = d - r;
            if (j >= 1 && j <= N) {
                rows_diag1_overlap++;
            }
        }
    }

    // Overlaps between cols and diag1
    int cols_diag1_overlap = 0;
    for (int c : cols) {
        for (int d : diag1) {
            int i = d - c;
            if (i >= 1 && i <= N) {
                cols_diag1_overlap++;
            }
        }
    }

    // Overlaps between rows and diag2
    int rows_diag2_overlap = 0;
    for (int r : rows) {
        for (int d : diag2) {
            int j = r - d;
            if (j >= 1 && j <= N) {
                rows_diag2_overlap++;
            }
        }
    }

    // Overlaps between cols and diag2
    int cols_diag2_overlap = 0;
    for (int c : cols) {
        for (int d : diag2) {
            int i = c + d;
            if (i >= 1 && i <= N) {
                cols_diag2_overlap++;
            }
        }
    }

    // Overlaps between rows and cols
    int rows_cols_overlap = 0;
    for (int r : rows) {
        if (cols.find(r) != cols.end()) {
            rows_cols_overlap++;
        }
    }

    // Total under attack
    int total_attack = rows_attack + cols_attack + diag1_attack + diag2_attack
                     - rows_diag1_overlap - cols_diag1_overlap - rows_diag2_overlap - cols_diag2_overlap
                     + rows_cols_overlap - diag_overlap;

    total_safe = N * N - total_attack;

    cout << total_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}