#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    set<int> diag1, diag2;  // diag1: i+j, diag2: i-j

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Start with total number of empty squares not in any row or column with a piece
    int ans = (n - rows.size()) * (n - cols.size());

    // Subtract the number of safe positions on each affected diagonal
    auto process_diag1 = [&](int d) {
        // For diagonal i+j=d, valid cells are those where both i and j are in [1,n]
        // i ranges from max(1, d-n) to min(n, d-1)
        int l = max(1LL, d - n);
        int r = min(n, d - 1);
        int count = r - l + 1;

        if (count <= 0) return;

        // Count how many of these rows/cols are already excluded
        int overlap = 0;
        for (int x : rows) {
            int y = d - x;
            if (y >= 1 && y <= n) overlap++;
        }
        for (int y : cols) {
            int x = d - y;
            if (x >= 1 && x <= n) overlap++;
        }

        // Use a set to avoid double counting
        set<int> seen;
        for (int x : rows) {
            int y = d - x;
            if (y >= 1 && y <= n) seen.insert(x);
        }
        for (int y : cols) {
            int x = d - y;
            if (x >= 1 && x <= n) seen.insert(x);
        }

        ans -= seen.size();
    };

    for (int d : diag1) process_diag1(d);

    auto process_diag2 = [&](int d) {
        // For diagonal i-j=d => i = j+d
        // Valid cells where j in [1,n] and i in [1,n]
        // So j must satisfy: 1 <= j <= n and 1 <= j+d <= n
        // => max(1, 1-d) <= j <= min(n, n-d)

        int lower_j = max(1LL, 1LL - d);
        int upper_j = min(n, n - d);
        int count = upper_j - lower_j + 1;

        if (count <= 0) return;

        // Count how many of these rows/cols are already excluded
        set<int> seen;
        for (int x : rows) {
            int y = x - d;
            if (y >= 1 && y <= n) seen.insert(x);
        }
        for (int y : cols) {
            int x = y + d;
            if (x >= 1 && x <= n) seen.insert(x);
        }

        ans -= seen.size();
    };

    for (int d : diag2) process_diag2(d);

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}