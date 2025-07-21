#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_M = 2005;

int N, M;

set<int> rows, cols;
set<int> diag1, diag2;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    int total = N * N;

    // Subtract all squares attacked by existing pieces
    // Each square is uniquely defined by its row, column, diagonal (x+y), or anti-diagonal (x-y)
    // We count the number of unique such squares that are attacked.

    // Total attacked squares = sum over rows + sum over cols + sum over diag1 + sum over diag2
    // But we must subtract overlaps between these sets to avoid double-counting.
    // We use inclusion-exclusion principle:
    // |A ∪ B ∪ C ∪ D| = |A| + |B| + |C| + |D| - |A∩B| - |A∩C| - |A∩D| - |B∩C| - |B∩D| - |C∩D| 
    //                  + |A∩B∩C| + ... - |A∩B∩C∩D|

    int attacked = 0;

    attacked += rows.size() * N; // All squares in occupied rows
    attacked += cols.size() * N; // All squares in occupied columns
    for (int d : diag1) attacked += N; // All squares in occupied diagonals (x+y)
    for (int d : diag2) attacked += N; // All squares in occupied anti-diagonals (x-y)

    // Subtract overlaps: row & col
    for (int r : rows) {
        for (int c : cols) {
            // intersection of row r and column c is one square (r,c)
            --attacked;
        }
    }

    // Subtract overlaps: row & diag1
    for (int r : rows) {
        for (int d : diag1) {
            // x = r, x+y = d => y = d - r
            int y = d - r;
            if (1 <= y && y <= N) --attacked;
        }
    }

    // Subtract overlaps: row & diag2
    for (int r : rows) {
        for (int d : diag2) {
            // x = r, x - y = d => y = r - d
            int y = r - d;
            if (1 <= y && y <= N) --attacked;
        }
    }

    // Subtract overlaps: col & diag1
    for (int c : cols) {
        for (int d : diag1) {
            // y = c, x + y = d => x = d - c
            int x = d - c;
            if (1 <= x && x <= N) --attacked;
        }
    }

    // Subtract overlaps: col & diag2
    for (int c : cols) {
        for (int d : diag2) {
            // y = c, x - y = d => x = d + c
            int x = d + c;
            if (1 <= x && x <= N) --attacked;
        }
    }

    // Subtract overlaps: diag1 & diag2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            // x + y = d1, x - y = d2 => x = (d1 + d2)/2, y = (d1 - d2)/2
            if ((d1 + d2) % 2 != 0 || (d1 - d2) % 2 != 0) continue;
            int x = (d1 + d2) / 2;
            int y = (d1 - d2) / 2;
            if (1 <= x && x <= N && 1 <= y && y <= N) --attacked;
        }
    }

    // Add back overlaps: row & col & diag1
    for (int r : rows) {
        for (int c : cols) {
            int d = r + c;
            if (diag1.count(d)) {
                // (r,c) is on this diag1
                ++attacked;
            }
        }
    }

    // Add back overlaps: row & col & diag2
    for (int r : rows) {
        for (int c : cols) {
            int d = r - c;
            if (diag2.count(d)) {
                // (r,c) is on this diag2
                ++attacked;
            }
        }
    }

    // Add back overlaps: row & diag1 & diag2
    for (int r : rows) {
        for (int d1 : diag1) {
            for (int d2 : diag2) {
                int x = (d1 + d2) / 2;
                int y = (d1 - d2) / 2;
                if (x == r && 1 <= x && x <= N && 1 <= y && y <= N) ++attacked;
            }
        }
    }

    // Add back overlaps: col & diag1 & diag2
    for (int c : cols) {
        for (int d1 : diag1) {
            for (int d2 : diag2) {
                int x = (d1 + d2) / 2;
                int y = (d1 - d2) / 2;
                if (y == c && 1 <= x && x <= N && 1 <= y && y <= N) ++attacked;
            }
        }
    }

    // Subtract overlaps: row & col & diag1 & diag2
    for (int r : rows) {
        for (int c : cols) {
            int d1 = r + c;
            int d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2)) ++attacked;
        }
    }

    // Now subtract the attacked squares from total
    cout << N * N - attacked << endl;

    return 0;
}