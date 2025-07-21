#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

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

    // Total safe squares = total empty squares not on any attacked line
    int total_safe = (n - rows.size()) * (n - cols.size());

    // Subtract the overlapping squares on the diagonal lines that are already excluded
    auto count_overlap = [&](const set<int>& lines, bool is_diag1) {
        for (int d : lines) {
            set<int> blocked;

            // Rows that intersect with this diagonal
            for (int r : rows) {
                int c = is_diag1 ? d - r : d + r;
                if (c >= 1 && c <= n)
                    blocked.insert(r);
            }

            // Cols that intersect with this diagonal
            for (int c : cols) {
                int r = is_diag1 ? d - c : d + c;
                if (r >= 1 && r <= n)
                    blocked.insert(r);
            }

            // Estimate length of diagonal
            int len;
            if (is_diag1) {
                if (d <= n + 1)
                    len = d - 1;
                else
                    len = 2 * n - d + 1;
            } else {
                int abs_d = abs(d);
                len = n - abs_d;
            }

            total_safe -= (len - blocked.size());
        }
    };

    count_overlap(diag1, true);
    count_overlap(diag2, false);

    cout << total_safe << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}