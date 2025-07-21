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

    int unsafe_rows = rows.size();
    int unsafe_cols = cols.size();
    int unsafe_diag1 = diag1.size();
    int unsafe_diag2 = diag2.size();

    // Total unsafe positions (union of all unsafe areas)
    // Using inclusion-exclusion principle to avoid double counting
    int total_unsafe = unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols;
    
    // Now subtract the positions that are already counted in rows and cols but also in diagonals
    // For each diagonal, we need to find the number of unique positions not already covered by rows or cols
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        int overlap_rows = 0, overlap_cols = 0;
        for (int i : rows) {
            if (d - i >= 1 && d - i <= N) overlap_rows++;
        }
        for (int j : cols) {
            if (d - j >= 1 && d - j <= N) overlap_cols++;
        }
        int overlap = overlap_rows + overlap_cols;
        // Subtract the positions not already covered by rows or cols
        total_unsafe += len - overlap;
    }

    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        int overlap_rows = 0, overlap_cols = 0;
        for (int i : rows) {
            if (i - d >= 1 && i - d <= N) overlap_rows++;
        }
        for (int j : cols) {
            if (j + d >= 1 && j + d <= N) overlap_cols++;
        }
        int overlap = overlap_rows + overlap_cols;
        // Subtract the positions not already covered by rows or cols
        total_unsafe += len - overlap;
    }

    // Now, subtract the positions that are counted in both diagonals but not in rows or cols
    // To avoid double counting, we need to find intersections between diag1 and diag2
    set<pair<int, int>> intersections;
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) == 0 && cols.count(j) == 0) {
                    intersections.insert({i, j});
                }
            }
        }
    }
    total_unsafe -= intersections.size();

    int total_safe = N * N - total_unsafe;
    cout << total_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}