#include<bits/stdc++.h>
#define int long long
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

    int total = N * N - M;

    int forbidden_rows = rows.size();
    int forbidden_cols = cols.size();
    int forbidden_diag1 = diag1.size();
    int forbidden_diag2 = diag2.size();

    int row_col = forbidden_rows * N + forbidden_cols * N - forbidden_rows * forbidden_cols;
    int row_diag1 = 0, row_diag2 = 0, col_diag1 = 0, col_diag2 = 0, diag1_diag2 = 0;

    for (int d : diag1) {
        int l = max(1LL, d - N);
        int r = min(N, d - 1);
        if (l > r) continue;
        int cnt = r - l + 1;
        row_diag1 += cnt;
    }

    for (int d : diag2) {
        int l = max(1LL, 1 - d);
        int r = min(N, N - d);
        if (l > r) continue;
        int cnt = r - l + 1;
        row_diag2 += cnt;
    }

    for (int d : diag1) {
        int l = max(1LL, d - N);
        int r = min(N, d - 1);
        if (l > r) continue;
        int cnt = r - l + 1;
        col_diag1 += cnt;
    }

    for (int d : diag2) {
        int l = max(1LL, 1 + d);
        int r = min(N, N + d);
        if (l > r) continue;
        int cnt = r - l + 1;
        col_diag2 += cnt;
    }

    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                diag1_diag2++;
            }
        }
    }

    int row_col_diag1 = 0;
    for (int r : rows) {
        for (int d : diag1) {
            int j = d - r;
            if (j >= 1 && j <= N) {
                row_col_diag1++;
            }
        }
    }

    int row_col_diag2 = 0;
    for (int r : rows) {
        for (int d : diag2) {
            int j = r - d;
            if (j >= 1 && j <= N) {
                row_col_diag2++;
            }
        }
    }

    int row_diag1_diag2 = 0;
    for (int r : rows) {
        for (int d1 : diag1) {
            for (int d2 : diag2) {
                if ((d1 + d2) % 2 != 0) continue;
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i == r && j >= 1 && j <= N) {
                    row_diag1_diag2++;
                }
            }
        }
    }

    int col_diag1_diag2 = 0;
    for (int c : cols) {
        for (int d1 : diag1) {
            for (int d2 : diag2) {
                if ((d1 + d2) % 2 != 0) continue;
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (j == c && i >= 1 && i <= N) {
                    col_diag1_diag2++;
                }
            }
        }
    }

    int row_col_diag1_diag2 = 0;
    for (int r : rows) {
        for (int c : cols) {
            int d1 = r + c;
            int d2 = r - c;
            if (diag1.find(d1) != diag1.end() && diag2.find(d2) != diag2.end()) {
                row_col_diag1_diag2++;
            }
        }
    }

    int total_forbidden = (forbidden_rows * N) + (forbidden_cols * N) - (forbidden_rows * forbidden_cols);
    total_forbidden += forbidden_diag1 * N - row_col_diag1;
    total_forbidden += forbidden_diag2 * N - row_col_diag2;
    total_forbidden -= (row_diag1 + row_diag2 + col_diag1 + col_diag2 - row_col_diag1 - row_col_diag2 - diag1_diag2);
    total_forbidden += (row_diag1_diag2 + col_diag1_diag2 - row_col_diag1_diag2);

    int safe_squares = total - total_forbidden;
    cout << safe_squares << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}