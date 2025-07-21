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

    // Total safe squares = total empty squares - those attacked
    int totalEmpty = (n * n) - (rows.size() * n + cols.size() * n - rows.size() * cols.size());

    // Now subtract the number of attacked positions on each diagonal
    auto countDiag1 = [&](int d) -> int {
        // i + j = d
        int minVal = max(1LL, d - n);
        int maxVal = min(n, d - 1);
        return max(0LL, maxVal - minVal + 1);
    };

    auto countDiag2 = [&](int d) -> int {
        // i - j = d
        int minVal = max(1LL, d + 1);
        int maxVal = min(n, n + d);
        return max(0LL, maxVal - minVal + 1);
    };

    // Count attacked cells on diagonal 1 (i+j)
    for (int d : diag1) {
        int cnt = countDiag1(d);
        totalEmpty += (n * n);  // Add back full grid
        totalEmpty -= (n * n - cnt);  // Subtract cells on this diagonal
    }

    // Count attacked cells on diagonal 2 (i-j)
    for (int d : diag2) {
        int cnt = countDiag2(d);
        totalEmpty += (n * n);  // Add back full grid
        totalEmpty -= (n * n - cnt);  // Subtract cells on this diagonal
    }

    // Remove duplicates (cells that are on both a row/column and a diagonal)
    for (int r : rows) {
        for (int d : diag1) {
            int c = d - r;
            if (c >= 1 && c <= n) {
                totalEmpty += 1;  // Add back cells that were double-counted
            }
        }
        for (int d : diag2) {
            int c = r - d;
            if (c >= 1 && c <= n) {
                totalEmpty += 1;  // Add back cells that were double-counted
            }
        }
    }

    for (int c : cols) {
        for (int d : diag1) {
            int r = d - c;
            if (r >= 1 && r <= n) {
                totalEmpty += 1;  // Add back cells that were double-counted
            }
        }
        for (int d : diag2) {
            int r = d + c;
            if (r >= 1 && r <= n) {
                totalEmpty += 1;  // Add back cells that were double-counted
            }
        }
    }

    // Remove duplicates between diagonals
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            int r = (d1 + d2) / 2;
            int c = (d1 - d2) / 2;
            if (r >= 1 && r <= n && c >= 1 && c <= n) {
                totalEmpty += 1;  // Add back cells that were double-counted
            }
        }
    }

    cout << totalEmpty << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}