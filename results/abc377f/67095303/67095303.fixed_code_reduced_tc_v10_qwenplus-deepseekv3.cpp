#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2; // diag1: i+j, diag2: i-j

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int total_safe = N * N - M; // Subtract M for occupied squares

    // Subtract squares under attack by rows and columns
    int row_attack = rows.size() * N;
    int col_attack = cols.size() * N;
    int row_col_intersect = rows.size() * cols.size();

    int under_row_or_col = row_attack + col_attack - row_col_intersect;
    total_safe -= under_row_or_col;

    // Add back the squares under attack by both row and column (they were subtracted twice)
    total_safe += row_col_intersect;

    // Now handle diagonal attacks
    // For diag1 (i+j = d)
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int length = max_i - min_i + 1;

        // Subtract squares under attack by this diagonal that are not already under row or column attack
        int new_under_diag1 = length;
        // Subtract squares that are in rows or cols
        for (int r : rows) {
            if (d - r >= 1 && d - r <= N) {
                new_under_diag1--;
            }
        }
        for (int c : cols) {
            if (d - c >= 1 && d - c <= N) {
                new_under_diag1--;
            }
        }
        for (int d2 : diag2) {
            // Check intersection points between diag1 and diag2
            if ((d + d2) % 2 == 0 && (d - d2) % 2 == 0) {
                int i = (d + d2) / 2;
                int j = (d - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    if (rows.count(i) || cols.count(j)) {
                        continue;
                    } else {
                        new_under_diag1--;
                    }
                }
            }
        }
        total_safe -= max(0LL, new_under_diag1);
    }

    // For diag2 (i-j = d)
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int length = max_i - min_i + 1;

        // Subtract squares under attack by this diagonal that are not already under row or column attack
        int new_under_diag2 = length;
        // Subtract squares that are in rows or cols
        for (int r : rows) {
            if (r - d >= 1 && r - d <= N) {
                new_under_diag2--;
            }
        }
        for (int c : cols) {
            if (c + d >= 1 && c + d <= N) {
                new_under_diag2--;
            }
        }
        for (int d1 : diag1) {
            // Check intersection points between diag1 and diag2
            if ((d1 + d) % 2 == 0 && (d1 - d) % 2 == 0) {
                int i = (d1 + d) / 2;
                int j = (d1 - d) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    if (rows.count(i) || cols.count(j)) {
                        continue;
                    } else {
                        new_under_diag2--;
                    }
                }
            }
        }
        total_safe -= max(0LL, new_under_diag2);
    }

    // Now, add back the squares that were subtracted twice (under both diagonals)
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    if (!rows.count(i) && !cols.count(j)) {
                        total_safe++;
                    }
                }
            }
        }
    }

    cout << total_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}