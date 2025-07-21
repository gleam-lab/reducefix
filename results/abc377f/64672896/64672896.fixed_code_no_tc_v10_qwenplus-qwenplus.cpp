#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;
    vector<array<i64, 2>> pieces(M);

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total number of squares under attack
    i64 attacked = 0;

    // Rows and columns contribute N squares each per line, minus overlaps
    attacked += (i64)rows.size() * N;
    attacked += (i64)cols.size() * N;

    // Diagonals: a + b = k type
    for (auto d : diag1) {
        // Number of points on diagonal x + y = d in [1,N]x[1,N]
        i64 lo = max(1LL, d - N);
        i64 hi = min(N, d - 1);
        attacked += hi - lo + 1;
    }

    // Diagonals: a - b = k type
    for (auto d : diag2) {
        // x - y = d => x = y + d
        // y >= 1 => x >= d + 1
        // y <= N => x <= N + d
        i64 y_min = max(1LL, 1 - d);
        i64 y_max = min(N, N - d);
        if (y_min <= y_max) {
            attacked += y_max - y_min + 1;
        }
    }

    // Subtract overlaps

    // Intersections between row and column
    attacked -= (i64)M; // Each piece is counted once in its row and once in its column

    // Intersections between rows and diag1
    for (auto [a, b] : pieces) {
        i64 sum = a + b;
        for (auto d : diag1) {
            if (d == sum) {
                attacked -= max(0LL, min(N, d - 1) - max(1LL, d - N) + 1);
                break;
            }
        }
    }

    // Intersections between rows and diag2
    for (auto [a, b] : pieces) {
        i64 diff = a - b;
        for (auto d : diag2) {
            if (d == diff) {
                i64 y_min = max(1LL, 1 - d);
                i64 y_max = min(N, N - d);
                if (y_min <= y_max) {
                    attacked -= y_max - y_min + 1;
                }
                break;
            }
        }
    }

    // Intersections between diag1 and diag2: each piece
    attacked -= M;

    // Now add back intersections among three sets
    attacked += M;

    // Subtract intersections among all four sets
    attacked -= M;

    // Total empty squares
    i64 totalEmpty = N * N - M;

    // Total safe squares = total empty - attacked squares
    cout << totalEmpty - attacked << '\n';

    return 0;
}