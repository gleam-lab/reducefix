#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2; // diag1: i+j, diag2: i-j

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int total = N * N;

    // Calculate forbidden squares
    int forbidden = 0;

    // Forbidden by rows and columns
    int row_cnt = rows.size();
    int col_cnt = cols.size();
    forbidden += row_cnt * N;
    forbidden += col_cnt * (N - row_cnt);

    // Forbidden by diagonals (i + j = d)
    int diag1_cnt = diag1.size();
    for (auto d : diag1) {
        int x_min = max(1LL, d - N);
        int x_max = min(N, d - 1);
        int len = x_max - x_min + 1;

        // Subtract squares already forbidden by rows or columns
        int overlap = 0;
        for (auto x : rows) {
            int y = d - x;
            if (1 <= y && y <= N) {
                overlap++;
            }
        }
        for (auto y : cols) {
            int x = d - y;
            if (1 <= x && x <= N) {
                overlap++;
            }
        }
        // Remove duplicates in the above counts
        overlap = min(overlap, len);

        forbidden += len - overlap;
    }

    // Forbidden by anti-diagonals (i - j = d)
    int diag2_cnt = diag2.size();
    for (auto d : diag2) {
        int x_min, x_max;
        if (d >= 0) {
            x_min = 1 + d;
            x_max = N;
        } else {
            x_min = 1;
            x_max = N + d;
        }
        int len = x_max - x_min + 1;

        // Subtract squares already forbidden by rows or columns
        int overlap = 0;
        for (auto x : rows) {
            int y = x - d;
            if (1 <= y && y <= N) {
                overlap++;
            }
        }
        for (auto y : cols) {
            int x = y + d;
            if (1 <= x && x <= N) {
                overlap++;
            }
        }
        // Remove duplicates in the above counts
        overlap = min(overlap, len);

        forbidden += len - overlap;
    }

    int safe = total - forbidden;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}