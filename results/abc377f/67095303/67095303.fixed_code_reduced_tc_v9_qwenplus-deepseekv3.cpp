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

    int total = N * N;
    int row_threat = rows.size() * N;
    int col_threat = cols.size() * N;
    int row_col_intersect = rows.size() * cols.size();
    int safe_initial = total - row_threat - col_threat + row_col_intersect;

    // Calculate squares threatened by diagonals i + j = d
    int diag1_threat = 0;
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        diag1_threat += len;
    }

    // Subtract squares already counted in rows or cols
    for (int d : diag1) {
        for (int r : rows) {
            int c = d - r;
            if (c >= 1 && c <= N) {
                diag1_threat--;
            }
        }
        for (int c : cols) {
            int r = d - c;
            if (r >= 1 && r <= N) {
                diag1_threat--;
            }
        }
        // Add back squares subtracted twice (intersection of row and column)
        for (int r : rows) {
            for (int c : cols) {
                if (r + c == d) {
                    diag1_threat++;
                }
            }
        }
    }

    // Calculate squares threatened by diagonals i - j = d
    int diag2_threat = 0;
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        diag2_threat += len;
    }

    // Subtract squares already counted in rows or cols
    for (int d : diag2) {
        for (int r : rows) {
            int c = r - d;
            if (c >= 1 && c <= N) {
                diag2_threat--;
            }
        }
        for (int c : cols) {
            int r = c + d;
            if (r >= 1 && r <= N) {
                diag2_threat--;
            }
        }
        // Add back squares subtracted twice (intersection of row and column)
        for (int r : rows) {
            for (int c : cols) {
                if (r - c == d) {
                    diag2_threat++;
                }
            }
        }
    }

    // Subtract squares threatened by both diagonals i + j = d1 and i - j = d2 (intersection points)
    int diag_intersect = 0;
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    diag_intersect++;
                }
            }
        }
    }

    // Total safe squares
    int safe = safe_initial - (diag1_threat + diag2_threat - diag_intersect);
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}