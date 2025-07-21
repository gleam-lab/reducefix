#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

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

    // Total unsafe squares
    int unsafe = 0;

    // Rows and columns
    unsafe += N * rows.size() + N * cols.size() - rows.size() * cols.size();

    // Diagonals type 1: i + j = d
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int cnt = max_i - min_i + 1;
        unsafe += cnt;
    }

    // Diagonals type 2: i - j = d
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int cnt = max_i - min_i + 1;
        unsafe += cnt;
    }

    // Subtract intersections between rows/columns and diagonals
    for (int d : diag1) {
        // Intersection with rows
        for (int row : rows) {
            int col = d - row;
            if (col >= 1 && col <= N) {
                unsafe--;
            }
        }
        // Intersection with columns
        for (int col : cols) {
            int row = d - col;
            if (row >= 1 && row <= N) {
                unsafe--;
            }
        }
    }

    for (int d : diag2) {
        // Intersection with rows
        for (int row : rows) {
            int col = row - d;
            if (col >= 1 && col <= N) {
                unsafe--;
            }
        }
        // Intersection with columns
        for (int col : cols) {
            int row = col + d;
            if (row >= 1 && row <= N) {
                unsafe--;
            }
        }
    }

    // Add intersections between diagonals type 1 and type 2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    unsafe++;
                }
            }
        }
    }

    // Total safe squares
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