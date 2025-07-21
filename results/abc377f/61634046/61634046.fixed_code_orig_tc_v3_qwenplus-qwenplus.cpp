#include <bits/stdc++.h>

using namespace std;

#define int long long

int N, M;
set<int> rows, cols;
set<int> diag1, diag2;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares attacked by existing pieces
    long long attacked = 0;

    // Rows and columns contribute directly
    attacked += rows.size() * N;
    attacked += cols.size() * N;

    // Diagonals
    attacked += diag1.size() * N;
    attacked += diag2.size() * N;

    // Overlaps between row and column
    for (int r : rows) {
        for (int c : cols) {
            // Each intersection counted twice
            attacked -= 1;
        }
    }

    // Overlaps between row and diagonal1: a + b = s, where a = r => b = s - r
    for (int r : rows) {
        for (int d : diag1) {
            int b = d - r;
            if (1 <= b && b <= N)
                attacked -= 1;
        }
    }

    // Overlaps between row and diagonal2: a - b = d, where a = r => b = r - d
    for (int r : rows) {
        for (int d : diag2) {
            int b = r - d;
            if (1 <= b && b <= N)
                attacked -= 1;
        }
    }

    // Overlaps between column and diagonal1: a + b = s, b = c => a = s - c
    for (int c : cols) {
        for (int d : diag1) {
            int a = d - c;
            if (1 <= a && a <= N)
                attacked -= 1;
        }
    }

    // Overlaps between column and diagonal2: a - b = d, b = c => a = d + c
    for (int c : cols) {
        for (int d : diag2) {
            int a = d + c;
            if (1 <= a && a <= N)
                attacked -= 1;
        }
    }

    // Overlaps between diagonal1 and diagonal2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            // Solve:
            // a + b = d1
            // a - b = d2
            int a = (d1 + d2) / 2;
            int b = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= a && a <= N && 1 <= b && b <= N)
                attacked -= 1;
        }
    }

    // Overlaps among rows, cols, and diagonals
    for (int r : rows) {
        for (int c : cols) {
            if (diag1.count(r + c)) attacked += 1;
            if (diag2.count(r - c)) attacked += 1;
        }
    }

    for (int r : rows) {
        for (int d1 : diag1) {
            int b = d1 - r;
            if (1 <= b && b <= N && diag2.count(r - b))
                attacked += 1;
        }
    }

    for (int c : cols) {
        for (int d2 : diag2) {
            int a = d2 + c;
            if (1 <= a && a <= N && diag1.count(a + c))
                attacked += 1;
        }
    }

    // Quadruple overlaps
    for (int r : rows) {
        for (int c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c))
                attacked -= 1;
        }
    }

    long long total_squares = N * N;
    long long occupied = M;
    long long safe = total_squares - attacked - occupied;

    cout << safe << endl;

    return 0;
}