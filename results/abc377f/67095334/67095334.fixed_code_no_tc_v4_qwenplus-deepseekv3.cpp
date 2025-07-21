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

    int total = N * N;
    int unsafe = 0;

    // Calculate unsafe squares from rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Subtract overlaps

    // Calculate unsafe squares from diagonals (diag1: i+j, diag2: i-j)
    for (auto d : diag1) {
        int min_i_plus_j = 2;
        int max_i_plus_j = 2 * N;
        if (d < min_i_plus_j || d > max_i_plus_j) continue;

        int len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N - d + 1;
        }
        unsafe += len;
    }

    for (auto d : diag2) {
        int min_i_minus_j = 1 - N;
        int max_i_minus_j = N - 1;
        if (d < min_i_minus_j || d > max_i_minus_j) continue;

        int len;
        if (d <= 0) {
            len = N + d;
        } else {
            len = N - d;
        }
        unsafe += len;
    }

    // Subtract overlaps between diagonals and rows/columns
    for (auto p : pieces) {
        int a = p.first, b = p.second;
        if (rows.count(a) && cols.count(b)) {
            unsafe--;
        }
        if (diag1.count(a + b) && rows.count(a)) {
            unsafe--;
        }
        if (diag1.count(a + b) && cols.count(b)) {
            unsafe--;
        }
        if (diag2.count(a - b) && rows.count(a)) {
            unsafe--;
        }
        if (diag2.count(a - b) && cols.count(b)) {
            unsafe--;
        }
    }

    // Add back overlaps between both diagonals
    for (auto p : pieces) {
        int a = p.first, b = p.second;
        if (diag1.count(a + b) && diag2.count(a - b)) {
            unsafe++;
        }
    }

    // The total safe squares are total squares minus unsafe squares plus occupied squares (since they are already counted)
    int safe = total - unsafe + M;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}