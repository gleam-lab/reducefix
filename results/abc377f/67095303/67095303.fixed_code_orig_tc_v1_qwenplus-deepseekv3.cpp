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

    int safe_rows = N - rows.size();
    int safe_cols = N - cols.size();
    int initial_safe = safe_rows * safe_cols;

    // Handle diagonals i+j = d (diag1)
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        int cnt = max_i - min_i + 1;

        for (auto r : rows) {
            if (d - r >= 1 && d - r <= N) {
                cnt--;
            }
        }
        for (auto c : cols) {
            if (d - c >= 1 && d - c <= N) {
                cnt--;
            }
        }
        initial_safe += cnt;
    }

    // Handle diagonals i-j = d (diag2)
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        if (min_i > max_i) continue;
        int cnt = max_i - min_i + 1;

        for (auto r : rows) {
            if (r - d >= 1 && r - d <= N) {
                cnt--;
            }
        }
        for (auto c : cols) {
            if (c + d >= 1 && c + d <= N) {
                cnt--;
            }
        }
        initial_safe += cnt;
    }

    // Now, subtract the squares that are in both diag1 and diag2 (intersection points)
    // These were added twice (once in each diagonal loop), so we need to subtract once
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.find(i) == rows.end() && cols.find(j) == cols.end()) {
                    initial_safe--;
                }
            }
        }
    }

    cout << initial_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}