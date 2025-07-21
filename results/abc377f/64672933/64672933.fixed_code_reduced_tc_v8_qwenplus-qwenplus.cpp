#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag_sum, diag_diff;
    set<pair<i64, i64>> occupied_cells;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag_sum.insert(a + b);
        diag_diff.insert(a - b);
        occupied_cells.insert({a, b});
    }

    // Count how many squares are attacked due to row, col, diag_sum, diag_diff
    i64 total_attacked = 0;

    // Add all attacked positions from each line type
    total_attacked += rows.size() * N; // All cells in forbidden rows
    total_attacked += cols.size() * N; // All cells in forbidden columns
    for (auto s : diag_sum) {
        // Number of points on diagonal x+y=s
        if (s >= 2 && s <= N + N) {
            i64 count = min(s - 1, N) - max(i64(1), s - N) + 1;
            total_attacked += count;
        }
    }
    for (auto d : diag_diff) {
        // Number of points on anti-diagonal x-y=d
        if (d >= -(N - 1) && d <= N - 1) {
            i64 count;
            if (d >= 0) {
                count = N - d;
            } else {
                count = N + d;
            }
            total_attacked += count;
        }
    }

    // Now subtract overlaps

    // Overlap between rows and columns (all combinations of r in rows, c in cols => cell (r,c))
    // These were counted twice: once in rows, once in cols
    i64 overlap_row_col = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            overlap_row_col++;
        }
    }
    total_attacked -= overlap_row_col;

    // Overlaps with diagonals
    // We'll check overlaps between each pair of sets

    auto count_overlap = [&](const set<i64>& A, const set<i64>& B, function<bool(i64, i64)> valid) {
        i64 cnt = 0;
        for (auto a : A) {
            for (auto b : B) {
                i64 x, y;
                if (valid(a, b)) {
                    cnt++;
                }
            }
        }
        return cnt;
    };

    // Helper functions for valid intersections
    function<bool(i64, i64)> valid_diag_row = [&](i64 s, i64 r) {
        i64 c = s - r;
        return c >= 1 && c <= N;
    };
    total_attacked -= count_overlap(diag_sum, rows, valid_diag_row); // diag_sum-row overlap

    function<bool(i64, i64)> valid_anti_row = [&](i64 d, i64 r) {
        i64 c = r - d;
        return c >= 1 && c <= N;
    };
    total_attacked -= count_overlap(diag_diff, rows, valid_anti_row); // diag_diff-row overlap

    function<bool(i64, i64)> valid_diag_col = [&](i64 s, i64 c) {
        i64 r = s - c;
        return r >= 1 && r <= N;
    };
    total_attacked -= count_overlap(diag_sum, cols, valid_diag_col); // diag_sum-col overlap

    function<bool(i64, i64)> valid_anti_col = [&](i64 d, i64 c) {
        i64 r = d + c;
        return r >= 1 && r <= N;
    };
    total_attacked -= count_overlap(diag_diff, cols, valid_anti_col); // diag_diff-col overlap

    function<bool(i64, i64)> valid_diag_anti = [&](i64 s, i64 d) {
        i64 x = (s + d) / 2;
        i64 y = (s - d) / 2;
        return x >= 1 && y >= 1 && x <= N && y <= N;
    };
    total_attacked -= count_overlap(diag_sum, diag_diff, valid_diag_anti); // diag_sum-diag_diff overlap

    // Now add back the triple overlaps (inclusion-exclusion principle)

    // Three-way overlaps: row, col, diag_sum
    i64 triple_rcd = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            i64 s = r + c;
            if (diag_sum.count(s)) {
                triple_rcd++;
            }
        }
    }
    total_attacked += triple_rcd;

    // Three-way overlaps: row, col, diag_diff
    i64 triple_rca = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            i64 d = r - c;
            if (diag_diff.count(d)) {
                triple_rca++;
            }
        }
    }
    total_attacked += triple_rca;

    // Three-way overlaps: row, diag_sum, diag_diff
    i64 triple_rda = 0;
    for (auto r : rows) {
        for (auto s : diag_sum) {
            for (auto d : diag_diff) {
                i64 x = (s + d) / 2;
                i64 y = (s - d) / 2;
                if ((s + d) % 2 == 0 && (s - d) % 2 == 0 && x == r && y >= 1 && y <= N) {
                    triple_rda++;
                }
            }
        }
    }
    total_attacked += triple_rda;

    // Three-way overlaps: col, diag_sum, diag_diff
    i64 triple_cda = 0;
    for (auto c : cols) {
        for (auto s : diag_sum) {
            for (auto d : diag_diff) {
                i64 x = (s + d) / 2;
                i64 y = (s - d) / 2;
                if ((s + d) % 2 == 0 && (s - d) % 2 == 0 && y == c && x >= 1 && x <= N) {
                    triple_cda++;
                }
            }
        }
    }
    total_attacked += triple_cda;

    // Four-way overlaps: row, col, diag_sum, diag_diff
    i64 quad = 0;
    for (auto [r, c] : occupied_cells) {
        i64 s = r + c;
        i64 d = r - c;
        if (diag_sum.count(s) && diag_diff.count(d)) {
            quad++;
        }
    }
    total_attacked -= quad;

    // The final result
    cout << N * N - total_attacked << "\n";

    return 0;
}