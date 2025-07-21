#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // First subtract all squares attacked by existing pieces via row and column
    int ans = (n - rows.size()) * (n - cols.size());

    // Now subtract the additional attacked squares on diagonals that are not already covered by row/column attack

    // For each diagonal of type x+y=d
    for (int d : diag1) {
        set<int> attacked_points;

        // Add all points (x,y) such that x+y=d and x is in rows or y is in cols
        for (int x : rows) {
            int y = d - x;
            if (1 <= y && y <= n)
                attacked_points.insert(x);
        }

        for (int y : cols) {
            int x = d - y;
            if (1 <= x && x <= n)
                attacked_points.insert(x);
        }

        // Total number of cells on this diagonal
        int len;
        if (d <= n + 1) {
            len = d - 1;
        } else {
            len = 2 * n - d + 1;
        }

        ans -= attacked_points.size();
    }

    // For each diagonal of type x-y=d
    for (int d : diag2) {
        set<int> attacked_points;

        // Add all points (x,y) such that x-y=d and x is in rows or y is in cols
        for (int x : rows) {
            int y = x - d;
            if (1 <= y && y <= n)
                attacked_points.insert(x);
        }

        for (int y : cols) {
            int x = y + d;
            if (1 <= x && x <= n)
                attacked_points.insert(x);
        }

        // Total number of cells on this diagonal
        int len;
        if (d >= 0) {
            len = n - d;
        } else {
            len = n + d;
        }

        ans -= attacked_points.size();
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}