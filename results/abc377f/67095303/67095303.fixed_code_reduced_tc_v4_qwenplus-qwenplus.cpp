#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

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

    // Total safe cells = total not on any attacked line
    // First compute the number of cells not in any row or column with a piece
    int ans = (n - rows.size()) * (n - cols.size());

    // Now subtract the cells that are on diagonals but already excluded due to row/col
    // We must avoid double-counting cells that are on both a row and col intersection AND a diagonal

    // Process each diagonal of the form i + j = d
    for (int d : diag1) {
        set<int> intersected_rows;

        // Check intersection with occupied rows
        for (int r : rows) {
            int c = d - r;
            if (c >= 1 && c <= n)
                intersected_rows.insert(r);
        }

        // Check intersection with occupied columns
        for (int c : cols) {
            int r = d - c;
            if (r >= 1 && r <= n)
                intersected_rows.insert(r);
        }

        // Compute length of this diagonal
        int len;
        if (d <= n + 1) {
            len = d <= n ? d - 1 : n;
        } else {
            len = 2 * n - d + 1;
        }

        ans -= (len - intersected_rows.size());
    }

    // Process each diagonal of the form i - j = d
    for (int d : diag2) {
        set<int> intersected_rows;

        // Check intersection with occupied rows
        for (int r : rows) {
            int c = r - d;
            if (c >= 1 && c <= n)
                intersected_rows.insert(r);
        }

        // Check intersection with occupied columns
        for (int c : cols) {
            int r = d + c;
            if (r >= 1 && r <= n)
                intersected_rows.insert(r);
        }

        // Compute length of this diagonal
        int len;
        if (d >= 0) {
            len = n - d;
        } else {
            len = n + d;
        }

        ans -= (len - intersected_rows.size());
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}