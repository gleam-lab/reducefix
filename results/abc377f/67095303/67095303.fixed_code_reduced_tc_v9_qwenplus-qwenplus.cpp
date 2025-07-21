#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> row_set, col_set, diag1_set, diag2_set;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        row_set.insert(a);
        col_set.insert(b);
        diag1_set.insert(a + b);
        diag2_set.insert(a - b);
    }

    // Total empty squares not attacked in row or column directions
    int ans = (n - row_set.size()) * (n - col_set.size());

    // Subtract the overlap with diagonal attacks
    auto process_diag1 = [&](int d) {
        set<int> covered_rows;

        // Rows that intersect this diagonal
        for (int r : row_set) {
            int c = d - r;
            if (1 <= c && c <= n)
                covered_rows.insert(r);
        }

        // Cols that intersect this diagonal
        for (int c : col_set) {
            int r = d - c;
            if (1 <= r && r <= n)
                covered_rows.insert(r);
        }

        // Count number of cells on this diagonal
        int len;
        if (d <= n + 1) {
            len = d - 1;
            if (len > n) len = n;
        } else {
            len = 2 * n - d + 1;
        }

        ans -= (len - covered_rows.size());
    };

    auto process_diag2 = [&](int d) {
        set<int> covered_rows;

        // Rows that intersect this diagonal
        for (int r : row_set) {
            int c = r - d;
            if (1 <= c && c <= n)
                covered_rows.insert(r);
        }

        // Cols that intersect this diagonal
        for (int c : col_set) {
            int r = d + c;
            if (1 <= r && r <= n)
                covered_rows.insert(r);
        }

        // Intersections with other diagonals (to avoid double counting)
        for (int e : diag1_set) {
            int sum = e;
            int diff = d;
            int r = (sum + diff) / 2;
            int c = sum - r;
            if (r == c || r < 1 || c < 1 || r > n || c > n)
                continue;
            if ((sum + diff) % 2 == 0) {
                if (1 <= r && r <= n && 1 <= c && c <= n)
                    covered_rows.insert(r);
            }
        }

        // Count number of cells on this diagonal
        int len;
        if (d >= 0)
            len = n - d;
        else
            len = n + d;

        ans -= (len - covered_rows.size());
    };

    // Apply corrections for diagonals
    for (int d : diag1_set)
        process_diag1(d);

    for (int d : diag2_set)
        process_diag2(d);

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}