#include<bits/stdc++.h>
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

    // First calculate the number of squares not attacked by any row or column
    int ans = (n - (int)rows.size()) * (n - (int)cols.size());

    // Subtract the overlapping squares on forbidden diagonals

    // Process diag1: x + y = d
    for (int d : diag1) {
        // Compute the range of valid x values such that both x and y = d - x are in [1, n]
        int low_x = max(1LL, d - n);
        int high_x = min(n, d - 1);

        if (low_x > high_x) continue;

        // Total points on this diagonal: high_x - low_x + 1
        int total_points = high_x - low_x + 1;

        // Count how many of these x-values have already been excluded due to row or column attack
        int blocked_count = 0;

        // Check intersection with excluded rows
        for (int x : rows) {
            int y = d - x;
            if (x >= 1 && y >= 1 && x <= n && y <= n) {
                blocked_count++;
            }
        }

        // Check intersection with excluded columns
        for (int y : cols) {
            int x = d - y;
            if (x >= 1 && y >= 1 && x <= n && y <= n) {
                blocked_count++;
            }
        }

        // Remove duplicate counts (points that were counted both in rows and cols)
        set<pair<int,int>> duplicates;
        for (int x : rows) {
            int y = d - x;
            if (y >= 1 && y <= n && cols.count(y)) {
                duplicates.insert({x, y});
            }
        }

        blocked_count -= duplicates.size();

        ans -= (total_points - blocked_count);
    }

    // Process diag2: x - y = d
    for (int d : diag2) {
        // Valid range of x: max(1, d + 1) <= x <= min(n, d + n)
        int low_x = max(1LL, d + 1);
        int high_x = min(n, d + n);

        if (low_x > high_x) continue;

        int total_points = high_x - low_x + 1;

        int blocked_count = 0;

        // Check intersection with excluded rows
        for (int x : rows) {
            int y = x - d;
            if (y >= 1 && y <= n) {
                blocked_count++;
            }
        }

        // Check intersection with excluded columns
        for (int y : cols) {
            int x = y + d;
            if (x >= 1 && x <= n) {
                blocked_count++;
            }
        }

        // Remove duplicates
        set<pair<int,int>> duplicates;
        for (int x : rows) {
            int y = x - d;
            if (y >= 1 && y <= n && cols.count(y)) {
                duplicates.insert({x, y});
            }
        }

        blocked_count -= duplicates.size();

        ans -= (total_points - blocked_count);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}