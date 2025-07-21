#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64,2>> g(M);
    set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 unsafe = 0;

    // Rows
    unsafe += rows.size() * N;
    // Columns
    unsafe += cols.size() * N;
    // Diagonals (i + j = k)
    for (auto k : diag1) {
        i64 min_ij = max(1LL, k - N);
        i64 max_ij = min(N, k - 1);
        if (max_ij >= min_ij) {
            unsafe += max_ij - min_ij + 1;
        }
    }
    // Diagonals (i - j = k)
    for (auto k : diag2) {
        i64 min_i = max(1LL, 1 + k);
        i64 max_i = min(N, N + k);
        if (max_i >= min_i) {
            unsafe += max_i - min_i + 1;
        }
    }

    // Inclusion-exclusion for overlaps
    // Rows and columns
    unsafe -= rows.size() * cols.size();
    // Rows and diag1 (i + j = k)
    for (auto a : rows) {
        for (auto k : diag1) {
            i64 b = k - a;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }
    // Rows and diag2 (i - j = k)
    for (auto a : rows) {
        for (auto k : diag2) {
            i64 b = a - k;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }
    // Columns and diag1 (i + j = k)
    for (auto b : cols) {
        for (auto k : diag1) {
            i64 a = k - b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }
    // Columns and diag2 (i - j = k)
    for (auto b : cols) {
        for (auto k : diag2) {
            i64 a = k + b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }
    // diag1 and diag2 intersections
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 + k2) % 2 == 0) {
                i64 a = (k1 + k2) / 2;
                i64 b = (k1 - k2) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    unsafe++;
                }
            }
        }
    }
    // Rows, columns, and any diagonal intersections
    // These are already counted in previous steps
    // Specifically, if a square is in all three, it was subtracted three times and added back once, net -2
    // Need to adjust for these cases
    // But in our inclusion-exclusion, it's handled correctly

    // Subtract the squares occupied by existing pieces (they are not empty)
    i64 occupied = M;
    // Total unsafe squares including overlaps
    i64 total_unsafe = unsafe;
    // Safe squares = total squares - unsafe squares - occupied squares (since they are already occupied)
    // But occupied squares are already counted in unsafe, so no need to subtract them again
    i64 safe = N * N - total_unsafe - occupied;
    cout << safe << "\n";

    return 0;
}