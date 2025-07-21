#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    set<int> diag1, diag2;  // diag1: i+j, diag2: i-j

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Total safe cells = total cells - attacked cells
    // We compute total attacked cells using inclusion-exclusion

    // First part: cells on the same row or column as any piece
    int attacked_by_row_or_col = n * (rows.size() + cols.size()) - rows.size() * cols.size();

    // Second part: cells on diagonal 1 (i+j=d) that are not already counted
    set<pair<int, int>> diagonal1_points;
    for (auto d : diag1) {
        // For i+j=d, valid range of i is max(1, d-n) to min(n, d-1)
        int i_min = max(1LL, d - n);
        int i_max = min(n, d - 1);
        if (i_min > i_max) continue;

        for (int i = i_min; i <= i_max; ++i) {
            int j = d - i;
            // Skip if this cell is already counted in row or column attack
            if (rows.count(i) || cols.count(j)) continue;
            diagonal1_points.insert({i, j});
        }
    }

    // Third part: cells on diagonal 2 (i-j=d) that are not already counted
    set<pair<int, int>> diagonal2_points;
    for (auto d : diag2) {
        // For i-j=d => i = j+d, valid range of j is max(1, 1-d) to min(n, n-d)
        int j_min = max(1LL, 1 - d);
        int j_max = min(n, n - d);
        if (j_min > j_max) continue;

        for (int j = j_min; j <= j_max; ++j) {
            int i = j + d;
            // Skip if this cell is already counted in row or column attack
            if (rows.count(i) || cols.count(j)) continue;
            diagonal2_points.insert({i, j});
        }
    }

    // Total number of attacked cells
    int attacked_cells = attacked_by_row_or_col + diagonal1_points.size() + diagonal2_points.size();

    // Number of empty unattacked cells
    int total_empty_cells = n * n - m;
    int unattacked_empty_cells = total_empty_cells - attacked_cells;

    cout << unattacked_empty_cells << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}