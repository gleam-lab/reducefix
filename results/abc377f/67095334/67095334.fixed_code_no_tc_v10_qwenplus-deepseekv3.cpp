#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    vector<pair<int, int>> pieces(M);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int unsafe = 0;

    // Rows and columns
    unsafe += N * rows.size() + N * cols.size() - rows.size() * cols.size();

    // Diagonals (i + j = d)
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        unsafe += len;
    }

    // Diagonals (i - j = d)
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        unsafe += len;
    }

    // Subtract overlaps between rows/columns and diagonals
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b)) {
            unsafe--;
        }
        if (rows.count(a) && diag1.count(a + b)) {
            unsafe--;
        }
        if (rows.count(a) && diag2.count(a - b)) {
            unsafe--;
        }
        if (cols.count(b) && diag1.count(a + b)) {
            unsafe--;
        }
        if (cols.count(b) && diag2.count(a - b)) {
            unsafe--;
        }
        if (diag1.count(a + b) && diag2.count(a - b)) {
            unsafe--;
        }
    }

    // Add back the triple overlaps
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b) && diag1.count(a + b)) {
            unsafe++;
        }
        if (rows.count(a) && cols.count(b) && diag2.count(a - b)) {
            unsafe++;
        }
        if (rows.count(a) && diag1.count(a + b) && diag2.count(a - b)) {
            unsafe++;
        }
        if (cols.count(b) && diag1.count(a + b) && diag2.count(a - b)) {
            unsafe++;
        }
    }

    // Subtract the quadruple overlaps
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b) && diag1.count(a + b) && diag2.count(a - b)) {
            unsafe--;
        }
    }

    int total_squares = N * N;
    int safe_squares = total_squares - unsafe;
    cout << safe_squares << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}