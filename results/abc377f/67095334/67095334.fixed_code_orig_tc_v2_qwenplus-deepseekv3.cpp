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

    int total_rows = rows.size();
    int total_cols = cols.size();
    int total_diag1 = diag1.size();
    int total_diag2 = diag2.size();

    // Total squares under threat by rows, columns, and diagonals
    int threatened = total_rows * N + total_cols * N - total_rows * total_cols;

    // Add squares threatened by diag1 (i+j = d)
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        threatened += (max_i - min_i + 1);
    }

    // Add squares threatened by diag2 (i-j = d)
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        if (min_i > max_i) continue;
        threatened += (max_i - min_i + 1);
    }

    // Subtract squares counted twice (intersection of rows or columns with diagonals)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) || diag2.count(r - c)) {
                threatened--;
            }
        }
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    if (rows.count(i) || cols.count(j)) {
                        threatened--;
                    }
                }
            }
        }
    }

    // Total safe squares
    int safe = N * N - threatened;
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