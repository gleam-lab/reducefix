#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;
    vector<array<i64, 2>> pieces;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares attacked by existing pieces
    i64 attacked = 0;

    // Count attacked cells in all rows with a piece
    for (auto r : rows) {
        attacked += N;
    }

    // Count attacked cells in all columns with a piece
    for (auto c : cols) {
        attacked += N;
    }

    // Subtract overlaps: cells where row and column intersect (double-counted)
    for (auto r : rows) {
        for (auto c : cols) {
            attacked--; // Each such cell was counted twice
        }
    }

    // Add attacked cells on diagonals (a+b) and anti-diagonals (a-b)
    // We calculate the number of cells on each diagonal
    auto diag_len = [&](i64 s) {
        i64 lo = max(1LL, s - N), hi = min(N, s - 1);
        return max(0LL, hi - lo + 1);
    };

    auto antidiag_len = [&](i64 d) {
        i64 lo = max(1LL, d + 1), hi = min(N, N + d);
        return max(0LL, hi - lo + 1);
    };

    for (auto d : diag1) {
        attacked += diag_len(d);
    }

    for (auto d : diag2) {
        attacked += antidiag_len(d);
    }

    // Subtract overlaps between diagonals and rows/columns
    for (auto [x, y] : pieces) {
        // These cells are already counted in row/col/diag
        // So we subtract them to avoid triple-counting
        attacked -= 3;
    }

    // Subtract overlaps between diagonals themselves
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve x + y = d1 and x - y = d2
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked--;
            }
        }
    }

    // Subtract overlaps between diagonals and rows/columns
    for (auto d : diag1) {
        for (auto r : rows) {
            i64 y = d - r;
            if (y >= 1 && y <= N) {
                attacked--;
            }
        }
        for (auto c : cols) {
            i64 x = d - c;
            if (x >= 1 && x <= N) {
                attacked--;
            }
        }
    }

    for (auto d : diag2) {
        for (auto r : rows) {
            i64 y = r - d;
            if (y >= 1 && y <= N) {
                attacked--;
            }
        }
        for (auto c : cols) {
            i64 x = c + d;
            if (x >= 1 && x <= N) {
                attacked--;
            }
        }
    }

    // Total unattacked squares
    i64 total = N * N;
    i64 ans = total - attacked;

    cout << ans << "\n";
    return 0;
}