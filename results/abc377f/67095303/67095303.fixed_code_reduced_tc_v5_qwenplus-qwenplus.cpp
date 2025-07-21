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
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total empty squares not attacked by row or column
    int ans = (n - rows.size()) * (n - cols.size());

    // Subtract squares that lie on dangerous diagonals of type i+j=d
    for (int d : diag1) {
        set<int> blocked_rows;

        // Check intersection with forbidden rows
        for (int r : rows) {
            int c = d - r;
            if (c >= 1 && c <= n)
                blocked_rows.insert(r);
        }

        // Check intersection with forbidden columns
        for (int c : cols) {
            int r = d - c;
            if (r >= 1 && r <= n)
                blocked_rows.insert(r);
        }

        // Compute length of diagonal d
        int len;
        if (d <= n + 1)
            len = d - 1;
        else
            len = 2 * n + 1 - d;

        ans -= (len - blocked_rows.size());
    }

    // Subtract squares that lie on dangerous diagonals of type i-j=d
    for (int d : diag2) {
        set<int> blocked_rows;

        // Check intersection with forbidden rows
        for (int r : rows) {
            int c = r - d;
            if (c >= 1 && c <= n)
                blocked_rows.insert(r);
        }

        // Check intersection with forbidden columns
        for (int c : cols) {
            int r = d + c;
            if (r >= 1 && r <= n)
                blocked_rows.insert(r);
        }

        // Compute length of diagonal d
        int len;
        if (d < 0)
            len = n + d;
        else
            len = n - d;

        ans -= (len - blocked_rows.size());
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();

    return 0;
}