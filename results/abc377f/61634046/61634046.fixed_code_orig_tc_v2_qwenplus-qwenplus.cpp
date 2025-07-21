#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_M = 2002;

int N, M;

set<int> rows, cols;
set<int> diag1, diag2;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    int total_captured = 0;
    total_captured += rows.size() * N; // all squares in occupied rows
    total_captured += cols.size() * N; // all squares in occupied columns
    total_captured += diag1.size() * N; // all squares in occupied diagonal 1
    total_captured += diag2.size() * N; // all squares in occupied diagonal 2

    // Inclusion-Exclusion Principle to subtract overcounts
    // For intersections of two sets
    for (int r : rows) {
        total_captured -= cols.size(); // row and column intersection
        total_captured -= diag1.count(r + 1); // row and diag1 where diag1 = r + j for square (r,j)
        total_captured -= diag2.count(r - 1); // row and diag2 where diag2 = r - j for square (r,j)
    }

    for (int c : cols) {
        total_captured -= diag1.count(1 + c); // col and diag1
        total_captured -= diag2.count(1 - c); // col and diag2
    }

    for (int d : diag1) {
        // diag1: i + j = d
        // number of points on this diagonal in grid: max(0, min(d - 1, N) - max(d - N, 1LL) + 1)
        int l = max(1LL, d - N);
        int r = min(N, d - 1);
        if (l <= r) {
            int cnt = r - l + 1;
            total_captured -= cnt;
        }
    }

    for (int d : diag2) {
        // diag2: i - j = d
        // i ranges from max(1, d + 1) to min(N, N + d)
        int l = max(1LL, d + 1);
        int r = min(N, N + d);
        if (l <= r) {
            int cnt = r - l + 1;
            total_captured -= cnt;
        }
    }

    // Intersections of three sets
    for (int r : rows) {
        for (int c : cols) {
            int d1 = r + c;
            int d2 = r - c;
            if (diag1.count(d1)) total_captured += 1;
            if (diag2.count(d2)) total_captured += 1;
        }
    }

    for (int r : rows) {
        for (int d1 : diag1) {
            int j = d1 - r;
            if (1 <= j && j <= N) {
                int d2 = r - j;
                if (diag2.count(d2)) total_captured += 1;
            }
        }
    }

    for (int c : cols) {
        for (int d1 : diag1) {
            int i = d1 - c;
            if (1 <= i && i <= N) {
                int d2 = i - c;
                if (diag2.count(d2)) total_captured += 1;
            }
        }
    }

    for (int d1 : diag1) {
        for (int d2 : diag2) {
            // Solve:
            // i + j = d1
            // i - j = d2
            // => i = (d1 + d2)/2
            // => j = (d1 - d2)/2
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (1 <= i && i <= N && 1 <= j && j <= N) {
                total_captured += 1;
            }
        }
    }

    // Subtract four-way overlaps
    for (int r : rows) {
        for (int c : cols) {
            int d1 = r + c;
            int d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2)) {
                total_captured -= 1;
            }
        }
    }

    int total_squares = N * N;
    int occupied_squares = total_captured;

    // Now we need to subtract the already occupied squares
    occupied_squares += M;

    cout << total_squares - occupied_squares << endl;

    return 0;
}