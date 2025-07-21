#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    set<int> diag1, diag2; // diag1: i+j, diag2: i-j

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Total empty cells not on any row or column with a piece
    int total = (n - rows.size()) * (n - cols.size());

    // Subtract cells that are attacked by diagonal pieces but not already counted in rows or cols
    for (int d : diag1) {
        // i + j = d
        // Number of points on this diagonal: depends on range of i and j
        int cnt = 0;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n + 1 - d;
        }

        // Count how many of those points are NOT in excluded rows or cols
        // We subtract how many of these points are already accounted for in the row/col exclusions
        int overlap = 0;
        for (int r : rows) {
            int c = d - r;
            if (c >= 1 && c <= n) overlap++;
        }
        for (int c : cols) {
            int r = d - c;
            if (r >= 1 && r <= n && rows.count(r) == 0) overlap++;
        }

        total -= (cnt - overlap);
    }

    for (int d : diag2) {
        // i - j = d
        // Determine number of points on this diagonal
        int cnt = 0;
        if (d >= 0) {
            cnt = n - d;
        } else {
            cnt = n + d;
        }

        // Count overlaps
        int overlap = 0;
        for (int r : rows) {
            int c = r - d;
            if (c >= 1 && c <= n) overlap++;
        }
        for (int c : cols) {
            int r = d + c;
            if (r >= 1 && r <= n && rows.count(r) == 0) overlap++;
        }

        total -= (cnt - overlap);
    }

    cout << total << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}