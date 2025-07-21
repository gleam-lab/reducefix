#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> diag, antidiag, row, col;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        diag.insert(a + b);
        antidiag.insert(a - b);
        row.insert(a);
        col.insert(b);
    }

    // Count how many cells are attacked using inclusion-exclusion

    i64 attacked = 0;

    // Add full lines
    attacked += row.size() * N;
    attacked += col.size() * N;
    attacked += diag.size() * N;
    attacked += antidiag.size() * N;

    // Subtract pairwise intersections

    auto overlap = [&](i64 x, i64 y, char type) {
        // Returns number of grid points where two lines intersect
        if (type == 'r') { // row-row: parallel, no intersection
            return 0LL;
        } else if (type == 'c') { // col-col: parallel
            return 0LL;
        } else if (type == 'd') { // diag-diag: parallel
            return 0LL;
        } else if (type == 'a') { // anti-diag-anti-diag: parallel
            return 0LL;
        } else if (type == 'R') { // row-col
            return 1LL;
        } else if (type == 'D') { // row-diag
            // row = x => x + y = d => y = d - x
            // So point is (x, d - x)
            i64 y = y - x;
            if (1 <= y && y <= N) return 1LL;
            else return 0LL;
        } else if (type == 'A') { // row-antidiag
            // x - y = a => y = x - a
            i64 y = x - y;
            if (1 <= y && y <= N) return 1LL;
            else return 0LL;
        } else if (type == 'E') { // col-diag
            // y = y0, x + y = d => x = d - y0
            i64 x = y - x;
            if (1 <= x && x <= N) return 1LL;
            else return 0LL;
        } else if (type == 'F') { // col-antidiag
            // y = y0, x - y = a => x = a + y0
            i64 x = x + y;
            if (1 <= x && x <= N) return 1LL;
            else return 0LL;
        } else if (type == 'G') { // diag-antidiag
            // Solve x + y = d, x - y = a
            // => 2x = d + a => x = (d + a)/2
            // => 2y = d - a => y = (d - a)/2
            if ((x + y) % 2 != 0) return 0LL;
            i64 x0 = (x + y) / 2;
            i64 y0 = (x - y) / 2;
            if (1 <= x0 && x0 <= N && 1 <= y0 && y0 <= N) return 1LL;
            else return 0LL;
        }
        return 0LL;
    };

    // Subtract row-col intersections
    for (auto r : row) {
        for (auto c : col) {
            attacked -= 1; // Each row and column intersect at one cell
        }
    }

    // Subtract row-diag intersections
    for (auto r : row) {
        for (auto d : diag) {
            i64 y = d - r;
            if (1 <= y && y <= N) {
                attacked -= 1;
            }
        }
    }

    // Subtract row-antidiag intersections
    for (auto r : row) {
        for (auto a : antidiag) {
            i64 y = r - a;
            if (1 <= y && y <= N) {
                attacked -= 1;
            }
        }
    }

    // Subtract col-diag intersections
    for (auto c : col) {
        for (auto d : diag) {
            i64 x = d - c;
            if (1 <= x && x <= N) {
                attacked -= 1;
            }
        }
    }

    // Subtract col-antidiag intersections
    for (auto c : col) {
        for (auto a : antidiag) {
            i64 x = a + c;
            if (1 <= x && x <= N) {
                attacked -= 1;
            }
        }
    }

    // Subtract diag-antidiag intersections
    for (auto d : diag) {
        for (auto a : antidiag) {
            i64 x = (d + a) / 2;
            i64 y = (d - a) / 2;
            if ((d + a) % 2 == 0 && (d - a) % 2 == 0 &&
                1 <= x && x <= N && 1 <= y && y <= N) {
                attacked -= 1;
            }
        }
    }

    // Add back triple overlaps (row-col-diag etc.) — they were subtracted too much

    // Add back quadruple overlaps

    // Total safe squares = total squares - attacked squares
    cout << N * N - attacked << "\n";

    return 0;
}