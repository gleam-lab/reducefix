#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int total_safe = N * N;

    // Subtract squares covered by rows
    total_safe -= rows.size() * N;

    // Subtract squares covered by columns
    total_safe -= cols.size() * N;

    // Add back squares covered by both rows and columns (intersection)
    total_safe += rows.size() * cols.size();

    // Subtract squares covered by diagonals (i+j=d)
    for (int d : diag1) {
        int min_j = max(1LL, d - N);
        int max_j = min(N, d - 1);
        if (min_j > max_j) continue;
        int len = max_j - min_j + 1;
        total_safe -= len;
    }

    // Subtract squares covered by diagonals (i-j=d)
    for (int d : diag2) {
        int min_j = max(1LL, 1 - d);
        int max_j = min(N, N - d);
        if (min_j > max_j) continue;
        int len = max_j - min_j + 1;
        total_safe -= len;
    }

    // Add back squares covered by both diagonals (i+j=d1 and i-j=d2)
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                total_safe += 1;
            }
        }
    }

    // Add back squares covered by both a row and a diagonal (i+j=d)
    for (int d : diag1) {
        for (int r : rows) {
            int j = d - r;
            if (j >= 1 && j <= N) {
                total_safe += 1;
            }
        }
    }

    // Add back squares covered by both a column and a diagonal (i+j=d)
    for (int d : diag1) {
        for (int c : cols) {
            int i = d - c;
            if (i >= 1 && i <= N) {
                total_safe += 1;
            }
        }
    }

    // Add back squares covered by both a row and a diagonal (i-j=d)
    for (int d : diag2) {
        for (int r : rows) {
            int j = r - d;
            if (j >= 1 && j <= N) {
                total_safe += 1;
            }
        }
    }

    // Add back squares covered by both a column and a diagonal (i-j=d)
    for (int d : diag2) {
        for (int c : cols) {
            int i = d + c;
            if (i >= 1 && i <= N) {
                total_safe += 1;
            }
        }
    }

    // Subtract squares covered by all three: row, column, and diagonal (i+j=d)
    for (int d : diag1) {
        for (int r : rows) {
            for (int c : cols) {
                if (r + c == d) {
                    total_safe -= 1;
                }
            }
        }
    }

    // Subtract squares covered by all three: row, column, and diagonal (i-j=d)
    for (int d : diag2) {
        for (int r : rows) {
            for (int c : cols) {
                if (r - c == d) {
                    total_safe -= 1;
                }
            }
        }
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