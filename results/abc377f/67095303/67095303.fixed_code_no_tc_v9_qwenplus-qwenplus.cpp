#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(r - c);
    }

    // First calculate all squares not in any row or column with a piece
    int ans = (n - rows.size()) * (n - cols.size());

    // Subtract squares on diagonals of type i+j=d that are not already excluded by row or column
    for (int d : diag1) {
        // Calculate number of points on diagonal i+j=d
        int cnt;
        if (d >= 2 && d <= n + 1) {
            cnt = d - 1;
        } else if (d > n + 1 && d <= 2 * n) {
            cnt = 2 * n + 1 - d;
        } else {
            cnt = 0; // Invalid diagonal
        }

        // Subtract points on this diagonal that aren't already excluded by row or column
        ans -= cnt;

        // Add back points that were already excluded due to row or column
        for (int r : rows) {
            int c = d - r;
            if (c >= 1 && c <= n) {
                ans += 1;
            }
        }
        for (int c : cols) {
            int r = d - c;
            if (r >= 1 && r <= n && !rows.count(r)) {
                ans += 1;
            }
        }
    }

    // Subtract squares on diagonals of type i-j=d that are not already excluded by row or column
    for (int d : diag2) {
        // Calculate number of points on diagonal i-j=d
        int cnt;
        if (d >= 1 - n && d <= 0) {
            cnt = n + d;
        } else if (d >= 1 && d <= n - 1) {
            cnt = n - d;
        } else {
            cnt = 0; // Invalid diagonal
        }

        // Subtract points on this diagonal that aren't already excluded by row or column
        ans -= cnt;

        // Add back points that were already excluded due to row or column
        for (int r : rows) {
            int c = r - d;
            if (c >= 1 && c <= n) {
                ans += 1;
            }
        }
        for (int c : cols) {
            int r = d + c;
            if (r >= 1 && r <= n && !rows.count(r)) {
                ans += 1;
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}