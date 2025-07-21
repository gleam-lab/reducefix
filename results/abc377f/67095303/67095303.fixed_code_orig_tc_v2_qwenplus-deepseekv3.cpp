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

    int unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // subtract intersections counted twice

    // Diagonals (i+j)
    for (auto d : diag1) {
        // The number of (i,j) with i+j = d is min(d-1, N) - max(1, d-N) + 1
        int low = max(1LL, d - N);
        int high = min(N, d - 1);
        if (low > high) continue;
        unsafe += (high - low + 1);
    }

    // Diagonals (i-j)
    for (auto d : diag2) {
        // The number of (i,j) with i-j = d is min(N, N - d) - max(1, 1 - d) + 1
        int low = max(1LL, 1 - d);
        int high = min(N, N - d);
        if (low > high) continue;
        unsafe += (high - low + 1);
    }

    // Subtract intersections between rows/columns and diagonals that were counted twice
    for (auto r : rows) {
        for (auto d1 : diag1) {
            int c = d1 - r;
            if (cols.count(c)) {
                unsafe--;
            }
        }
        for (auto d2 : diag2) {
            int c = r - d2;
            if (cols.count(c)) {
                unsafe--;
            }
        }
    }

    for (auto c : cols) {
        for (auto d1 : diag1) {
            int r = d1 - c;
            if (rows.count(r)) {
                unsafe--;
            }
        }
        for (auto d2 : diag2) {
            int r = c + d2;
            if (rows.count(r)) {
                unsafe--;
            }
        }
    }

    // Add back triple intersections (if any square is in row, column, and both diagonals)
    // These are squares that are exactly the positions of existing pieces
    // Since each existing piece is counted in all four sets, they were subtracted three times too many (once for each pair)
    // So we need to add back M (since each existing piece was subtracted three times, but should only be subtracted once)
    unsafe -= M;

    // The safe squares are total squares minus unsafe squares, but also need to subtract the existing pieces (since they are not empty)
    int total = N * N - M;
    int safe = total - unsafe;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}