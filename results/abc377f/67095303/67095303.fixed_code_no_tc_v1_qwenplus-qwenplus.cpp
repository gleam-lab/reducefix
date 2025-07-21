#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> rows, cols;
    set<int> diag1, diag2;  // diag1: i+j, diag2: i-j

    for (int i = 0; i < M; ++i) {
        int r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(r - c);
    }

    // Start with total number of cells not in any attacked row or column
    int ans = (N - rows.size()) * (N - cols.size());

    // Subtract squares on attack diagonals that are not already excluded by rows/cols
    for (int d : diag1) {
        // i + j = d
        int count = 0;

        // The diagonal intersects rows from max(1, d - N) to min(N, d - 1)
        int r_start = max(1LL, d - N);
        int r_end = min(N, d - 1);

        if (r_start <= r_end) {
            count = r_end - r_start + 1;
            // Subtract already counted rows
            for (int r : rows) {
                int c = d - r;
                if (1 <= c && c <= N) {
                    count--;
                }
            }
        }

        ans -= count;
    }

    for (int d : diag2) {
        // i - j = d
        int count = 0;

        // The diagonal intersects rows from max(1, d + 1) to min(N, d + N)
        int r_start = max(1LL, d + 1);
        int r_end = min(N, d + N);

        if (r_start <= r_end) {
            count = r_end - r_start + 1;
            // Subtract already counted rows
            for (int r : rows) {
                int c = r - d;
                if (1 <= c && c <= N) {
                    count--;
                }
            }
        }

        ans -= count;
    }

    cout << ans << endl;
}

signed main() {
    solve();
    return 0;
}