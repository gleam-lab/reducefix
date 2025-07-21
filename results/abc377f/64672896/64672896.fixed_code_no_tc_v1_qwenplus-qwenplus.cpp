#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares covered by existing pieces' attack patterns
    i64 attacked = 0;

    // Count how many cells are in attacked rows
    attacked += (i64)rows.size() * N;

    // Count how many cells are in attacked columns
    attacked += (i64)cols.size() * N;

    // Count how many cells are in attacked diagonal 1 (a+b)
    for (auto d : diag1) {
        // For x + y = d, the number of valid (x,y) in [1,N]x[1,N]
        i64 low = max(1LL, d - N);
        i64 high = min(N, d - 1);
        if (low <= high) {
            attacked += high - low + 1;
        }
    }

    // Count how many cells are in attacked diagonal 2 (a-b)
    for (auto d : diag2) {
        // For x - y = d => x = y + d
        // y must be in [1, N], so x = y + d in [1, N]
        i64 low = max(1LL, 1 - d);
        i64 high = min(N, N - d);
        if (low <= high) {
            attacked += high - low + 1;
        }
    }

    // Subtract overlapping cells that were double-counted

    // Rows and columns intersections
    for (auto r : rows) {
        for (auto c : cols) {
            attacked--; // (r,c) was counted twice
        }
    }

    // Rows and diag1 intersections
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (1 <= c && c <= N)
                attacked--;
        }
    }

    // Rows and diag2 intersections
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (1 <= c && c <= N)
                attacked--;
        }
    }

    // Cols and diag1 intersections
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (1 <= r && r <= N)
                attacked--;
        }
    }

    // Cols and diag2 intersections
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = c + d;
            if (1 <= r && r <= N)
                attacked--;
        }
    }

    // Diag1 and diag2 intersections
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve:
            // x + y = d1
            // x - y = d2
            // => x = (d1 + d2)/2
            // => y = (d1 - d2)/2
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                i64 x = (d1 + d2) / 2;
                i64 y = (d1 - d2) / 2;
                if (1 <= x && x <= N && 1 <= y && y <= N)
                    attacked--;
        }
    }

    // Subtract overlaps with all three types
    for (auto r : rows) {
        for (auto c : cols) {
            for (auto d1 : diag1) {
                if (r + c == d1)
                    attacked--; // counted thrice, subtract two times
            }
            for (auto d2 : diag2) {
                if (r - c == d2)
                    attacked--; // counted thrice, subtract two times
            }
        }
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                if (rows.count(x) && cols.count(y))
                    attacked--; // counted thrice, subtract two times
            }
        }
    }

    // Finally, total squares = N*N
    // Minus attacked squares
    // Minus occupied squares (M)
    i64 total = N * N - attacked - M;

    cout << total << "\n";

    return 0;
}