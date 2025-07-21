#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    set<int> diag1, diag2;  // i+j and i-j

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // First compute total number of cells not in any attacked row or column
    int ans = (n - rows.size()) * (n - cols.size());

    // Subtract the cells on the diagonals that are not already excluded by removed rows/columns
    auto process_diag1 = [&](int d) {
        // i + j = d
        int count = 0;

        // Compute valid range for i
        int i_min = max(1LL, d - n);
        int i_max = min(n, d - 1);

        if (i_min > i_max)
            return;

        // Total cells on this diagonal
        int total_cells = i_max - i_min + 1;

        // Cells already excluded due to forbidden rows or columns
        for (int i = i_min; i <= i_max; ++i) {
            int j = d - i;
            if (rows.count(i) || cols.count(j))
                count++;
        }

        ans -= (total_cells - count);
    };

    auto process_diag2 = [&](int d) {
        // i - j = d => i = j + d
        int count = 0;

        int j_min = max(1LL, 1 - d);
        int j_max = min(n, n - d);

        if (j_min > j_max)
            return;

        // Total cells on this diagonal
        int total_cells = j_max - j_min + 1;

        // Cells already excluded due to forbidden rows or columns
        for (int j = j_min; j <= j_max; ++j) {
            int i = j + d;
            if (rows.count(i) || cols.count(j))
                count++;
        }

        ans -= (total_cells - count);
    };

    for (int d : diag1)
        process_diag1(d);

    for (int d : diag2)
        process_diag2(d);

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}