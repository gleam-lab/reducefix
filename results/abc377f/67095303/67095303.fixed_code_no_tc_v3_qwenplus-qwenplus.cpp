#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> rows, cols;
    set<int> diag1, diag2; // diag1: i+j, diag2: i-j

    for (int i = 0; i < M; ++i) {
        int r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(r - c);
    }

    // Start with all empty squares not in any attacked row or column
    int total = (N - rows.size()) * (N - cols.size());

    // Subtract squares that are on attacked diagonals but not in attacked rows or columns

    // To avoid double-counting, we'll track coordinates already excluded due to diagonals
    set<pair<int, int>> blocked;

    // Process diag1: i + j = d
    for (int d : diag1) {
        // The diagonal i + j = d has values from max(1, d - N) to min(N, d - 1)
        int start = max(1LL, d - N);
        int end = min(N, d - 1);

        for (int i = start; i <= end; ++i) {
            int j = d - i;
            if (j < 1 || j > N) continue;
            if (rows.count(i) == 0 && cols.count(j) == 0) {
                blocked.insert({i, j});
            }
        }
    }

    // Process diag2: i - j = d
    for (int d : diag2) {
        // We need to find valid (i, j) such that i - j = d => i = j + d
        if (d >= 0) {
            // i = j + d => j <= N - d
            for (int j = max(1LL, 1 - d); j <= min(N - d, N); ++j) {
                int i = j + d;
                if (rows.count(i) == 0 && cols.count(j) == 0) {
                    blocked.insert({i, j});
                }
            }
        } else {
            // d < 0, i = j + d => j >= 1-d
            for (int j = max(1LL, 1 - d); j <= N; ++j) {
                int i = j + d;
                if (i >= 1 && i <= N && rows.count(i) == 0 && cols.count(j) == 0) {
                    blocked.insert({i, j});
                }
            }
        }
    }

    cout << total - blocked.size() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}