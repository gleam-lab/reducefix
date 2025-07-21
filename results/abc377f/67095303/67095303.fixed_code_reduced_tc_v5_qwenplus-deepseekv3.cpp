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

    int forbidden_rows = rows.size();
    int forbidden_cols = cols.size();
    int forbidden_diag1 = diag1.size();
    int forbidden_diag2 = diag2.size();

    // Calculate the total forbidden squares without considering overlaps
    int total_forbidden = forbidden_rows * N + forbidden_cols * N - forbidden_rows * forbidden_cols;

    // Now, account for the diagonals
    // For each diagonal in diag1, the number of squares is min(d-1, N) - max(1, d-N) + 1
    for (int d : diag1) {
        int min_col = max(1LL, d - N);
        int max_col = min(N, d - 1);
        if (min_col > max_col) continue;
        total_forbidden += (max_col - min_col + 1);
    }

    // For each diagonal in diag2, the number of squares is min(N, N - d) - max(1, 1 - d) + 1
    for (int d : diag2) {
        int min_col = max(1LL, 1 - d);
        int max_col = min(N, N - d);
        if (min_col > max_col) continue;
        total_forbidden += (max_col - min_col + 1);
    }

    // Now, subtract the overlaps between rows/cols and diagonals
    // For each piece, the intersection of row/col with diag1 and diag2 is already counted in the initial rows/cols
    // So, for each piece, subtract the overcounted squares
    // But since each piece's position is counted in all four sets, we need to subtract the overlaps correctly
    // Alternatively, consider that the initial total_forbidden double-counts the intersections

    // To avoid overcounting, we need to subtract the squares that are counted multiple times
    // Specifically:
    // 1. Squares that are in both a forbidden row and a forbidden diagonal (they are counted twice)
    // 2. Similarly for columns and diagonals
    // 3. Squares that are in both diagonals (counted twice)

    // Subtract overlaps between rows and diag1
    for (int d : diag1) {
        for (int r : rows) {
            int c = d - r;
            if (1 <= c && c <= N) {
                total_forbidden--;
            }
        }
    }

    // Subtract overlaps between cols and diag1
    for (int d : diag1) {
        for (int c : cols) {
            int r = d - c;
            if (1 <= r && r <= N) {
                total_forbidden--;
            }
        }
    }

    // Subtract overlaps between rows and diag2
    for (int d : diag2) {
        for (int r : rows) {
            int c = r - d;
            if (1 <= c && c <= N) {
                total_forbidden--;
            }
        }
    }

    // Subtract overlaps between cols and diag2
    for (int d : diag2) {
        for (int c : cols) {
            int r = d + c;
            if (1 <= r && r <= N) {
                total_forbidden--;
            }
        }
    }

    // Additionally, subtract overlaps between diag1 and diag2 (squares counted in both diagonals)
    // These are the squares where i + j = d1 and i - j = d2
    // So, i = (d1 + d2)/2, j = (d1 - d2)/2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    total_forbidden--;
                }
            }
        }
    }

    // The total safe squares is N*N - total_forbidden - M (since the existing pieces occupy squares)
    int total_safe = N * N - total_forbidden - M;
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