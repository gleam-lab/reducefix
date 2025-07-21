#include <bits/stdc++.h>
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

    int total_attacked = 0;

    // Rows and columns: each row or column contributes N squares, but intersections are already counted
    total_attacked += rows.size() * N;
    total_attacked += cols.size() * N;
    total_attacked -= rows.size() * cols.size(); // subtract intersections counted twice

    // Diagonals (i+j = d)
    for (int d : diag1) {
        int len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N - d + 1;
        }
        total_attacked += len;
    }

    // Diagonals (i-j = d)
    for (int d : diag2) {
        int len;
        if (d >= 0) {
            len = N - d;
        } else {
            len = N + d;
        }
        total_attacked += len;
    }

    // Subtract intersections between rows and diag1
    for (int d : diag1) {
        for (int r : rows) {
            int c = d - r;
            if (1 <= c && c <= N) {
                total_attacked--;
            }
        }
    }

    // Subtract intersections between columns and diag1
    for (int d : diag1) {
        for (int c : cols) {
            int r = d - c;
            if (1 <= r && r <= N) {
                total_attacked--;
            }
        }
    }

    // Subtract intersections between rows and diag2
    for (int d : diag2) {
        for (int r : rows) {
            int c = r - d;
            if (1 <= c && c <= N) {
                total_attacked--;
            }
        }
    }

    // Subtract intersections between columns and diag2
    for (int d : diag2) {
        for (int c : cols) {
            int r = d + c;
            if (1 <= r && r <= N) {
                total_attacked--;
            }
        }
    }

    // Add back intersections between diag1 and diag2 (i+j=d1, i-j=d2)
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    total_attacked++;
                }
            }
        }
    }

    int total_squares = N * N;
    int safe_squares = total_squares - total_attacked;
    cout << safe_squares << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}