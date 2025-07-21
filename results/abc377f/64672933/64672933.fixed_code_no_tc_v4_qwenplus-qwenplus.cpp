#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
        occupied_cells.emplace(a, b);
    }

    // Total number of cells attacked via rows and columns
    i64 total_attacked = 0;

    // Cells attacked by rows and columns (including overlaps)
    total_attacked += (i64)rows.size() * N;
    total_attacked += (i64)cols.size() * N;

    // Diagonals and anti-diagonals
    for (auto s : diag_sum) {
        // Number of cells on diagonal a + b = s
        i64 count = min(s, N) - max(i64(1), s - N + 1) + 1;
        total_attacked += count;
    }
    for (auto d : diag_diff) {
        // Number of cells on diagonal a - b = d
        if (d >= 0) {
            i64 start = max(i64(1), d + 1);
            i64 end = N;
            i64 count = end - start + 1;
            if (count > 0) total_attacked += count;
        } else {
            i64 start = max(i64(1), -d + 1);
            i64 end = N + d;
            i64 count = end - start + 1;
            if (count > 0) total_attacked += count;
        }
    }

    // Now subtract overlaps
    // Overlaps between rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            total_attacked -= 1; // each (r,c) counted twice
        }
    }

    // Overlaps between rows and diagonals
    for (auto r : rows) {
        for (auto s : diag_sum) {
            i64 c = s - r;
            if (1 <= c && c <= N) total_attacked -= 1;
        }
        for (auto d : diag_diff) {
            i64 c = r - d;
            if (1 <= c && c <= N) total_attacked -= 1;
        }
    }

    // Overlaps between columns and diagonals
    for (auto c : cols) {
        for (auto s : diag_sum) {
            i64 r = s - c;
            if (1 <= r && r <= N) total_attacked -= 1;
        }
        for (auto d : diag_diff) {
            i64 r = d + c;
            if (1 <= r && r <= N) total_attacked -= 1;
        }
    }

    // Overlaps between diag_sum and diag_diff
    for (auto s : diag_sum) {
        for (auto d : diag_diff) {
            i64 r = (s + d) / 2;
            i64 c = s - r;
            if ((s + d) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N) {
                total_attacked -= 1;
            }
        }
    }

    // Add back the actual occupied cells because they were counted multiple times
    total_attacked -= (i64)occupied_cells.size();

    i64 total_cells = N * N;
    i64 result = total_cells - total_attacked;

    cout << result << "\n";

    return 0;
}