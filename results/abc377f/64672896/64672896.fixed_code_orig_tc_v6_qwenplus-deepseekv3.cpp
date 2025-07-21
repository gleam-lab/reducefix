#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    set<i64> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 total = N * N;
    i64 covered = 0;

    // Rows
    covered += rows.size() * N;
    // Columns
    covered += cols.size() * N;
    // Diagonals i+j = k
    for (auto k : diag1) {
        i64 low = max(1LL, k - N);
        i64 high = min(N, k - 1);
        if (low <= high) {
            covered += high - low + 1;
        }
    }
    // Diagonals i-j = k
    for (auto k : diag2) {
        i64 low = max(1LL, 1 + k);
        i64 high = min(N, N + k);
        if (low <= high) {
            covered += high - low + 1;
        }
    }

    // Inclusion-exclusion for overlaps between rows, cols, diag1, diag2
    // Subtract overlaps between rows and cols
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                covered -= 3;
            } else if (diag1.count(r + c) || diag2.count(r - c)) {
                covered -= 1;
            }
        }
    }

    // Subtract overlaps between rows and diag1
    for (auto r : rows) {
        for (auto k : diag1) {
            i64 c = k - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) && diag2.count(r - c)) {
                    covered -= 2;
                } else if (cols.count(c) || diag2.count(r - c)) {
                    covered -= 0;
                } else {
                    covered -= 1;
                }
            }
        }
    }

    // Subtract overlaps between rows and diag2
    for (auto r : rows) {
        for (auto k : diag2) {
            i64 c = r - k;
            if (c >= 1 && c <= N) {
                if (cols.count(c) && diag1.count(r + c)) {
                    covered -= 2;
                } else if (cols.count(c) || diag1.count(r + c)) {
                    covered -= 0;
                } else {
                    covered -= 1;
                }
            }
        }
    }

    // Subtract overlaps between cols and diag1
    for (auto c : cols) {
        for (auto k : diag1) {
            i64 r = k - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) && diag2.count(r - c)) {
                    covered -= 2;
                } else if (rows.count(r) || diag2.count(r - c)) {
                    covered -= 0;
                } else {
                    covered -= 1;
                }
            }
        }
    }

    // Subtract overlaps between cols and diag2
    for (auto c : cols) {
        for (auto k : diag2) {
            i64 r = k + c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) && diag1.count(r + c)) {
                    covered -= 2;
                } else if (rows.count(r) || diag1.count(r + c)) {
                    covered -= 0;
                } else {
                    covered -= 1;
                }
            }
        }
    }

    // Add overlaps between rows, cols, diag1, diag2 (all four)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                covered += 1;
            }
        }
    }

    // The safe squares
    i64 safe = total - covered + M; // M is added because the existing pieces are subtracted but they are not empty
    cout << safe << "\n";

    return 0;
}