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

    int total_unsafe = unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols;

    for (auto d : diag1) {
        int i_plus_j = d;
        int min_a = max(1LL, i_plus_j - N);
        int max_a = min(N, i_plus_j - 1);
        int count = max_a - min_a + 1;

        int intersect_rows = 0;
        for (auto r : rows) {
            if (i_plus_j - r >= 1 && i_plus_j - r <= N) {
                intersect_rows++;
            }
        }

        int intersect_cols = 0;
        for (auto c : cols) {
            if (i_plus_j - c >= 1 && i_plus_j - c <= N) {
                intersect_cols++;
            }
        }

        int already_counted = intersect_rows + intersect_cols;
        for (auto r : rows) {
            if (i_plus_j - r >= 1 && i_plus_j - r <= N && cols.count(i_plus_j - r)) {
                already_counted--;
            }
        }

        total_unsafe += count - already_counted;
    }

    for (auto d : diag2) {
        int i_minus_j = d;
        int min_a = max(1LL, 1 - i_minus_j);
        int max_a = min(N, N - i_minus_j);
        int count = max_a - min_a + 1;

        int intersect_rows = 0;
        for (auto r : rows) {
            if (r - i_minus_j >= 1 && r - i_minus_j <= N) {
                intersect_rows++;
            }
        }

        int intersect_cols = 0;
        for (auto c : cols) {
            if (i_minus_j + c >= 1 && i_minus_j + c <= N) {
                intersect_cols++;
            }
        }

        int already_counted = intersect_rows + intersect_cols;
        for (auto c : cols) {
            if (i_minus_j + c >= 1 && i_minus_j + c <= N && rows.count(i_minus_j + c)) {
                already_counted--;
            }
        }

        total_unsafe += count - already_counted;
    }

    int total_safe = N * N - total_unsafe;
    cout << total_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}