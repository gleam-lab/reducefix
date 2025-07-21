#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> rows, cols, diag1, diag2; // diag1: i+j, diag2: i-j

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int total_safe = n * n; // Initial total squares
    // Subtract squares in unsafe rows
    total_safe -= n * rows.size();
    // Subtract squares in unsafe columns
    total_safe -= n * cols.size();
    // Add back squares that were subtracted twice (intersection of rows and columns)
    total_safe += rows.size() * cols.size();

    // Now handle diagonals
    // For each diagonal in diag1 (i+j = d)
    for (auto d : diag1) {
        // The length of the diagonal is min(d-1, n) - max(d-n, 1) + 1
        int min_i_plus_j = max(2LL, d - n);
        int max_i_plus_j = min(d - 1, n);
        int len = max_i_plus_j - min_i_plus_j + 1;
        if (len <= 0) continue; // No squares on this diagonal

        // Squares on this diagonal not already covered by rows or columns
        int unsafe = len;
        // Subtract squares already covered by rows
        for (auto r : rows) {
            if (d - r >= 1 && d - r <= n) {
                unsafe--;
            }
        }
        // Subtract squares already covered by columns
        for (auto c : cols) {
            if (d - c >= 1 && d - c <= n) {
                unsafe--;
            }
        }
        // Add back squares subtracted twice (intersection of rows and columns)
        for (auto r : rows) {
            for (auto c : cols) {
                if (r + c == d) {
                    unsafe++;
                }
            }
        }
        total_safe -= unsafe;
    }

    // For each diagonal in diag2 (i-j = d)
    for (auto d : diag2) {
        // The length of the diagonal is min(n - d, n) - max(1 - d, 1) + 1
        int min_i_minus_j = max(1LL, 1 - d);
        int max_i_minus_j = min(n - d, n);
        int len = max_i_minus_j - min_i_minus_j + 1;
        if (len <= 0) continue; // No squares on this diagonal

        // Squares on this diagonal not already covered by rows or columns
        int unsafe = len;
        // Subtract squares already covered by rows
        for (auto r : rows) {
            if (r - d >= 1 && r - d <= n) {
                unsafe--;
            }
        }
        // Subtract squares already covered by columns
        for (auto c : cols) {
            if (c + d >= 1 && c + d <= n) {
                unsafe--;
            }
        }
        // Add back squares subtracted twice (intersection of rows and columns)
        for (auto r : rows) {
            for (auto c : cols) {
                if (r - c == d) {
                    unsafe++;
                }
            }
        }
        total_safe -= unsafe;
    }

    cout << total_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}