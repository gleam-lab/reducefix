#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2; // diag1: i+j, diag2: i-j

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total unsafe squares = rows + columns + diagonals - overlaps
    int unsafe = 0;

    // Rows and columns contributions
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // subtract intersections of rows and columns

    // Diagonals (i+j)
    for (auto d : diag1) {
        int len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N - d + 1;
        }
        unsafe += len;
    }

    // Diagonals (i-j)
    for (auto d : diag2) {
        int len;
        if (d >= 0) {
            len = N - d;
        } else {
            len = N + d;
        }
        unsafe += len;
    }

    // Subtract overlaps between rows/columns and diagonals
    for (auto d : diag1) {
        // Intersection with rows: for each row x in rows, check if y = d - x is in [1, N]
        for (auto x : rows) {
            int y = d - x;
            if (1 <= y && y <= N) {
                unsafe--;
            }
        }
        // Intersection with columns: for each column y in cols, check if x = d - y is in [1, N]
        for (auto y : cols) {
            int x = d - y;
            if (1 <= x && x <= N) {
                unsafe--;
            }
        }
    }

    for (auto d : diag2) {
        // Intersection with rows: for each row x in rows, check if y = x - d is in [1, N]
        for (auto x : rows) {
            int y = x - d;
            if (1 <= y && y <= N) {
                unsafe--;
            }
        }
        // Intersection with columns: for each column y in cols, check if x = d + y is in [1, N]
        for (auto y : cols) {
            int x = d + y;
            if (1 <= x && x <= N) {
                unsafe--;
            }
        }
    }

    // Subtract overlaps between diag1 and diag2 (i.e., squares covered by both diagonals)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve i + j = d1, i - j = d2 => i = (d1 + d2)/2, j = (d1 - d2)/2
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    unsafe++;
                }
            }
        }
    }

    // Total safe squares = total squares - unsafe squares
    int total = N * N;
    int safe = total - unsafe;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}