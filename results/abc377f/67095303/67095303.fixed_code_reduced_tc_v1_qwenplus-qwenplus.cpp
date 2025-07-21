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

    // Total empty cells not in any occupied row or column
    int total = (n - rows.size()) * (n - cols.size());

    // Remove squares attacked by diagonal lines (diag1: i+j=d)
    for (int d : diag1) {
        int low = max(1LL, d - n);
        int high = min(n, d - 1);
        if (low > high) continue;

        // Count how many of these are already excluded due to occupied rows/cols
        int count_already_excluded = 0;

        // Check intersection with occupied rows
        for (int r : rows) {
            int c = d - r;
            if (c >= 1 && c <= n)
                count_already_excluded++;
        }

        // Check intersection with occupied columns
        for (int c : cols) {
            int r = d - c;
            if (r >= 1 && r <= n)
                count_already_excluded++;
        }

        total -= (high - low + 1 - count_already_excluded);
    }

    // Remove squares attacked by diagonal lines (diag2: i-j=d)
    for (int d : diag2) {
        int low, high;
        if (d <= 0)
            low = 1 - d, high = n;
        else
            low = 1, high = n - d;
        if (low > high) continue;

        // Count how many of these are already excluded due to occupied rows/cols
        int count_already_excluded = 0;

        // Check intersection with occupied rows
        for (int r : rows) {
            int c = r - d;
            if (c >= 1 && c <= n)
                count_already_excluded++;
        }

        // Check intersection with occupied columns
        for (int c : cols) {
            int r = c + d;
            if (r >= 1 && r <= n)
                count_already_excluded++;
        }

        total -= (high - low + 1 - count_already_excluded);
    }

    cout << total << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}