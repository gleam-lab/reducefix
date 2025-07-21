#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    set<int> diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // First subtract all squares in attacked rows or columns
    int total_safe = (n - rows.size()) * (n - cols.size());

    // Now subtract the intersections with diagonals that are not already covered by row/col attacks
    auto process_diag = [&](const set<int>& dset, const set<int>& hset, const set<int>& vset, bool is_d1) {
        for (int d : dset) {
            set<int> blocked;

            // Rows that intersect this diagonal
            for (int x : rows) {
                int y = is_d1 ? (d - x) : (x - d);
                if (y >= 1 && y <= n)
                    blocked.insert(x);
            }

            // Cols that intersect this diagonal
            for (int y : cols) {
                int x = is_d1 ? (d - y) : (d + y);
                if (x >= 1 && x <= n)
                    blocked.insert(x);
            }

            // Count length of diagonal
            int len;
            if (is_d1) {
                if (d <= n + 1)
                    len = d - 1;
                else
                    len = 2 * n + 1 - d;
            } else {
                int abs_d = abs(d);
                len = n - abs_d;
            }

            total_safe -= (len - blocked.size());
        }
    };

    process_diag(diag1, rows, cols, true);
    process_diag(diag2, rows, cols, false);

    cout << total_safe << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}