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

    int total = N * N;
    int attacked = 0;

    // Rows and columns
    int row_count = rows.size();
    int col_count = cols.size();
    attacked += row_count * N + col_count * N - row_count * col_count;

    // Diagonals (i+j = d)
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        int len = max_i - min_i + 1;
        attacked += len;
    }

    // Diagonals (i-j = d)
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        if (min_i > max_i) continue;
        int len = max_i - min_i + 1;
        attacked += len;
    }

    // Subtract intersections between rows/columns and diagonals
    for (int d : diag1) {
        for (int r : rows) {
            int c = d - r;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
        for (int c : cols) {
            int r = d - c;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
    }

    for (int d : diag2) {
        for (int r : rows) {
            int c = r - d;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
        for (int c : cols) {
            int r = c + d;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
    }

    // Add back intersections between diagonals that were subtracted twice
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= i && i <= N && 1 <= j && j <= N) {
                attacked++;
            }
        }
    }

    // Subtract the existing pieces (they are not empty)
    attacked -= M;

    int safe = total - attacked;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}