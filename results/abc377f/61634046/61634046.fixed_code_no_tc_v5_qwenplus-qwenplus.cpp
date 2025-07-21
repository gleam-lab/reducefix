#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 2000;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    set<int> rows, cols;
    set<long long> diag1, diag2;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(1LL * a + b); // anti-diagonal
        diag2.insert(1LL * a - b); // main diagonal
    }

    long long total = N * N;

    // Remove squares attacked by existing pieces
    // All rows and columns occupied or attacked
    long long attacked = N * (rows.size() + cols.size()) 
                       + (N * 2 - 1) * (diag1.size() + diag2.size());

    // Inclusion-Exclusion principle to subtract overlapping counts

    // Subtract overlaps between rows and columns
    attacked -= 1LL * rows.size() * cols.size();

    // Subtract overlaps between rows and diagonals
    for (int r : rows) {
        attacked -= diag1.count(r * 1LL + r) ? 1 : 0;
        attacked -= diag2.count(0LL) ? 1 : 0; // (r - r)
    }

    // Subtract overlaps between columns and diagonals
    for (int c : cols) {
        attacked -= diag1.count(c * 1LL + c) ? 1 : 0;
        attacked -= diag2.count(2LL * c) ? 1 : 0; // (c - c) = 0
    }

    // Subtract overlaps between diagonal types
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve:
            // x + y = d1
            // x - y = d2
            // => x = (d1 + d2)/2, y = (d1 - d2)/2
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                long long x = (d1 + d2) / 2;
                long long y = (d1 - d2) / 2;
                if (1 <= x && x <= N && 1 <= y && y <= N) {
                    attacked--;
                }
            }
        }
    }

    // Subtract overlaps already counted thrice (row, col, diag1, diag2)
    for (int r : rows) {
        for (int c : cols) {
            if (diag1.count(1LL * r + c) && diag2.count(1LL * r - c)) {
                attacked++;
            }
        }
    }

    // Subtract the M occupied squares themselves
    cout << total - attacked << endl;

    return 0;
}