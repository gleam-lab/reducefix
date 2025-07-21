#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // First calculate the number of squares not in any attacked row or column
    int ans = (n - rows.size()) * (n - cols.size());

    // Subtract squares on attacked diagonals that are not already excluded by row/col
    auto process_diag = [&](const set<int>& dSet, bool is_d1) {
        for (int d : dSet) {
            set<int> blocked_rows;

            // Rows that intersect this diagonal
            for (int r : rows) {
                int c = is_d1 ? d - r : r - d;
                if (1 <= c && c <= n)
                    blocked_rows.insert(r);
            }

            // Columns that intersect this diagonal
            for (int c : cols) {
                int r = is_d1 ? d - c : d + c;
                if (1 <= r && r <= n)
                    blocked_rows.insert(r);
            }

            // Length of diagonal
            int len = 0;
            if (is_d1) {
                if (d <= n + 1)
                    len = d - 1;
                else
                    len = 2 * n - d + 1;
            } else {
                int min_val = max(1LL, d + 1);
                int max_val = min(n, n + d);
                if (min_val > max_val)
                    len = 0;
                else
                    len = max_val - min_val + 1;
            }

            ans -= (len - blocked_rows.size());
        }
    };

    process_diag(diag1, true);  // Process i+j=d
    process_diag(diag2, false); // Process i-j=d

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}